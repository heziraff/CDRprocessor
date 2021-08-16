#pragma once

namespace experis {
// Interface
class Inputer {
public:
	Inputer() = default;
	virtual ~Inputer() = default;
	virtual void operator()() = 0;
};

} //experis