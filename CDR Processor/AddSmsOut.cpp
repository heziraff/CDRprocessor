#include "AddSmsOut.h"
#include <sstream>
#include "DataBase.h"
#include "ClientBillingDomain.h"

experis::AddSmsOut::AddSmsOut(DataBase& a_DB)
	:m_DB(a_DB) {
}

void experis::AddSmsOut::Add(std::vector<std::string> &a_cdr) {
	std::stringstream sstream(a_cdr[1]);
	long long id;
	sstream >> id;

	sstream << a_cdr[7];
	size_t smsOut;
	sstream >> smsOut;
	;

	ClientBillingDomain clientBD{ id, 0, 0, 0, smsOut, 0, 0 };
	m_DB.Add(clientBD);
}