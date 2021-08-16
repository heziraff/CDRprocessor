#include "TelnetInputer.h"


using namespace experis;

TelnetInputer::TelnetInputer(NetworkHandler& a_network, RequestQueue& a_requestQueue)
	:m_network(a_network), m_requestQueue(a_requestQueue)  {
}

void TelnetInputer::operator()() {
	std::string request;
	size_t socket;
	m_network.GetInput(&socket, &request);
	m_requestQueue.Push({ socket , request });
}