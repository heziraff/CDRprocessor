#ifndef __NetworkHandler__
#define __NetworkHandler__

#ifdef WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <windows.h>
typedef FD_SET FD_SET_TYPE;
#else
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#define SOCKET int
#define DWORD int
#define ULONG unsigned long
typedef fd_set FD_SET_TYPE;
#endif
#include <memory>
#include <vector>
#include <string>
#include <mutex>

class NetworkHandler
{
public:
	struct ShutdownException : std::exception {
		virtual const char *what() const override { return "network was shut down"; }
	};

public:
	template <class F1, class F2>
	NetworkHandler(unsigned short _usersPort, F1 _newUserFunc, F2 _closedUserFunc)
		: m_usersPort(_usersPort)
		, m_remoteServerPort(0)
		, m_numListeners(1)
		, m_totalSockets(0)
		, m_nextReadSocketToTraverse(0), m_totalSocketsReady(0)
	{
		m_newConnectionFunc[USERS_LISTENER].reset(new Callback<F1>(_newUserFunc));
		m_closedConnectionFunc[USERS_LISTENER].reset(new Callback<F2>(_closedUserFunc));

		Init();
		FD_ZERO(&m_lastReadSet);
	}

	template <class F1, class F2, class F3, class F4>
	NetworkHandler(unsigned short _usersPort, F1 _newUserFunc, F2 _closedUserFunc, unsigned short _remoteServerPort, F3 _newRemoteServerFunc, F4 _closedRemoteServerFunc)
		: m_usersPort(_usersPort)
		, m_remoteServerPort(_remoteServerPort), m_totalSockets(0)
		, m_numListeners(2)
		, m_nextReadSocketToTraverse(0), m_totalSocketsReady(0)
	{
		m_newConnectionFunc[USERS_LISTENER].reset(new Callback<F1>(_newUserFunc));
		m_closedConnectionFunc[USERS_LISTENER].reset(new Callback<F2>(_closedUserFunc));
		m_newConnectionFunc[REMOTE_SERVER_LISTENER].reset(new Callback<F3>(_newRemoteServerFunc));
		m_closedConnectionFunc[REMOTE_SERVER_LISTENER].reset(new Callback<F4>(_closedRemoteServerFunc));

		Init();
		FD_ZERO(&m_lastReadSet);
	}

	void GetInput(size_t *_socketid, std::string *_input); // throws ShutdownException
	void PutOutput(size_t _socketid, const std::string &_output);
	void Shutdown();

private:
	static const size_t READ_DATA_BUFSIZE = 1024;
	static const size_t WRITE_DATA_BUFSIZE = 8192 * 3;

	struct CallbackBase
	{
		virtual ~CallbackBase() { }
		virtual void Call(size_t _id) = 0;
	};

	template <class F>
	struct Callback : public CallbackBase
	{
		Callback(F _f) : m_f(_f) { }

		virtual void Call(size_t _id)
		{
			m_f(_id);
		}

		F m_f;
	};

	struct SOCKET_INFORMATION {
		SOCKET_INFORMATION(SOCKET _s, CallbackBase *_connectionClosedCallback) : writeLen(0), Socket(_s), BytesRECV(0), m_connectionClosedCallback(_connectionClosedCallback) { }
		char readBuffer[READ_DATA_BUFSIZE];
		char writeBuffer[WRITE_DATA_BUFSIZE];
		int writeLen;
		SOCKET Socket;
		DWORD BytesRECV;
		CallbackBase *m_connectionClosedCallback;
	};

	enum { USERS_LISTENER, REMOTE_SERVER_LISTENER, NUM_LISTENERS };

	static void InitWsa();
	static void InitListener(SOCKET *_socket, unsigned short _port);

private:
	NetworkHandler(const NetworkHandler &);
	NetworkHandler& operator=(const NetworkHandler &);

	void Init();
	bool Recv(size_t *_socketid, std::string *_input);
	size_t CreateSocketInformation(SOCKET s, size_t _listenerIdx);
	void FreeSocketInformation(DWORD Index);
 
	std::mutex m_mutex;
	std::mutex m_singleReaderMutex;
	unsigned short m_usersPort;
	unsigned short m_remoteServerPort;
	size_t m_numListeners;
	DWORD m_totalSockets;

	// from here they are initialized by Init()
	std::unique_ptr<CallbackBase> m_newConnectionFunc[NUM_LISTENERS];
	std::unique_ptr<CallbackBase> m_closedConnectionFunc[NUM_LISTENERS];
	SOCKET m_listenSocket[NUM_LISTENERS];
	SOCKET_INFORMATION *m_socketArray[FD_SETSIZE];
	FD_SET_TYPE m_lastReadSet;
	int m_nextReadSocketToTraverse;
	size_t m_totalSocketsReady;
	std::vector<size_t> m_virtualSocketIdToRealSocketId;
};

#endif
