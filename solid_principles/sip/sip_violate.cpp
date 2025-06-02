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

     double totalPrice(){
        double total = 0;
       for(auto p : products){
          total+=p->price;
       }
       return total;
     }

     vector<Product*> getProducts(){
        return products;
     }

     void payment(){
      cout<<"payment of total "<<this->totalPrice()<<" is generated";
     }
  
    void generateInvoice (){
       for(auto p:products){
         cout<<p->name<<" : "<<p->price<<" \n";
       }
       cout<<"Total "<<this->totalPrice();
    }

     void saveToDatabase(){
      cout<<"saved to database";
     }
};


int main(){
   Product *p1 = new Product("creatine", 1,999.0);
   Product *p2 = new Product("whey protein", 2,5000);
   Cart *c = new Cart();
   c->addProduct(p1);
   c->addProduct(p2);
  c->payment();
  c->generateInvoice();
  c->saveToDatabase();
  return 0 ;
}