#include<iostream>
#include <string>
using namespace std;
class Link {
public:
	string name, origin, horse, weapon;

	Link(const string& n, const string& o, const string& h, const string& w, Link* p = 0, Link* s = 0)
		: name(n), origin(o), horse(h), weapon(w), prev(p), succ(s) { }
	Link(const Link& other)
	{
		name = other.name;
		origin = other.origin;
		horse = other.horse;
		weapon = other.weapon;
		Link *p = this, *q = other.prev;
		while (q != NULL)
		{
			p->prev = new Link(q->name, q->origin, q->horse, q->weapon);
			p->prev->succ = p;
			p = p->prev;
			q = q->prev;
		}
		p = this;
		q = other.succ;
		while (q != NULL)
		{
			p->succ = new Link(q->name, q->origin, q->horse, q->weapon);
			p->succ->prev = p;
			p = p->succ;
			q = q->succ;
		}
	}
	Link& operator=(const Link& other)
	{
		if (this == &other) return *this;
		if (prev)
		{
			prev->succ = NULL;
			delete prev;
		}
		if (succ)
		{
			succ->prev = NULL;
			delete succ;
		}
		prev = NULL;
		succ = NULL;
		name = other.name;
		origin = other.origin;
		horse = other.horse;
		weapon = other.weapon;
		Link *p = this, *q = other.prev;
		while (q != NULL)
		{
			p->prev = new Link(q->name, q->origin, q->horse, q->weapon);
			p->prev->succ = p;
			p = p->prev;
			q = q->prev;
		}
		p = this;
		q = other.succ;
		while (q != NULL)
		{
			p->succ = new Link(q->name, q->origin, q->horse, q->weapon);
			p->succ->prev = p;
			p = p->succ;
			q = q->succ;
		}
		return *this;
	}
	~Link()
	{
		if (prev)
		{
			prev->succ = NULL;
			delete prev;
		}
		if (succ)
		{
			succ->prev = NULL;
			delete succ;
		}
	}
	Link* add_ordered(Link* n);   // add_ordered n before this object
							 //Link* add(Link* n);      // add_ordered n after this object
	Link* erase();           // remove this object from list
	Link* find(const string& s);    // find s in list
									//const Link* find(const string& s) const; // find s in list

									//Link* advance(int n) const;     // move n positions in list

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};

//------------------------------------------------------------------------------

Link* Link::add_ordered(Link* n)   // add_ordered n before this object; return n
{
	if (n == 0) return this;
	if (this == 0) return n;
	Link *p = this;
	if (n->name < p->name)
	{
		while (p->prev != NULL && p->name > n->name) p = p->prev;
		if (p->prev == NULL)
		{
			p->prev = n;
			n->succ = p;
			return n;
		}
		n->prev = p;
		if (p->succ) p->succ->prev = n;
		n->succ = p->succ;
		p->succ = n;
	}
	else
	{
		while (p->succ != NULL && p->name < n->name) p = p->succ;
		if (p->succ == NULL)
		{
			p->succ = n;
			n->prev = p;
		}
		else
		{
			n->succ = p;
			if (p->prev) p->prev->succ = n;
			n->prev = p->prev;
			p->prev = n;
		}
	}
	while (n->prev != NULL) n = n->prev;
	return n;
}

//------------------------------------------------------------------------------

Link* Link::erase()          // remove this object from the list; return this's successor
{
	if (this == 0) return 0;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;
}

//------------------------------------------------------------------------------

Link* Link::find(const string& s) // find s in list;
								  // return 0 for "not found"
{
	Link* p = this;
	while (p) {
		if (p->name == s) return p;
		p = p->succ;
	}
	return 0;
}

//------------------------------------------------------------------------------

void print_all(Link* p)
{
	while (p) {
		cout << "name:" << p->name << " origin:" << p->origin << " horse:" << p->horse << " weapon:" << p->weapon << '\n';
		p = p->next();
	}
}

//------------------------------------------------------------------------------

int main()
{
	Link* norse_gods = new Link("Thor", "Norway", "dog", "hammer");
	norse_gods = norse_gods->add_ordered(new Link("Odin", "Norway", "cat", "stick"));
	norse_gods = norse_gods->add_ordered(new Link("Zeus", "Norway", "bunny", "pistol"));
	norse_gods = norse_gods->add_ordered(new Link("Freia", "Norway", "parrot", "Italish Cannon"));

	Link* greek_gods = new Link("Hera", "Greek", "dragon", "boomerang");
	greek_gods = greek_gods->add_ordered(new Link("Athena", "Greek", "pig", "rifle"));
	greek_gods = greek_gods->add_ordered(new Link("Mars", "Greek", "Pi-ka-chu", "space saber"));
	greek_gods = greek_gods->add_ordered(new Link("Poseidon", "Greek", "Dragon", "rocket launcher"));

	Link* p = greek_gods->find("Mars");
	if (p) p->name = "Maroon";

	// Move Zeus into his correct Pantheon: 
	{
		Link* p = norse_gods->find("Zeus");
		if (p) {
			if (p == norse_gods) norse_gods = p->next();
			p->erase();
			greek_gods = greek_gods->add_ordered(p);
		}
	}

	// Finally, let's print out those lists:
	cout << "norse_gods:\n";
	print_all(norse_gods);
	cout << "\n\n";
	cout << "greek_gods:\n";
	print_all(greek_gods);
	cout << "\n\ncoppying:\n";
	Link qqq = *greek_gods;
	cout << "\ndeleting:\n";
	delete greek_gods;
	cout << "\n";
	print_all(&qqq);
	cout << "\n";
}