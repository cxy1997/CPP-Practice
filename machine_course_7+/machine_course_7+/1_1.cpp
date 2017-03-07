#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMLEN 80
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
	List* first = 0;
	List* curr = 0;
	List* last = 0;
	List* add = 0;
	Person *p, *old;
	/* -- read persons from stdin -- */
	while (getrecord(nbuf, fbuf, &y, &m, &d)) {
		/* -- construct new person record -- */
		add = new List;
		add->data = p = new Person;
		add->next = 0;
		strcpy(p->name, nbuf);
		strcpy(p->first, fbuf);
		p->birth.year = y;
		p->birth.month = m;
		p->birth.day = d;
		/* -- add to list (and sort them already at insertion time) -- */
		if (first == 0) {
			/* -- first record -- */
			first = add;
		}
		else {
			/* -- there are already records -- */
			curr = first;
			last = 0;
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