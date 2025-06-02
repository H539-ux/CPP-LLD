#include <bits/stdc++.h>
using namespace std;

class Engine
{

public:
  Engine()
  {
    cout << "engine created\n";
  }

  void start()
  {
    cout << "engine started" << endl;
  }

  ~Engine()
  {
    cout << "engine destroyed\n";
  }
};

/*


✅ When Car is created:

Engine’s constructor is called first (member objects initialized before the owner).

✅ When Car is destroyed:

Engine’s destructor is called automatically.

✅ Engine’s lifetime is tied to Car – that’s composition!



*/
class Car
{
private:
  Engine e; // in composition for this eample car ows engine e so engine's lifetime is tied to cars lifetime
public:
  Car()
  {
    cout << "car created\n";
  }

  void run()
  {
    e.start();
    cout << "car started\n";
  }

  ~Car()
  {
    cout << "car destroyed\n";
  }
};

int main()
{
  Car c;
  c.run();
  return 0;
}