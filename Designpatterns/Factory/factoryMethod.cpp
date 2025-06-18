#include <bits/stdc++.h>
using namespace std;
// abstract class
class Payment
{
public:
  virtual void makePayment() {};
};
// concerete classes
class CryptoPayment : public Payment
{
public:
  void makePayment()
  {
    cout << "making payment via crypto\n";
  }
};

class CreditCardPayment : public Payment
{
public:
  void makePayment()
  {
    cout << "making payment via creditcard\n";
  }
};

class PaypalPayment : public Payment
{
public:
  void makePayment()
  {
    cout << "making payment via paypal\n";
  }
};

// abstract factory which ha payment
class PaymentFactory
{
public:
  virtual Payment *getPaymentType()=0;
};
// concerete factories
class CryptoPaymentFactory : public PaymentFactory
{
public:
  Payment *getPaymentType()
  {
    return new CryptoPayment();
  }
};

class CreditCardPaymentFactory : public PaymentFactory
{
public:
  Payment *getPaymentType()
  {
    return new CreditCardPayment();
  }
};

class PaypalPaymentFactory : public PaymentFactory
{
public:
  Payment *getPaymentType ()
  {
    return new PaypalPayment();
  }
};




int main()
{
 
  PaymentFactory*pf = new PaypalPaymentFactory();
  Payment * p = pf->getPaymentType();
  p->makePayment();

}