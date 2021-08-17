#include "AddVoiceIn.h"
#include <sstream>
#include "DataBase.h"
#include "ClientBillingDomain.h"

experis::AddVoiceIn::AddVoiceIn(DataBase& a_DB)
	:m_DB(a_DB) {
}

void experis::AddVoiceIn::Add(std::vector<std::string> a_cdr) {
	std::stringstream sstream(a_cdr[1]);
	long long id;
	sstream >> id;

	sstream << a_cdr[7];
	size_t voiceIn;
	sstream >> voiceIn;

	ClientBillingDomain clientBD{ id, voiceIn, 0, 0, 0, 0, 0 };
	m_DB.Add(clientBD);
}