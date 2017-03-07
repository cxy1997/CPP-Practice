#include "std_lib_facilities.h"
typedef vector<char> Line;    // a line is a vector of characters
class Text_iterator { // keep track of line and character position within a line
	list<Line>::iterator ln;
	Line::iterator pos;
public:
	typedef forward_iterator_tag iterator_category;
	typedef char value_type;
	typedef size_t difference_type;
	typedef char* pointer;
	typedef char& reference;

	// start the iterator at line ll's character position pp:
	Text_iterator(list<Line>::iterator ll, Line::iterator pp)
		:ln(ll), pos(pp) { }

	char& operator*() { return *pos; }
	Text_iterator& operator++();
	bool operator==(const Text_iterator& other) const;
	bool operator!=(const Text_iterator& other) const { return !(*this == other); }
	void remove()
	{
		pos = ln->erase(pos);
		if (pos == ln->end())
		{
			++ln;
			pos = ln->begin();
		}
	}
	void insert(char t)
	{
		pos = ln->insert(pos, t);
		/*if (t == '\n')
		{
			ln = d.line.insert(ln,Line());
			pos = ln->begin();
		}*/
	}
};
Text_iterator& Text_iterator::operator++()
{
	++pos;
	if (pos == (*ln).end()) {
		++ln;            // proceed to next line
		pos = (*ln).begin();
	}                // proceed to next character
	return *this;
}
bool Text_iterator::operator==(const Text_iterator& other) const
{
	return (ln == other.ln && pos == other.pos);
}
struct Document {
	list<Line> line;
	Document() { line.push_back(Line());}
	Text_iterator begin() // first character of first line
	{
		return Text_iterator(line.begin(), line.begin()->begin());
	}
	Text_iterator end()        // one beyond the last line
	{
		list<Line>::iterator last = line.end();
		--last;
		return Text_iterator(last, (*last).begin());
	}
	friend istream& operator >> (istream& is, Document& d);
	friend ostream& operator << (ostream& os, Document& d);
};
istream& operator >> (istream& is, Document& d)
{
	char ch;
	while (is.get(ch))
	{
		d.line.back().push_back(ch);
		if (ch == '\n') d.line.push_back(Line());
	}
	d.line.push_back(Line());
	return is;
}
ostream& operator << (ostream& os, Document& d)
{
	for (Text_iterator t = d.begin(); t != d.end(); ++t) cout << *t;
	return os;
}
void print(Document& d)
{
	for (Text_iterator p = d.begin(); p != d.end(); ++p) cout << *p;
}
template<class Iter> 
Iter advance(Iter p, int n)
{
	while (n>0) { ++p; --n; }    // go forwards
	return p;
}
void erase_line(Document& d, int n)
{
	if (n<0 || d.line.size() <= n) return;    // ignore out-of-range lines
	d.line.erase(advance(d.line.begin(), n));
}
bool match(Text_iterator first, Text_iterator last, const string& s)
{
	string::const_iterator p;

	for (p = s.begin();
		p != s.end() && first != last && *p == *first;
		++p, ++first)
	{
		//cout << *p;
	}

	return p == s.end(); // if we reached end of string, we matched it all
}
Text_iterator find_text(Text_iterator first, Text_iterator last, string s)
{
	if (s.size() == 0) return last;    // can't find an empty string
	char first_char = s[0];
	Text_iterator p = first;
	while (true) 
	{
		while (p != last && *p != s[0]) ++p;
		if (p == last || match(p, last, s)) return p; else ++p;
	}
}
Text_iterator find_and_replace(Text_iterator first, Text_iterator last, const string& s, const string& r)
{
	Text_iterator tar = find_text(first, last, s);
	if (tar == last) return tar;
	/*else 
	{
		Text_iterator p = tar;
		for (int i = 0; i < s.size(); ++i) p.remove();
		p = tar;
		for (int i = 0; i < r.size(); ++i) tar.insert(r[i]);
		return p;
	}*/
	Text_iterator p = tar;
	for (int i = 0; i < r.size(); ++i)
	{
		*p = r[i];
		++p;
	}
}
int main()
{
	Document my_doc;
	ifstream fin("1.in");
	fin >> my_doc;
	cout << my_doc <<endl;
	Text_iterator b = my_doc.begin();
	Text_iterator e = my_doc.end();
	Text_iterator p = find_text(b, e, "secret\nhomestead");
	if (p == my_doc.end())
		cout << "not found";
	else {
		cout << "Find!\n";
		Text_iterator q = find_and_replace(b, e, "secret\nhomestead", "theres no secret");
	}
	cout << my_doc;
	fin.close();
	system("pause");
}

//------------------------------------------------------------------------------
