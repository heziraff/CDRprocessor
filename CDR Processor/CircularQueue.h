#pragma once
#include <atomic>
#include <mutex>
#include <iostream>
#include <vector>
#include <condition_variable>
#include "SocketAndCommand.h"
#include "Loger/SingletonLogger.h"

namespace experis {
using valueType = SocketAndCommand;
using containerr = std::vector<valueType>;
class CircularQueue {
public:
	CircularQueue(size_t a_fixedSize, std::mutex& a_mutex);

	void Push(const valueType& a_val);
	void Get(valueType& a_data);
	bool Work() const;
	void Work(bool a_work);
	size_t Size() const;

private:
	containerr m_container;
	std::mutex& m_mutex;
	bool m_work;
	std::atomic<int> m_front;
	std::atomic<int> m_rear;
	std::condition_variable m_conditionVariable;
	size_t m_size;
	Logger* m_logger;
	};
}//experis