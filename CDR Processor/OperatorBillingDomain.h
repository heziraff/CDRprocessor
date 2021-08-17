#pragma once
#include "ClientBillingDomain.h"

namespace experis {
class OperatorBillingDomain {

public:
	explicit OperatorBillingDomain() = default;
	explicit OperatorBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut);
	void operator+=(const ClientBillingDomain& a_other);
	std::string toString() const;
	long long Id() const;
	size_t VoiceOut() const;
	size_t VoiceIn() const;
	size_t SmsOut() const;
	size_t SmsIn() const;

private:
	long long m_id;
	size_t m_voiceOut;
	size_t m_voiceIn;
	size_t m_smsOut;
	size_t m_smsIn;
};

}// experis