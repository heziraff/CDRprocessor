#pragma once
#include <map>
#include <string>
#include "SingletonLogger.h"

namespace experis {
class ClientBillingDomain;
class OperatorBillingDomain;

class DataBase {
	using operatorsBD = std::map< long long, OperatorBillingDomain>;
	using clientsBD = std::map< long long, ClientBillingDomain>;
public:	
	explicit DataBase();
	~DataBase() = default;
	DataBase(const DataBase& a_other) = delete;
	DataBase& operator=(const DataBase& a_other) = delete;

	void Add(const ClientBillingDomain& a_cbd);
	OperatorBillingDomain& OperatorBD(const long long& a_key);
	ClientBillingDomain& ClientBD(const long long& a_key);

private:
	operatorsBD m_operatorsBD;
	clientsBD m_clientsBD;
	Logger* m_logger;
};

}//experis