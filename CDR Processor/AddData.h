#pragma once
#include "Action.h"

namespace experis {
class DataBase;

class AddData : public Action {
public:
	/*CTOR*/
	explicit AddData(DataBase& a_DB);
	~AddData() = default;
	AddData(const AddData& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string> a_cdr) override;

private:
	DataBase& m_DB;
};

}

