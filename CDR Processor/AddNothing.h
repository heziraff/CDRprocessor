#pragma once
#include "Action.h"


namespace experis {

class AddNothing : public Action {
public:
	/*CTOR*/
	explicit AddNothing() = default;
	~AddNothing() = default;
	AddNothing(const AddNothing& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string> a_cdr) override {};
};

}