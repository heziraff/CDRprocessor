#pragma once
#include <map>
#include <string>
#include "BillingDomain.h"

namespace experis {
class DataBase {

	using container = std::map<std::string, std::map< long long, BillingDomain*>>;
public:
	void Add(const BillingDomain& a_bd);
	BillingDomain& Get(const std::string& a_type, const long long& a_key);

private:
	container m_billingDomains;
};

}//experis