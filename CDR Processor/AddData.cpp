#include "AddData.h"
#include <sstream>
#include "DataBase.h"
#include "ClientBillingDomain.h"

experis::AddData::AddData(DataBase& a_DB)
	:m_DB(a_DB) {
}

void experis::AddData::Add(std::vector<std::string> &a_cdr) {
	std::stringstream sstream(a_cdr[1]);
	long long id;
	sstream >> id;

	sstream << a_cdr[7];
	double dataIn;
	sstream >> dataIn;

	sstream << a_cdr[8];
	double dataOut;
	sstream >> dataOut;

	ClientBillingDomain clientBD{ id, 0, 0, 0, 0, dataIn, dataOut };
	m_DB.Add(clientBD);
}