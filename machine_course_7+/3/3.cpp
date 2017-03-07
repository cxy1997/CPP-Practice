#include <iostream>
using namespace std;
#include "Complex.h"
class Base {
public:
	virtual void f(int) {
		cout << "Base::f(int)" << endl;
	}
	virtual void f(double) {
		cout << "Base::f(double)" << endl;
	}
	virtual void g(int i = 10) {
		cout << "Base::g(int = " << i << ')' << endl;
	}
};
class Derived : public Base {
public:
	virtual void f(Complex) {
		cout << "Derived::f(Complex)" << endl;
	}
	virtual void g(int i = 20) {
		cout << "Derived::g(int = " << i << ')' << endl;
	}
};
int main() {
	Base b;
	Derived d;
	Base* pb = new Derived;
	b.f(1.0);    //base::f(double)
	d.f(1.0);    //derived::f(Complex)
	pb->f(1.0);  //base::f(double)
	b.g();       //base::g(10)
	d.g();       //derived::g(20)
	pb->g();     //derived::g(10)
	delete pb;
}