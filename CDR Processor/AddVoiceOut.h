#pragma once
#include "Action.h"


namespace experis {
class DataBase;

class AddVoiceOut : public Action {
public:
	/*CTOR*/
	explicit AddVoiceOut(DataBase& a_DB);
	~AddVoiceOut() = default;
	AddVoiceOut(const AddVoiceOut& a_other) = delete;

	/*Methods*/
	virtual void Add(std::vector<std::string>& a_cdr) override;

private:
	DataBase& m_DB;
};

}