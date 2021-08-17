#include "ClientBillingDomain.h"
#include <cassert>

namespace experis {
ClientBillingDomain::ClientBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut, double a_dataIn, double a_dataOut)
	:m_id(a_id), m_voiceIn(a_voiceIn), m_voiceOut(a_voiceOut), m_smsIn(a_smsIn), m_smsOut(a_smsOut), m_dataIn(a_dataIn), m_dataOut(a_dataOut) {
}

void ClientBillingDomain::operator+=(const ClientBillingDomain& a_other) {
	m_id = a_other.Id();
	m_voiceIn += a_other.VoiceIn();
	m_voiceOut += a_other.VoiceOut();
	m_smsIn += a_other.SmsIn();
	m_smsOut += a_other.SmsOut();
	m_dataIn += a_other.DataIn();
	m_dataOut += a_other.DataOut();
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