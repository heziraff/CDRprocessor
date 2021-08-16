#include "OperatorBillingDomain.h"
#include <cassert>
#include "ClientBillingDomain.h"
using namespace experis;

OperatorBillingDomain::OperatorBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut)
	:m_voiceIn(a_voiceIn), m_voiceOut(a_voiceOut), m_smsIn(a_smsIn), m_smsOut(a_smsOut) {
	m_id = a_id;
}

void OperatorBillingDomain::operator+=(const BillingDomain& a_other) {
	a_other.AddTo(*this);
}

void OperatorBillingDomain::AddTo(ClientBillingDomain& a_sum) const {
	a_sum.m_voiceIn += VoiceIn();
	a_sum.m_voiceOut += VoiceOut();
	a_sum.m_smsIn += SmsIn();
	a_sum.m_smsOut += SmsOut();
}

void OperatorBillingDomain::AddTo(OperatorBillingDomain& a_clientBillingDomain) const {
	assert(false);
}


long long OperatorBillingDomain::Id() const {
	return m_id;
}

size_t OperatorBillingDomain::VoiceOut() const {
	return m_voiceOut;
}

size_t OperatorBillingDomain::VoiceIn() const {
	return m_voiceIn;
}

size_t OperatorBillingDomain::SmsOut() const {
	return m_smsOut;
}

size_t OperatorBillingDomain::SmsIn() const {
	return m_smsIn;
}