#include "AddSmsIn.h"
#include <sstream>
#include "DataBase.h"
#include "ClientBillingDomain.h"

experis::AddSmsIn::AddSmsIn(DataBase& a_DB)
:m_DB(a_DB){
}

void experis::AddSmsIn::Add(std::vector<std::string> a_cdr) {
	std::stringstream sstream(a_cdr[1]);
	long long id;
	sstream >> id;

	sstream << a_cdr[7];
	size_t smsIn;
	sstream >> smsIn;

	ClientBillingDomain clientBD{ id, 0, 0, smsIn, 0, 0, 0 };
	m_DB.Add(clientBD);
}
