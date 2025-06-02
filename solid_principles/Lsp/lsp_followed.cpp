
#include<bits/stdc++.h>
using namespace std;




class DepositableAccount {
  public:
    virtual void deposit(double amount){};
   
};

class WithdrawAble:public DepositableAccount{
   virtual void withdraw(double amount){};
};


class Saving:public WithdrawAble{
    public:
     void deposit(double amount){
        cout<<"added amount "<<amount<<" to your saving account \n";
     }
     void withdraw(double amount){
           cout<<"removed amount "<<amount<<" from saving account \n";
     }
};

class Current:public WithdrawAble{
  public:
      void deposit(double amount){
        cout<<"added amount "<<amount<<" to your current account \n";
     }
     void withdraw(double amount){
           cout<<"removed amount "<<amount<<" from currnt account \n";
     }
};

class FixedDeposit:public DepositableAccount{
  public:
    void deposit(double amount){
        cout<<"added amount "<<amount<<" to your  FD \n";
     }
     void withdraw(double amount){
          throw runtime_error("Withdrawal from Fixed Deposit is not allowed!");
     }
};


int main(){
 DepositableAccount *d = new FixedDeposit();
  d->deposit(5000.0);
}