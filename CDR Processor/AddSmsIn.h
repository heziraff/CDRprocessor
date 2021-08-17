#pragma once
#include "Action.h"

namespace experis {
class DataBase;

class AddSmsIn : public Action {
public:
	/*CTOR*/
	explicit AddSmsIn(DataBase& a_DB);
	~AddSmsIn() = default;
	AddSmsIn(const AddSmsIn& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string> a_cdr) override;

private:
	DataBase& m_DB;
};

}

