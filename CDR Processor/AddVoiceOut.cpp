#include "AddVoiceOut.h"
#include <sstream>
#include "DataBase.h"
#include "ClientBillingDomain.h"

experis::AddVoiceOut::AddVoiceOut(DataBase& a_DB)
	:m_DB(a_DB) {
}

void experis::AddVoiceOut::Add(std::vector<std::string> &a_cdr) {
	std::stringstream sstream(a_cdr[1]);
	long long id;
	sstream >> id;

	sstream << a_cdr[7];
	size_t voiceOut;
	sstream >> voiceOut;

	ClientBillingDomain clientBD{ id, 0, voiceOut, 0, 0, 0, 0 };
	m_DB.Add(clientBD);
}