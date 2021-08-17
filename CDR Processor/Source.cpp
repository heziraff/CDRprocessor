#include "NetworkHandler.h"
#include <iostream>
#include <set>
#include <string>
#include "CyclicQueue.h"
#include "SocketAndCommand.h"
#include <thread>
#include "TelnetInputer.h"
#include "OutputClient.h"
#include "SingletonLogger.h"

#include "OperatorBillingDomain.h"
#include "ClientBillingDomain.h"
#include "DataBase.h"
#include "ReadCDR.h"
#include "AddData.h"
#include "AddNothing.h"
#include "AddSmsIn.h"
#include "AddSmsOut.h"
#include "AddVoiceIn.h"
#include "AddVoiceOut.h"

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



int main() {
	DataBase dataBase;
	CyclicQueue<std::string> cdrPaths{100};
	std::map<std::string, Action> actions;
	actions["MOC"] = AddVoiceOut{ dataBase };
	actions["MTC"] = AddVoiceIn{ dataBase };
	actions["SMS-MO"] = AddSmsOut{ dataBase };
	actions["SMS-MT"] = AddSmsIn{ dataBase };
	actions["D"] = AddData{ dataBase };
	actions["U"] = AddNothing{};
	actions["B"] = AddNothing{};
	actions["X"] = AddNothing{};
	ReadCDR readCDR{ dataBase , cdrPaths , actions };
	
	int t = 0;
	std::set<size_t> activeSockets;
	NetworkHandler net{ 5100, NewConnection{activeSockets} ,ConnectionTerminate{activeSockets} };
	std::mutex mutex;
	CyclicQueue<SocketAndCommand> requestQueue{ 100 };
	TelnetInputer telnetInputer{ net, requestQueue };
	OutputClient outputClient(net, requestQueue);

	//std::thread inputer(readCDR, &telnetInputer);
	//std::thread outpuer(PutOutput1, outputClient);
	
	//inputer.join();
	//outpuer.join();
	
}