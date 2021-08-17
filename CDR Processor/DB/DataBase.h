#pragma once
#include <map>
#include <string>


namespace experis {
class ClientBillingDomain;
class OperatorBillingDomain;

class DataBase {
	using operatorsBD = std::map< long long, OperatorBillingDomain>;
	using clientsBD = std::map< long long, ClientBillingDomain>;
public:	
	void Add(const ClientBillingDomain& a_cbd);
	OperatorBillingDomain& OperatorBD(const long long& a_key);
	ClientBillingDomain& ClientBD(const long long& a_key);

private:
	operatorsBD m_operatorsBD;
	clientsBD m_clientsBD;
};

}//experis