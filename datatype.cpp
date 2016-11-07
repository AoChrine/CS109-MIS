#include "common.h"
using namespace std;

// template <class T>
// class DataTypes {
//     T a;
//   public:
//     DataTypes(T value)
//       {a=value;}
//     T get();
//     void update(T b){a = b;};
    
// };

// template <class T>
// T DataTypes<T>::get()
// {
//   return a;
// }

// string name, string value, string size(if string)


class DataType{
	protected:
	public:
		DataType(){};
		// virtual string getName() = 0;
		// virtual int64_t getValue() = 0;
		// virtual string getValue() = 0;
		//virtual string getName() = 0;
		// virtual void update() = 0;
		// virtual DataType* clone(stringstream& ss) = 0;
		~DataType(){};
};

class NUMERIC: public DataType
{
private:
	string name;
	int64_t value;
public:
	NUMERIC(string name, string x):value(atoi(x.c_str())),name(name),DataType(){}
	string getName() const {return name;}
	int64_t getValue() const {return value;}
	void update(int64_t updatedVal) {value = updatedVal;}
	// DataType * clone(stringstream& ss){};
	~NUMERIC(){}
};

class REAL: public DataType
{
private:
	double x;
public:
	REAL(double x):x(x){}
	double get() const {return x;}
	void update(double y) {x = y;}
	DataType * clone(stringstream& ss){};
	~REAL(){}
};

class CHAR: public DataType
{
private:
	char x;
public:
	CHAR(char x):x(x){}
	char get() const {return x;}
	void update(char y) {x = y;}
	DataType * clone(stringstream& ss){};
	~CHAR(){}
};

class STRING: public DataType
{
private:
	char* x;
public:
	STRING(string s, int size) {x = new char[size]; strcpy(x, s.c_str());}
	char* get() const {return x;}
	void update(int index, char c) {x[index] = c;}
	DataType * clone(stringstream& ss){};
	~STRING(){delete[] x;}
};

int main(){
	DataType* d = new NUMERIC("Hello", "132");
	cout << d->value << endl;
// d = new STRING(stringN, defaultVal, size)
}