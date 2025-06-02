
#include<bits/stdc++.h>
using namespace std;

class BankAccount {
  public:
    virtual void deposit(double amount){};
    virtual void withdraw(double amount){};

};

class Saving:public BankAccount{
    public:
     void deposit(double amount){
        cout<<"added amount "<<amount<<" to your saving account \n";
     }
     void withdraw(double amount){
           cout<<"removed amount "<<amount<<" from saving account \n";
     }
};

class Current:public BankAccount{
  public:
      void deposit(double amount){
        cout<<"added amount "<<amount<<" to your current account \n";
     }
     void withdraw(double amount){
           cout<<"removed amount "<<amount<<" from currnt account \n";
     }
};

class FixedDeposit:public BankAccount{
  public:
    void deposit(double amount){
        cout<<"added amount "<<amount<<" to your  FD \n";
     }
     void withdraw(double amount){
          throw runtime_error("Withdrawal from Fixed Deposit is not allowed!");
     }
};


int main(){
  BankAccount *b = new FixedDeposit();
  b->deposit(5000.0);
  b->withdraw(2000.0);   //violation of lsp 
}