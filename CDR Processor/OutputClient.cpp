#include "OutputClient.h"


using namespace experis;
/**/
experis::OutputClient::OutputClient(NetworkHandler& a_network, RequestQueue& a_requestQueue)
	:m_network(a_network), m_requestQueue(a_requestQueue) {
}

void experis::OutputClient::Output() {
	SocketAndCommand socketAndCommand;
	m_requestQueue.Dequeue(socketAndCommand);
	m_network.PutOutput(socketAndCommand.Socket(), socketAndCommand.Command());
}