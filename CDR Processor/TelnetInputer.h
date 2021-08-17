#pragma once

#include "NetworkHandler.h"
#include "SocketAndCommand.h"
#include "CyclicQueue.h"
#include "inputer.h"


namespace experis {
//class NetworkHandler;
//class SocketAndCommand;
//class CircularQueue;
using RequestQueue = CyclicQueue<SocketAndCommand>;
class TelnetInputer : public Inputer {
	
public:
	explicit TelnetInputer(NetworkHandler &a_network, RequestQueue &a_requestQueue);
	TelnetInputer(const TelnetInputer& a_other) = default;
	~TelnetInputer() = default;
	TelnetInputer& operator=(const TelnetInputer& a_other) = default;
	virtual void operator()() override;

private:
	NetworkHandler &m_network;
	RequestQueue & m_requestQueue;
};

} // experis