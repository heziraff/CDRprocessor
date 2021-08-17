#pragma once
#include "SocketAndCommand.h"
#include "CyclicQueue.h"
#include <vector>

namespace experis {


class Processor  {

public:
	//explicit Processor(RequestQueue& a_requestQueue);
	Processor(const Processor& a_other) = default;
	~Processor() = default;
	Processor& operator=(const Processor& a_other) = default;
	
private:
	
	//RequestQueue& m_requestQueue;
	

};

} // experis