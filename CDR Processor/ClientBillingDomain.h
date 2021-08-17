#pragma once
#include <string>

namespace experis {
class ClientBillingDomain {

public:
	explicit ClientBillingDomain() = default;
	explicit ClientBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut, double a_dataIn, double a_dataOut);

	virtual void operator+=( const ClientBillingDomain& a_other);
	std::string toString() const;
	long long Id() const;
	size_t VoiceOut() const;
	size_t VoiceIn() const;
	size_t SmsOut() const;
	size_t SmsIn() const;
	double DataOut() const;
	double DataIn() const;

//private:
	long long m_id;
	size_t m_voiceOut;
	size_t m_voiceIn;
	size_t m_smsOut;
	size_t m_smsIn;
	double m_dataOut;
	double m_dataIn;
};

}// experis

