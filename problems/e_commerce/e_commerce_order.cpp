
#include<bits/stdc++.h>
#include "Logger.h"
using namespace std;

class Product{
  public:
   string name;
   double price;

   Product(string name, double price){
    this->name = name;
    this->price = price;
   }
};

class Order{
  private:
   vector<Product*> products;
   Logger *l;
  public:
    Order(Logger*l){
      this->l=l;
    }
    vector<Product*> getProducts(){
      return this->products;
    }

    void addProduct(Product*p){
      this->l->log("product NAME: "+ p->name+" PRICE: "+ to_string(p->price)+" added to list");
      products.push_back(p);
    }
};

class ProcessTotal {
   public:
    static double getTotal(vector<Product*> products){
      double total = 0;
      for(auto p:products){
        total+=p->price;
      }
      return  total;
    }
};



class Payment{
    public:
     virtual void pay(){}
};

class Crypto : public Payment{
   private:
    Logger *l;
  public:
  Crypto(Logger*l){
    this->l=l;
  }
   void pay(){
       this->l->log("payment done through crypto");
   }
};

class Upi:public Payment{
   private:
    Logger *l;
  public:
   Upi(Logger *l){
    this->l=l;
   }
   void pay(){
    this->l->log("payment done through Upi");
   }
};



class Database{
    public:
     virtual void save(){}
};

class MongoDb:public Database{
     private:
    Logger *l;
    public:
     MongoDb(Logger *l){
           this->l=l;
     }
    void save(){
      this->l->log("saved to MongoDb");
    }
};

class MySql:public Database{
   private:
    Logger *l;
   public:
    MySql(Logger *l){
      this->l=l;
    }
    void save(){
      this->l->log("saved to MySql");
    }
};

class Notifier{
   public:
   virtual void notify(){}
};

class EmailNotifier : public Notifier{
   private:
    Logger *l;
      public:
       EmailNotifier(Logger*l){
        this->l=l;
       }
       void notify(){
        this->l->log("notification send via email");
       }
};

class WhatsAppNotifier : public Notifier{
    private:
    Logger * l;
    public:
      WhatsAppNotifier(Logger*l){
        this->l=l;
      }
      void notify(){
        this->l->log("notification send via whatsapp");
       }
};


class DatabaseService{
   private:
    Database *db; //
   public:
     DatabaseService(Database*db){
      this->db = db;
     }

     void processSave(){
      this->db->save();
     }
};

class PaymentService{
private :
 Payment *p;//
 public:
  PaymentService(Payment*p){
    this->p = p;
  }
  void processPayment(){
    this->p->pay();
  }
};

class NotificationService{
  private:
   Notifier *n;
  public:
   NotificationService(Notifier *n){
    this->n = n;
   }
   void processNotification(){
    this->n->notify();
   }
};

class OrderProcessor{
     private:
      DatabaseService*ds;
      PaymentService*ps;
      NotificationService*ns;
      Logger *l;
     public:
      OrderProcessor(DatabaseService*ds,PaymentService*ps,NotificationService*ns,Logger *l){
         this->ds = ds;
         this->ps = ps;
         this->ns = ns;
         this->l=l;
      }

    
        void process(Order& order) {
        // 1. Calculate total
        double total = ProcessTotal::getTotal(order.getProducts());
        this->l->log("Processing order with total: "+ to_string(total));
        
        // 2. Process payment
        ps->processPayment();
        
        // 3. Save to database
        ds->processSave();
        
        // 4. Send notification
        ns->processNotification();
        
        this->l->log( "Order processing completed successfully!") ;
    }
      
   


};


void Logger::log(const std::string &msg) {
    cout << "[LOG] " << msg << endl;
}

int main(){
   Product *p1 = new Product("laptop",500000.0);
   Product *p2 = new Product("mobile",24000);
   Logger l;
   Order o(&l);
   o.addProduct(p1);
   o.addProduct(p2);
   Database *mongo = new MongoDb(&l);
   DatabaseService *ds = new DatabaseService(mongo);
   Payment *upi = new Upi(&l);
   PaymentService *ps = new PaymentService(upi);
   Notifier * email = new EmailNotifier(&l);
   NotificationService *ns = new NotificationService(email);
   OrderProcessor processor(ds, ps, ns,&l);
   processor.process(o);

    delete p1;
    delete p2;
    delete mongo;
    delete ds;
    delete upi;
    delete ps;
    delete email;
    delete ns;

  
}