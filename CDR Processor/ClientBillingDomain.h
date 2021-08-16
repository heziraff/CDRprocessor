#pragma once
#include "BillingDomain.h"

namespace experis {
class ClientBillingDomain : public BillingDomain {

public:
	explicit ClientBillingDomain() = default;
	explicit ClientBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut, double a_dataIn, double a_dataOut);

	virtual void operator+=( const BillingDomain& a) override;
	virtual void AddTo(ClientBillingDomain& a_clientBillingDomain) const override;
	virtual void AddTo(OperatorBillingDomain& a_clientBillingDomain) const override;
	long long Id() const;
	size_t VoiceOut() const;
	size_t VoiceIn() const;
	size_t SmsOut() const;
	size_t SmsIn() const;
	double DataOut() const;
	double DataIn() const;

//private:
	size_t m_voiceOut;
	size_t m_voiceIn;
	size_t m_smsOut;
	size_t m_smsIn;
	double m_dataOut;
	double m_dataIn;
};

}// experis

