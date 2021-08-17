#include "ReadCDR.h"
#include "DataBase.h"
#include "Reader.h"
#include "ClientBillingDomain.h"
#include <sstream>
#include "Action.h"

namespace experis {


ReadCDR::ReadCDR(DataBase& a_dataBase, CyclicQueue< std::string>& a_cdrPaths, std::map<std::string, std::shared_ptr<Action>>& a_actions)
:m_dataBase(a_dataBase), m_cdrPaths(a_cdrPaths), m_actions(a_actions){
}

void ReadCDR::operator()() {
	while(true) {
		std::string path;
		m_cdrPaths.Dequeue(path);
		Reader reader{ path };
		std::string cdrPath;
		std::string line;
		line = reader.Line();
		while(line != "") {
			std::vector<std::string> cdrVec = m_tokenizer.Tokens(line, "|");
			assert(cdrVec.size() == 11);
			std::shared_ptr<Action> act = m_actions[cdrVec[3]];
			act->Add(cdrVec);
			line = reader.Line();
		}
	}
}


} //experis