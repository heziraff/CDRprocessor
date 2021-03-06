#pragma once
#include "NetworkHandler.h"
#include "SocketAndCommand.h"
#include "CyclicQueue.h"

namespace experis {
//class NetworkHandler;
//class SocketAndCommand;
//class CircularQueue;
using RequestQueue = CyclicQueue<SocketAndCommand>;
class OutputClient {

public:
	explicit OutputClient(NetworkHandler& a_networ, RequestQueue& a_requestQueue);
	OutputClient(const OutputClient& a_other) = default;
	~OutputClient() = default;
	OutputClient& operator=(const OutputClient& a_other) = default;
	void Output();

private:
	NetworkHandler& m_network;
	RequestQueue& m_requestQueue;
};

} // experis
