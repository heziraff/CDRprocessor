#include "Reader.h"
#include <iostream>

using namespace experis;

Reader::Reader(const std::string& a_fileName) 
: m_file(std::ifstream(a_fileName)){
}

std::string Reader::Line() {
    std::string str;
    std::getline(m_file, str);
    return str;
}
