#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    string name;
    int id;
    double price;



   Product(string name,int id, double price){
     this->name = name;
     this->id =id;
     this->price = price;
   }
   
    double getPrice(){
      return this->price;
    }
   ~Product(){

   }

};

class Cart{
   private:
    vector<Product*>products;
   public:
     void addProduct(Product* p){
      products.push_back(p);
     }

     vector<Product*> getProducts(){
        return products;
     }
};


class PriceCalculator{
     public:
      static double totalPrice(Cart *c){
        double total = 0;
       for(auto p : c->getProducts()){
          total+=p->getPrice();
       }
       return total;
     }
};

class PaymentProcessor {
       public:
        virtual void paymentprocessing(Cart *c){};
};

class Paypal : public PaymentProcessor{
       void paymentprocessing(Cart*c){
        cout<<"payment of total "<<PriceCalculator::totalPrice(c)<<" is generated via paypal";      
       }
};

class Crypto : public PaymentProcessor{
       void paymentprocessing(Cart*c){
        cout<<"payment of total "<<PriceCalculator::totalPrice(c)<<" is generated via crypto";      
       }
};


class InvoiceGenerator{
   public:
   static string generateInvoice(Cart *cart) { // Static!
        stringstream invoice;
        for (auto p : cart->getProducts()) {
            invoice << p->name << " : " << p->getPrice() << "\n";
        }
        invoice << "Total: " << PriceCalculator::totalPrice(cart);
        return invoice.str();
    }
};

class DatabaseServer{
  public:
   virtual void savingToDb(Cart *c){};
};

class MongoDb : public DatabaseServer{
  public:
   void savingToDb(Cart *c){
       cout<<"saving to MongoDb\n";
   }
};

class MySql : public DatabaseServer{
  public:
   void savingToDb(Cart *c){
    cout<<"saving to MySql\n";
   }
};

int main(){
   Product *p1 = new Product("creatine", 1,999.0);
   Product *p2 = new Product("whey protein", 2,5000);
   Cart *c = new Cart();
   c->addProduct(p1);
   c->addProduct(p2);
  PaymentProcessor *py = new Crypto();
  py->paymentprocessing(c);
 
  DatabaseServer *ds = new MongoDb();
  ds->savingToDb(c);
  

  return 0 ;

}