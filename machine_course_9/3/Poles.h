#ifndef POLES
#define POLES
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_draw.H"
#include "Window.h";
#include "Graph.h";
#include <vector>
using namespace std;
using namespace Graph_lib;
class Negative_Number_Error{};
class Poles
{
private:
	vector<Fl_Box*> data;
	vector<Fl_Box*> mark;
public:
	Poles(const vector<string>& v1, const vector<double>& v2)
	{
		int i;
		Fl_Box *tmp;
		double max = 0.00002;
		for (i = 0; i < v2.size(); ++i)
		{
			if (v2[i] < -0.00002) throw Negative_Number_Error();
			if (v2[i] > max) max = v2[i];
		}
		for (i = 0; i < v2.size(); ++i)
		{
			tmp = new Fl_Box(100 + i*600.0 / v2.size(), 500 - 400.0*v2[i] / max, 600.0 / v2.size(), 400.0*v2[i] / max);
			data.push_back(tmp);
			data[i]->color(Color::yellow);
			data[i]->box(FL_BORDER_BOX);
			tmp = new Fl_Box(90 + (i + 0.5)*600.0 / v2.size(), 486 - 400.0*v2[i] / max, 20, 10, v1[i].c_str());
			mark.push_back(tmp);
			mark[i]->box(FL_NO_BOX);
		}
	}
	/*~Poles()
	{
		for (int i = 0; i < data.size(); ++i) delete data[i];
	}*/
	void affiliate_to(Graph_lib::Window& win)
	{
		for (int i = 0; i < data.size(); ++i)
		{
			win.add(*data[i]);
			win.add(*mark[i]);
		}
	}
};
#endif

