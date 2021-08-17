#include "Tokenizer.h"
#include <string>

using namespace experis;
std::vector<std::string> Tokenizer::Tokens(const std::string &a_line,  const std::string& a_delimiter) const {
	std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = a_line.find(a_delimiter);
    while(end != std::string::npos) {
        tokens.push_back(a_line.substr(start, end - start));
        start = end + a_delimiter.length();
        end = a_line.find(a_delimiter, start);
    }
    tokens.push_back(a_line.substr(start, end));
    return tokens;
}