#include "CircularQueue.h"

experis::CircularQueue::CircularQueue(
	size_t a_fixedSize,
	std::mutex& a_mutex):
    m_container({ a_fixedSize }),
	m_mutex(a_mutex),
	m_work(true),
	m_front(0), 
	m_rear(0),
    m_size(10)
    ,m_logger(SingletonLogger::GetLogger()) 
{
}

void experis::CircularQueue::Push(const valueType& a_val) {
    {
        //std::unique_lock<std::mutex> uniqueLock(m_mutex);
       // while(m_size < m_container.size()) {
            //m_conditionVariable.wait(uniqueLock);
       // }
        m_container[m_rear] = a_val;
        m_logger->Info("Push " + a_val.Str() +" to the queue");
        ++m_rear;
        m_rear = m_rear % m_container.size();
        ++m_size;
    }
    //m_conditionVariable.notify_one();
}

void experis::CircularQueue::Get(valueType &a_data) {
    {
        //std::unique_lock<std::mutex> uniqueLock(m_mutex);
        //while(m_size == 0) {
           // m_conditionVariable.wait(uniqueLock);
      //  }
        a_data = m_container[m_front];
        m_logger->Info("Get " + a_data.Str() + " from the queue");
        ++m_front;
        m_front = m_front % m_container.size();
        --m_size;
    }
   // m_conditionVariable.notify_one();
}

bool experis::CircularQueue::Work() const {
    return m_work;
}

void experis::CircularQueue::Work(bool a_work) {
    m_work = a_work;
}

size_t experis::CircularQueue::Size() const {
    return m_container.size();
}
