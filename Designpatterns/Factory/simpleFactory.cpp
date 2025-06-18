#include<bits/stdc++.h>
using namespace std;

class Burger{
 public:
   virtual void prepare(){};
};

class NormalBurger : public Burger{
    public:
     void prepare(){
      cout<<"preparing normal burger";
    }
};

class ClassicBurger : public Burger{
   public:
     void prepare(){
      cout<<"preparing classic burger";
    }

};

class PremiumBurger : public Burger{
   public:
     void prepare(){
      cout<<"preparing premium burger";
    }
};

class BurgerFactory {
   public:
     Burger* createBurger(string type){
        if(type == "classic"){
          return new ClassicBurger();
        }else if(type == "normal"){
          return new NormalBurger();
        }else if(type == "premium"){
          return new PremiumBurger();
        }
        cout<<"plz provide valid type\n";
        return nullptr;
     }
};
int main(){

  BurgerFactory *bf = new BurgerFactory();
  Burger *b = bf->createBurger("premium");
  b->prepare();

}