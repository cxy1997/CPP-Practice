#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "String.h"
using namespace std;
const int NAMLEN = 80;
class Date
{
public:
	int day; /* 1 .. 31 */
	int month; /* 1 .. 12 */
	int year; /* YYYY */
	friend istream& operator >> (istream& in, Date& d);
};
istream& operator >> (istream& in, Date& d)
{
	char t1, t2;
	in >> d.year >> t1 >> d.month >> t2 >> d.day;
	return in;
}
class Person
{
public:
	String name, first;
	Date birth;
	friend istream& operator >> (istream& in, Person& p);
};
istream& operator >> (istream& in, Person& p)
{
	in >> p.name >> p.first >> p.birth;
	return in;
}
typedef struct List
{
	Person *data;
	List *next;
};
/* -- read on input record and return success/error -- */
int main() {
	//freopen("input.dat", "r", stdin);
	ifstream fin("input.dat");
	char nbuf[NAMLEN];
	char fbuf[NAMLEN];
	int y, m, d;
	List* first = nullptr;
	List* curr = nullptr;
	List* last = nullptr;
	List* add = new List;
	Person *p, *old;
	add->data = p = new Person;
	/* -- read persons from stdin -- */
	while (fin>>(*(add->data))) {
		/* -- construct new person record -- */
		add->next = nullptr;
		/* -- add to list (and sort them already at insertion time) -- */
		if (first == nullptr) {
			/* -- first record -- */
			first = add;
		}
		else {
			/* -- there are already records -- */
			curr = first;
			last = nullptr;
			while (curr) {
				old = curr->data;
				if (p->name < old->name ||
					(p->name == old->name &&
					p->first <= old->first)) {
					break;
				}
				last = curr;
				curr = curr->next;
			}
			/* -- insert at right place -- */
			add->next = curr;
			if (last) {
				last->next = add;
			}
			else {
				first = add;
			}
		}
		add = new List;
		add->data = p = new Person;
	}
	/* -- print out sorted list and delete list -- */
	curr = first;
	while (curr) {
		p = curr->data;
		cout << (p->name) << ' ' << (p->first) << ' ' << (p->birth.year) << '.' << (p->birth.month) << '.' << (p->birth.day) << '\n';
		//printf("%s %s %d.%d.%d\n", p->name, p->first, p->birth.year, p->birth.month, p->birth.day);
		last = curr;
		curr = curr->next;
		delete p;
		delete last;
	}
	return 0;
}