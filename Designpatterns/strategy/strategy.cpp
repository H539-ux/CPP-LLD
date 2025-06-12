#include <bits/stdc++.h>
using namespace std;

//abstract strategy
class Walkable{
   public:
    virtual void walk(){};
};

class Talkable{
 public:
   virtual void talk(){};
};

class Flyable{
 public:
  virtual void fly(){};
};

//concrete strategy
class NormalWalk : public Walkable{
    public:
      void walk()override{
         cout<<"normal walking\n";
      }
};

class NotNormalWalk : public Walkable{
    public:
      void walk() override{
        cout<<"different type of walk\n";
      }
};

class NormalTalk : public Talkable{
  public:
      void talk()override{
         cout<<"normal talking\n";
      }
};

class NotNormalTalk: public Talkable{
       public:
      void talk() override{
        cout<<"different type of talk\n";
      }
};

class NormalFly : public Flyable{
public:
      void fly()override{
         cout<<"normal flyinging\n";
      }
};

class NotNormalFly : public Flyable{
     public:
      void fly() override{
        cout<<"different type of fly\n";
      }
};


class Robot {
  public:
  Flyable *f;
  Walkable *w;
  Talkable *t;
   Robot(Talkable*t, Walkable *w,Flyable *f){
    this->f=f;
    this->w=w;
    this->t=t;
   }

   void processWalk(){
    this->w->walk();
   }

   void processTalk(){
    this->t->talk();
   }

   void processFly(){
    this->f->fly();
   }
  virtual void projection(){};
};




int main(){
  Robot *rb1=new Robot(new NormalTalk(),new NormalWalk(),new NotNormalFly()); // we can pass any combination 
  Robot * rb2 = new Robot(new NotNormalTalk(), new NormalWalk(),new NormalFly());

  cout<<"************* for robot1****************\n";
  rb1->processFly();
  rb1->processTalk();
  rb1->processWalk();
  cout<<"************* for robot2****************\n";
  rb2->processFly();
  rb2->processTalk();
  rb2->processWalk();

}