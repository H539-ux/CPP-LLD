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
class Payment{
    public:
      void payment(Cart *c){
      cout<<"payment of total "<<PriceCalculator::totalPrice(c)<<" is generated";
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
      void saveToDatabase(Cart *c){
      cout<<"saved to database";
     }
};

int main(){
   Product *p1 = new Product("creatine", 1,999.0);
   Product *p2 = new Product("whey protein", 2,5000);
   Cart *c = new Cart();
   c->addProduct(p1);
   c->addProduct(p2);
   Payment *py = new Payment();
   py->payment(c);
  
  

  return 0 ;

}