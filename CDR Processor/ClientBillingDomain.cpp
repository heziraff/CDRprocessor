#include "ClientBillingDomain.h"
#include <cassert>

namespace experis {
ClientBillingDomain::ClientBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut, double a_dataIn, double a_dataOut)
	:m_voiceIn(a_voiceIn), m_voiceOut(a_voiceOut), m_smsIn(a_smsIn), m_smsOut(a_smsOut), m_dataIn(a_dataIn), m_dataOut(a_dataOut) {
	m_id = a_id;
}

void ClientBillingDomain::operator+=(const  BillingDomain& a_other) {
	a_other.AddTo(*this);
}

void ClientBillingDomain::AddTo(ClientBillingDomain& a_sum) const {

	a_sum.m_voiceIn += VoiceIn();
	a_sum.m_voiceOut += VoiceOut();
	a_sum.m_smsIn += SmsIn();
	a_sum.m_smsOut += SmsOut();
	a_sum.m_dataIn += DataIn();
	a_sum.m_dataOut += DataOut();
}

void ClientBillingDomain::AddTo(OperatorBillingDomain& a_clientBillingDomain) const {
	assert(false);
}

long long ClientBillingDomain::Id() const {
	return m_id;
}

size_t ClientBillingDomain::VoiceOut() const {
	return m_voiceOut;
}

size_t ClientBillingDomain::VoiceIn() const {
	return m_voiceIn;
}

size_t ClientBillingDomain::SmsOut() const {
	return m_smsOut;
}

size_t ClientBillingDomain::SmsIn() const {
	return m_smsIn;
}

double ClientBillingDomain::DataIn() const {
	return m_dataIn;
}

double ClientBillingDomain::DataOut() const {
	return m_dataOut;
}
}