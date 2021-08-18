#pragma once
#include <string>
#include "tokenizer.h"
#include "CyclicQueue.h"
#include "DataBase.h"
#include "SocketAndCommand.h"

namespace experis {
class Action;
class ReadCDR {
public:
	explicit ReadCDR(DataBase& a_dataBase, CyclicQueue< std::string>& a_cdrPaths, std::map<std::string, std::shared_ptr<Action>>&a_actions);
	ReadCDR(const ReadCDR& a_other) = delete;
	~ReadCDR() = default;
	void operator()();
	
private:
	Tokenizer m_tokenizer;
	DataBase& m_dataBase;
	CyclicQueue< std::string>& m_cdrPaths;
	std::map<std::string, std::shared_ptr<Action>>& m_actions;
};

}//experis

