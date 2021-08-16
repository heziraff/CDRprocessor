#include "DataBase.h"
#include "ClientBillingDomain.h"

using namespace experis;

void experis::DataBase::Add(const BillingDomain& a_bd) {

	*m_billingDomains["msisdn"][a_bd.m_id] += a_bd;

	//*m_billingDomains["operator"][a_bd.m_id / 10000000000] += a_bd;
}

BillingDomain& DataBase::Get(const std::string& a_type, const long long& a_key) {
	return *m_billingDomains[a_type][a_key];
}