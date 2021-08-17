#pragma once

#include <fstream>
#include <string>

namespace experis {

class Reader {
public:
	Reader() = delete;
	explicit Reader(const std::string& a_fileName);
	Reader(const Reader &a_other) = delete;
	std::string Line() ;
	~Reader() = default;

private:
	 std::ifstream m_file;
};

} //experis

