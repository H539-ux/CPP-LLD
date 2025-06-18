#include<bits/stdc++.h>
using namespace std;

class Button {
  public:
   virtual void button()=0;
    virtual ~Button() = default; 
};

class CheckBox {
  public:
    virtual void checkbox()=0;
    virtual ~CheckBox() = default;
};


class WindowButton : public Button{
  public:
    void button()override{
      cout<<"windows button\n";
    }
};

class MacButton : public Button{
     public:
    void button()override{
      cout<<"macs button\n";
    }
};


class WindowCheckBox: public CheckBox{
   public:
    void checkbox()override{
      cout<<"windows checkbox\n";
    }
};

class MacCheckBox : public CheckBox{
      public:
    void checkbox()override{
      cout<<"macs checkbox\n";
    }
};


class UIComponentsFactory{
  public:
    virtual Button* getButton()=0;
    virtual CheckBox* getCheckBox()=0;
    virtual ~UIComponentsFactory()= default;
};



class WindowsComponentsFactory: public UIComponentsFactory{
        public:
         Button* getButton(){
            return new WindowButton();
         }

         CheckBox* getCheckBox(){
          return new WindowCheckBox();
         }
};

class MacsComponentsFactory: public UIComponentsFactory{
       public:
         Button* getButton(){
            return new MacButton();
         }

         CheckBox* getCheckBox(){
          return new MacCheckBox();
         }
};


 void buildUI(UIComponentsFactory *UI){
       Button *b = UI->getButton();
       CheckBox*c = UI->getCheckBox();
       b->button();
       c->checkbox();
       delete b;
       delete c;
 }


int main(){
    UIComponentsFactory * UI = new WindowsComponentsFactory() ;
    buildUI(UI);
    delete UI;

}