#include <bits/stdc++.h>
using namespace std;

class DatabaseServer
{
public:
  virtual void save() {};
};

class MongoDb : public DatabaseServer
{
public:
  void save()
  {
    cout << "saving to mongo\n";
  }
};

class Mysql : public DatabaseServer
{
public:
  void save()
  {
    cout << "saving to mysql\n";
  }
};


class UserService {
  private:
   DatabaseServer *ds; // dependency injection 

   public:
    UserService(DatabaseServer * ds){
      this->ds = ds;
    }
    void saveData(){
      this->ds->save(); 
    }

};
int main()
{
  MongoDb * mb = new MongoDb();
  UserService *us = new UserService(mb);
  us->saveData();
}