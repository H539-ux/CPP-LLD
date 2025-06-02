#include <bits/stdc++.h>
using namespace std;

class Database {
public:
   virtual void addData (string data){
        cout<<"data added in database";
    }
};

class Mysql : public Database{
    public:
     void addData (string data){
        cout<<"data added in Mysql";
    }
};

class MongoDb : public Database{
   public:
     void addData (string data){
        cout<<"data added in Mongodb";
    }
};




int main() {
    Database *d = new Mysql();
    // Mysql *m = new Mysql();
    // MongoDb *md = new MongoDb();
    d->addData("mydata");
    // m->addData("mydata");
    // md->addData("mydata");
    return 0;
}