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

class Payment{
    public:
      void payment(Cart *c,string paymentService){

        if(paymentService == "paypal"){
             cout<<"payment of total "<<PriceCalculator::totalPrice(c)<<" is generated via paypal";          //violates ocp
        }else if(paymentService == "crypto"){
           cout<<"payment of total "<<PriceCalculator::totalPrice(c)<<" is generated via crypto ";
        }
      
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



class Database {
   public:
      void saveToDatabase(Cart *c,string dbtype){
         if(dbtype=="mongodb"){
           cout<<"saving to mongodb";
         }else if(dbtype == "mysql"){           // violate ocp 
           cout<<"saving to mysql";
         }
     }
};

int main(){
   Product *p1 = new Product("creatine", 1,999.0);
   Product *p2 = new Product("whey protein", 2,5000);
   Cart *c = new Cart();
   c->addProduct(p1);
   c->addProduct(p2);
   Payment *py = new Payment();
   py->payment(c,"paypal");

   Database *db = new Database();

   db->saveToDatabase(c,"mysql");
  

  return 0 ;

}