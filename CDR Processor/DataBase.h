#pragma once
#include <map>
#include <string>


namespace experis {
class ClientBillingDomain;
class OperatorBillingDomain;

class DataBase {
	using operatorsBD = std::map< unsigned int, OperatorBillingDomain>;
	using clientsBD = std::map< long long, ClientBillingDomain>;
public:	
	void Add(const ClientBillingDomain& a_cbd);
	OperatorBillingDomain& OperatorBD(const unsigned int& a_key);
	ClientBillingDomain& ClientBD(const long long& a_key);

private:
	operatorsBD m_operatorsBD;
	clientsBD m_clientsBD;
};

}//experis