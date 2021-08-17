#include "OperatorBillingDomain.h"
#include <cassert>
#include "ClientBillingDomain.h"
namespace experis {

OperatorBillingDomain::OperatorBillingDomain(long long a_id, size_t a_voiceIn, size_t a_voiceOut, size_t a_smsIn, size_t a_smsOut)
	:m_id(a_id), m_voiceIn(a_voiceIn), m_voiceOut(a_voiceOut), m_smsIn(a_smsIn), m_smsOut(a_smsOut) {
}

void OperatorBillingDomain::operator+=(const ClientBillingDomain& a_other) {
	m_id = a_other.Id();
	m_voiceIn += a_other.VoiceIn();
	m_voiceOut += a_other.VoiceOut();
	m_smsIn += a_other.SmsIn();
	m_smsOut += a_other.SmsOut();
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
}