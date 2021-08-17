#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace experis {

class Tokenizer {
public:
	Tokenizer() = default;
	Tokenizer(const Tokenizer& a_other) = delete;
	~Tokenizer() = default;
	std::vector<std::string> Tokens(const std::string &a_line, const std::string& a_delimiter) const;
};

} //experis