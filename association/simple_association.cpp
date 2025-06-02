
#include<bits/stdc++.h>
using namespace std;



class Student{
  private:
   string name;
   int roll_no;
  public:
    Student(string name,int roll_no){
       this->name = name;
       this-> roll_no = roll_no;
    }
   
    string getName(){
      return this->name;
    }
    void listen(){
      cout<<this->name<<" is listening ";
    }
};

class Teacher{
    

     public:
      void teaching(Student *s){
        cout<<"teacher is teaching to "<< s->getName()<<endl;
        s->listen();

      }
};

int main(){
  Student s ("harshal",72);
  Teacher t;
  t.teaching(&s);
}
