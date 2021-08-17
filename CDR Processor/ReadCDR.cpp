#include "ReadCDR.h"
#include "DataBase.h"
#include "Reader.h"
#include "DB/ClientBillingDomain.h"
#include <sstream>
#include "Action.h"

namespace experis {


ReadCDR::ReadCDR(DataBase& a_dataBase, CyclicQueue< std::string>& a_cdrPaths, std::map<std::string, Action>& a_actions)
:m_dataBase(a_dataBase), m_cdrPaths(a_cdrPaths), m_actions(a_actions){
}

void ReadCDR::operator()() {
	while(true) {
		std::string path;
		m_cdrPaths.Dequeue(path);
		Reader reader{ path };
		std::string cdrPath;
		std::string line;
		do {
		line = reader.Line();
		std::vector<std::string> cdrVec = m_tokenizer.Tokens(line, "|");
		m_actions[cdrVec[2]].Add(cdrVec);
		}
		while(line != "");

	}
}


} //experis