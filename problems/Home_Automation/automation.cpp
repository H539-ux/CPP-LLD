
#include<bits/stdc++.h>
using namespace std;


class Device{
   public:
    virtual void ToggleOn()=0;
    virtual void ToggleOff()=0;
    virtual ~Device() {};
};

class Logger{
  public:
    void log(const string& msg){
      cout<<"[LOG] "<<msg<<endl;
    }
};

class Fan : public Device{
 private:
 Logger *l;
 public:
  Fan(Logger *l){
    this->l = l;
  }
  void ToggleOn() override {
    this->l->log("Fan turned on");
  }

  void ToggleOff()override {
      this->l->log("Fan turned off");
  }
};

class Tv: public Device{
  private:
 Logger *l;
 public:
  Tv(Logger *l){
    this->l = l;
  }
  void ToggleOn() override {
    this->l->log("TV turned on");
  }

  void ToggleOff() override {
     this->l->log("TV turned off");
  }
};

class Ac: public Device{
 private:
 Logger *l;
 public:
  Ac(Logger *l){
    this->l = l;
  }
  void ToggleOn() override {
    this->l->log("AC turned on");
  }

  void ToggleOff() override {
     this->l->log("AC turned off");
  }
};


class DeviceController{
  private:
   Device *d;
  public:
   DeviceController(Device *d){
    this->d = d;
   }
   void setDevice(Device *d){
      this->d=d;
   }
   void processTurnOn(){
     this->d->ToggleOn();
   }
   void processTurnOff(){
    this->d->ToggleOff();
   }

};


int main(){
  Logger l;
  Tv tv(&l);
  Ac ac(&l);
  Fan fan(&l);
  DeviceController dc(&tv);
  dc.processTurnOn();
  dc.setDevice(&fan);
  dc.processTurnOn()

}