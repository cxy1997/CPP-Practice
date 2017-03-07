#include <iostream>
using namespace std;
class base {
public:
	void Iam() { cout << "base::Iam()" << endl; } /*1*/
	virtual void Iam_v() { cout << "base::Iam_v()" << endl; } /*2*/
};
class drvd : public base {
public:
	virtual void Iam() { cout << "drvd::Iam()" << endl; } /*3*/
	virtual void Iam_v() { cout << "drvd::Iam_v()" << endl; } /*4*/
};
class drvddrvd : public drvd {
public:
	virtual void Iam() { cout << "drvddrvd::Iam()" << endl; } /*5*/
	virtual void Iam_v() { cout << "drvddrvd::Iam_v()" << endl; } /*6*/
};
int main() {
	base b;
	drvd d;
	drvddrvd dd;
	base *pb;
	drvd *pd;
	b.Iam();     //base::Iam()
	b.Iam_v();   //base::Iam_v()
	d.Iam();     //drvd::Iam()
	d.Iam_v();   //drvd::Iam_v()
	dd.Iam();    //drvddrvd::Iam()
   	dd.Iam_v();  //drvdfrvd::Iam_v()
	pb = &b;
	pb->Iam();   //base::Iam()
	pb->Iam_v(); //base::Iam_v()
	pb = &d;
	pb->Iam();   //base::Iam()
	pb->Iam_v(); //drvd::Iam_v()
	pb = &dd;
	pb->Iam();   //base::Iam()
	pb->Iam_v(); //drvddrvd::Iam_v()
	pd = &d;
	pd->Iam();   //drvd::Iam()
	pd->Iam_v(); //drvd::Iam_v()
	pd = &dd;
	pd->Iam();   //drvddrvd::Iam()
	pd->Iam_v(); //drvddrvd::Iam_v()
}