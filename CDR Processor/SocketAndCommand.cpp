#include "SocketAndCommand.h"

using namespace experis;

SocketAndCommand::SocketAndCommand(SocketAndCommand::SocketType a_socket, const std::string& a_command)
: m_command {a_command }
, m_socketId {a_socket} {
}
std::string SocketAndCommand::Command() {
	return this->m_command;
}

SocketAndCommand::SocketType SocketAndCommand::Socket() {
	return this->m_socketId;
}

std::string SocketAndCommand::Str() const {
	return m_command + ", " + std::to_string(m_socketId);
}
