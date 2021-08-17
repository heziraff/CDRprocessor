#pragma once
#include <string>
namespace experis {

class SocketAndCommand {
	using SocketType = size_t;
public:
	explicit SocketAndCommand() = default;
	SocketAndCommand(SocketAndCommand::SocketType a_socket, const std::string& a_command);
	~SocketAndCommand() = default;
	SocketAndCommand(const SocketAndCommand&) = default;

	SocketAndCommand& operator=(const SocketAndCommand&) = default;
	std::string Command();
	SocketType Socket();
	std::string toString() const;

private:
	std::string m_command;
	SocketType  m_socketId;
};

} //expris