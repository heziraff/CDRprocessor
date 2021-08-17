#include "NetworkHandler.h"
#include <iostream>
#include <set>
#include <string>
#include "CyclicQueue.h"
#include "SocketAndCommand.h"
#include <thread>
#include "TelnetInputer.h"
#include "OutputClient.h"
#include "Loger/SingletonLogger.h"

using namespace experis;
struct NewConnection {
	NewConnection(std::set<size_t>& a_activeSockets) : m_activeSockets(a_activeSockets) {}
	void operator()(size_t a_socketId) {
		std::cout << "NewConnection: " << a_socketId << std::endl;
		m_activeSockets.insert(a_socketId);
	}
	std::set<size_t>& m_activeSockets;
};

struct ConnectionTerminate {
	ConnectionTerminate(std::set<size_t>& a_activeSockets) : m_activeSockets(a_activeSockets) {}
	void operator()(size_t a_socketId) {
		std::cout << "ConnectionTerminate: " << a_socketId << std::endl;
		m_activeSockets.erase(a_socketId);
	}
	std::set<size_t>& m_activeSockets;
};

void GetInput1(TelnetInputer *a_telnetInputer) {
	while(true) {
		(*a_telnetInputer)();
	}
}

#include "OperatorBillingDomain.h"
#include "ClientBillingDomain.h"
#include "DataBase.h"
int main() {
	
	
	int t = 0;
	/*
	SingletonLogger loger();
	std::set<size_t> activeSockets;
	NetworkHandler net{ 5100, NewConnection{activeSockets} ,ConnectionTerminate{activeSockets} };
	std::mutex mutex;
	RequestQueue requestQueue(100, mutex);

	TelnetInputer telnetInputer{ net, requestQueue };
	OutputClient outputClient(net, requestQueue);

	std::thread inputer(GetInput1, &telnetInputer);
	//std::thread outpuer(PutOutput1, outputClient);
	
	inputer.join();
	//outpuer.join();
	*/
}