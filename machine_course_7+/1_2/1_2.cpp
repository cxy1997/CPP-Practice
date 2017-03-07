#include <cstdio>
#include <cstdlib>
#include <cstring>
const int NAMLEN = 80;
typedef struct Date
{
	int day; /* 1 .. 31 */
	int month; /* 1 .. 12 */
	int year; /* YYYY */
};
typedef struct Person
{
	char name[NAMLEN];
	char first[NAMLEN];
	Date birth;
};
typedef struct List
{
	Person *data;
	List *next;
};
/* -- read on input record and return success/error -- */
auto getrecord(char* nbuf, char* fbuf, int* y, int* m, int* d)
{
	return scanf("%s %s %d.%d.%d", nbuf, fbuf, y, m, d) == 5;
}
int main() {
	freopen("input.dat", "r", stdin);
	char nbuf[NAMLEN];
	char fbuf[NAMLEN];
	int y, m, d;
	List* first = nullptr;
	List* curr = nullptr;
	List* last = nullptr;
	List* add = nullptr;
	Person *p, *old;
	/* -- read persons from stdin -- */
	while (getrecord(nbuf, fbuf, &y, &m, &d)) {
		/* -- construct new person record -- */
		add = new List;
		add->data = p = new Person;
		add->next = nullptr;
		strcpy_s(p->name, nbuf);
		strcpy_s(p->first, fbuf);
		p->birth.year = y;
		p->birth.month = m;
		p->birth.day = d;
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
				if ((strcmp(p->name, old->name) < 0) ||
					((strcmp(p->name, old->name) == 0) &&
					(strcmp(p->first, old->first) <= 0))) {
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
	}
	/* -- print out sorted list and delete list -- */
	curr = first;
	while (curr) {
		p = curr->data;
		printf("%s %s %d.%d.%d\n", p->name, p->first,
			p->birth.year, p->birth.month, p->birth.day);
		last = curr;
		curr = curr->next;
		delete p;
		delete last;
	}
	return 0;
}