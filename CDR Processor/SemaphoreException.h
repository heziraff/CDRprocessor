#pragma once
#include <exception>

namespace experis {

	class SemaphoreException : public std::exception {
	public:
		SemaphoreException(char const* a_detail)
			:m_detail(a_detail) {
		}

		virtual char const* what() const override {
			return m_detail;
		}
	private:
		char const* m_detail;
	};
}