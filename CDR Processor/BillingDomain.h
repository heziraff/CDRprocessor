#pragma once

namespace experis {
class ClientBillingDomain;
class OperatorBillingDomain;

class BillingDomain {
public:
	virtual void operator+=(const BillingDomain& a) = 0;
	virtual void AddTo(ClientBillingDomain& a_sum) const = 0;
	virtual void AddTo(OperatorBillingDomain& a_sum) const = 0;
	long long m_id;
};

}//experis