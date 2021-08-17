#include "DataBase.h"
#include "ClientBillingDomain.h"
#include "OperatorBillingDomain.h"

namespace experis {

DataBase::DataBase() 
:m_logger(SingletonLogger::GetLogger()) {
}
void experis::DataBase::Add(const ClientBillingDomain& a_cbd) {
	m_clientsBD[a_cbd.Id()] += a_cbd;
	m_operatorsBD[a_cbd.Id() / 10000000000] += a_cbd;
	m_logger->Info(a_cbd.toString());
}
OperatorBillingDomain& DataBase::OperatorBD(const long long& a_key) {
	return m_operatorsBD[a_key];
}
ClientBillingDomain& DataBase::ClientBD(const long long& a_key) {
	return m_clientsBD[a_key];
}
}