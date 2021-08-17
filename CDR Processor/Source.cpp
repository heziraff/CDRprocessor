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

void ReadCdrFiles(ReadCDR *a_telnetInputer) {
	(*a_telnetInputer)();
}

void LoadActions(std::map<std::string, std::shared_ptr<Action>>& a_actions, DataBase &dataBase) {
	std::shared_ptr<Action> addVoiceOut = std::make_shared<AddVoiceOut>(dataBase);
	a_actions["MOC"] = addVoiceOut;

	std::shared_ptr<Action> addVoiceIn = std::make_shared<AddVoiceIn>(dataBase);
	a_actions["MTC"] = addVoiceIn;

	std::shared_ptr<Action> addSmsOut = std::make_shared<AddSmsOut>(dataBase);
	a_actions["SMS-MO"] = addSmsOut;

	std::shared_ptr<Action> addSmsIn = std::make_shared<AddSmsIn>(dataBase);
	a_actions["SMS-MT"] = addSmsIn;

	std::shared_ptr<Action> addData = std::make_shared<AddData>(dataBase);
	a_actions["D"] = addData;

	std::shared_ptr<Action> addNothing = std::make_shared<AddNothing>(dataBase);
	a_actions["U"] = addNothing;
	a_actions["B"] = addNothing;
	a_actions["X"] = addNothing;
}
	

int main() {
	DataBase dataBase;
	CyclicQueue<std::string> cdrPaths{100};
	static std::map<std::string, std::shared_ptr<Action>> actions;
	LoadActions(actions, dataBase);


	ReadCDR readCDR{ dataBase , cdrPaths , actions };
	cdrPaths.Enqueue("InCDR/CDR2.txt");
	cdrPaths.Enqueue("InCDR/CDR2.txt");
	int t = 0;
	std::set<size_t> activeSockets;
	NetworkHandler net{ 5100, NewConnection{activeSockets} ,ConnectionTerminate{activeSockets} };
	std::mutex mutex;
	CyclicQueue<SocketAndCommand> requestQueue{ 100 };
	TelnetInputer telnetInputer{ net, requestQueue };
	OutputClient outputClient(net, requestQueue);

	std::thread readCdrFiles(ReadCdrFiles, &readCDR);
	//std::thread outpuer(PutOutput1, outputClient);
	
	readCdrFiles.join();
	//outpuer.join();
	
}