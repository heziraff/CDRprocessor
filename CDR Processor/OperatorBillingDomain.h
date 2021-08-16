#pragma once
#include "BillingDomain.h"

namespace experis {
class OperatorBillingDomain :public BillingDomain {

public:
	explicit OperatorBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut);
	virtual void AddTo(ClientBillingDomain& a_clientBillingDomain) const override;
	virtual void AddTo(OperatorBillingDomain& a_clientBillingDomain) const override;
	virtual void operator+=(const BillingDomain& a) override;
	long long Id() const;
	size_t VoiceOut() const;
	size_t VoiceIn() const;
	size_t SmsOut() const;
	size_t SmsIn() const;

private:
	size_t m_voiceOut;
	size_t m_voiceIn;
	size_t m_smsOut;
	size_t m_smsIn;
};

}// experis