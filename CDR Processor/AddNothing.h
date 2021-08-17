#pragma once
#include "Action.h"


namespace experis {
class DataBase;
class AddNothing : public Action {
public:
	/*CTOR*/
	explicit AddNothing(DataBase& a_DB){}
	~AddNothing() = default;
	AddNothing(const AddNothing& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string> &a_cdr) override {};
};

}