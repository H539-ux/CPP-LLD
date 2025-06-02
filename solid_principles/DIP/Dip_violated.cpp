#include<bits/stdc++.h>
using namespace std;
class MongoDb{
   public:
    void save(){
      cout<<"saving to mongodb\n";
    }
};

class MySql{
 public:
  void save(){
    cout<<"saving to mysql\n";
  }
};


class UserService{
 private:
  MongoDb mo;
  MySql ms;
  public:
  void saveToMongo(){
    mo.save();
  }

  void saveToMysql(){
     ms.save();
  }
};

int main(){
   UserService us;
   us.saveToMongo();
}