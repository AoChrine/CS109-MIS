#include "common.h"

using namespace std;

template <class T>
class DataTypes {
    T a;
  public:
    DataTypes(T value)
      {a=value;}
    T get();
    void update(T b){a = b;};
    
};

template <class T>
T DataTypes<T>::get()
{
  return a;
}



int main () {
  DataTypes <int> myobject (100);
  DataTypes <double> myobject1 (101.13);
  cout << myobject.get() << endl;
  cout << myobject1.get() << endl;
  myobject.update(1012);
  cout << myobject.get() << endl;
  return 0;
}

