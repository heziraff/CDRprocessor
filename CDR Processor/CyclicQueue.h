#pragma once
#include <cassert>
#include <vector>
#include <mutex>
#include <semaphore>
#include <exception>
#include "SingletonLogger.h"
#include <iostream>

namespace experis {

template<typename ValueT>
class CyclicQueue {
public:
	explicit CyclicQueue(size_t a_containerSize);
	~CyclicQueue() = default;
	CyclicQueue(const CyclicQueue& a_other) = delete;

	CyclicQueue& operator=(const CyclicQueue& a_other) = delete;
	void Enqueue(const ValueT& a_value);
	void Dequeue(ValueT& a_value);
	void Stop();

private:
	struct ProgramStopped : public std::exception {};

	std::vector<ValueT> m_container;
	size_t m_maxSize;
	size_t m_nextEmpty;
	size_t m_first;
	size_t m_currentSize;
	std::mutex m_mutex;
	std::condition_variable m_enqueueCond;
	std::condition_variable m_dequeueCond;
	bool m_stopped;
	Logger* m_logger;
};

template<typename ValueT>
CyclicQueue<ValueT>::CyclicQueue(size_t a_containerSize)
	: m_container(a_containerSize)
	, m_maxSize(a_containerSize)
	, m_nextEmpty(0)
	, m_first(0)
	, m_currentSize(0)
	//, m_producerSem(a_containerSize, a_containerSize)
	//, m_consumerSem(0, a_containerSize)
	, m_mutex()
	, m_enqueueCond()
	, m_dequeueCond()
	, m_stopped(false)
	, m_logger(SingletonLogger::GetLogger()) {
}

template<typename ValueT>
void CyclicQueue<ValueT>::Enqueue(const ValueT& a_value) {
	{ // unique lock
		std::unique_lock<std::mutex> uniqueLock(this->m_mutex);
		while((this->m_currentSize == this->m_maxSize) && !this->m_stopped) {
			this->m_enqueueCond.wait(uniqueLock);
		}
		if(this->m_stopped) {
			throw ProgramStopped{};
		}
		assert(this->m_currentSize <= this->m_maxSize);
		this->m_container[this->m_nextEmpty] = a_value;
		//std::string str = a_value.toString();
		m_logger->Info("Push ... to the queue");
		this->m_nextEmpty = (this->m_nextEmpty + 1) % this->m_maxSize;
		++this->m_currentSize;
	}
	this->m_dequeueCond.notify_one();
}

template<typename ValueT>
void CyclicQueue<ValueT>::Dequeue(ValueT& a_dequeueTo) {
	{ // unique lock
		std::unique_lock<std::mutex> uniqueLock(this->m_mutex);
		while((this->m_currentSize == 0) && !this->m_stopped) {
			this->m_dequeueCond.wait(uniqueLock);
		}
		if(this->m_stopped) {
			throw ProgramStopped{};
		}
		assert(!this->m_container.empty());
		a_dequeueTo = this->m_container[this->m_first];
		this->m_first = (this->m_first + 1) % this->m_maxSize;
		--this->m_currentSize;
	}
	this->m_enqueueCond.notify_one();
}

template<typename ValueT>
void CyclicQueue<ValueT>::Stop() {
	std::unique_lock<std::mutex> uniqueLock(this->m_mutex);
	this->m_stopped = true;
	this->m_dequeueCond.notify_all();
	this->m_enqueueCond.notify_all();
}

} //experis
