#pragma once
#include "SocketAndCommand.h"
#include "CircularQueue.h"

namespace experis {
using RequestQueue = CircularQueue;
class Processor  {

public:
	explicit Processor(RequestQueue& a_requestQueue);
	Processor(const Processor& a_other) = default;
	~Processor() = default;
	Processor& operator=(const Processor& a_other) = default;

private:
	RequestQueue& m_requestQueue;
};

} // experis