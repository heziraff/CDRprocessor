#pragma once
#include "Action.h"


namespace experis {
class DataBase;

class AddSmsOut : public Action {
public:
	/*CTOR*/
	explicit AddSmsOut(DataBase& a_DB);
	~AddSmsOut() = default;
	AddSmsOut(const AddSmsOut& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string> a_cdr) override;

private:
	DataBase& m_DB;
};

}