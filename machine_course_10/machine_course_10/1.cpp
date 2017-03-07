#include "Window.h";
#include "Graph.h";
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_draw.H"
#include "Li.h"
#include <cmath>
#include <iostream>
#include <vector>
#include "Binary_Tree.h"
using namespace std;
using namespace Graph_lib;
int main()
{
	Graph_lib::Window win(800, 600, "Binary Tree");
	Binary_tree tree(5, Point(400, 50), 12, "0123456789abcdef", true, Color::magenta);
	Triangle_tree tree2(5, Point(400, 350), 12, "0123456789abcdef");
	tree.affiliate_to(win);
	tree2.affiliate_to(win);
	win.show();
	return Fl::run();
}