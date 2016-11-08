#include "common.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////THIS CODE IS SO UNECESSARILY GARBAGE////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////






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
		virtual double getValue() = 0;
		virtual string getName() = 0;
		virtual void updateValue(double updatedVal) = 0;
		virtual char getChar(){}
		virtual void updateChar(char updatedChar){}
		virtual void updateString(int index, char updatedChar){}
		virtual char* getString(){}
		//virtual string getString()
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
	virtual string getName() {cout << name << endl; return name;}
	double getValue() {return value;}
	void updateValue(double updatedVal) {value = updatedVal;}
	void updateChar(char updatedChar){}
	// DataType * clone(stringstream& ss){};
	~NUMERIC(){}
};


class REAL: public DataType // how to use the same function as NUMERIC but return diff data type
{
private:
    string name;
	double value;
public:
	REAL(string name, string x):value(std::stod(x)),name(name),DataType(){}
	virtual string getName() {cout << name << endl; return name;}
	double getValue() {return value;}
	void updateValue(double updatedVal) {value = updatedVal;}
	//DataType * clone(stringstream& ss){};
	~REAL(){}
};


class CHAR: public DataType
{
private:
	string name;
	char x;
public:
	CHAR(string name, string x):name(name),x(x[1]),DataType(){}
	string getName() {cout << name << endl; return name;}
	void updateChar(char y) {x = y;}
	char getChar(){return x;}
	void updateValue(double updatedVal){} // unnecessary
	double getValue(){} // unnecessary
	//DataType * clone(stringstream& ss){};
	~CHAR(){}
};


class STRING: public DataType
{
private:
	string name;
	char* charArray;
public:
	STRING(string name, string s, string size):name(name),DataType(){charArray = new char[atoi(size.c_str())]; strcpy(charArray, s.c_str());}
	string getName() {cout << name << endl; return name;}
	char* getString() {return charArray;}
	void updateString(int index, char c) {charArray[index] = c;}
	void updateValue(double updatedVal){} // unnecessary
	double getValue(){} // unnecessary
	//DataType * clone(stringstream& ss){};
	~STRING(){delete[] charArray;}
};

