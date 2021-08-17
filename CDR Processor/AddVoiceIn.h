#pragma once
#include "Action.h"

namespace experis {
class DataBase;

class AddVoiceIn : public Action {
public:
	/*CTOR*/
	explicit AddVoiceIn(DataBase& a_DB);
	~AddVoiceIn() = default;
	AddVoiceIn(const AddVoiceIn& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string> a_cdr) override;

private:
	DataBase& m_DB;
};

}
