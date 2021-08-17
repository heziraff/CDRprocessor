#pragma once
#include <vector>
#include <string>
namespace experis {
class ClientBillingDomain;

class Action {
public:
	explicit Action() = default;
	~Action() = default;
	virtual void Add(std::vector<std::string> a_cdr) {};
};

}//experis

