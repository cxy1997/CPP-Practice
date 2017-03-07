#include <iostream>
using namespace std;
class size_out_of_range{};
class Rectangle
{
private:
	int length, width;
public:
	Rectangle(int l = 1, int w = 1) 
	{
		if (l <= 0 || l >= 20 || w <= 0 || w >= 20) throw size_out_of_range();
		else
		{
			length = l;
			width = w;
		}
	}
	int perimeter() { return (2 * (length + width)); }
	int area() { return length*width; }
	int setLength(int l)
	{
		if (l <= 0 || l >= 20) throw size_out_of_range();
		else length = l;
	}
	int getLength() { return length; }
	int setWidth(int w)
	{
		if (w <= 0 || w >= 20) throw size_out_of_range();
		else width = w;
	}
	int getWidth() { return width; }
	void draw()
	{
		int i, j;
		for (i = 0; i < length; ++i)
		{
			for (j = 0; j < width; ++j) cout << '*';
			cout << '\n';
		}
	}
};
int main()
{
	Rectangle r1;
	cout << "这是一个1*1的矩形：\n";
	r1.draw();
	cout << "如果设置为不合法长度，";
	try
	{
		r1.setLength(30);
	}
	catch (size_out_of_range)
	{
		cout << "就会像这样报错，\n";
	}
	r1.setLength(6);
	r1.setWidth(8);
	cout << "现在它是个"<<r1.getLength()<<'*'<<r1.getWidth() << "的矩形了：\n"<<r1.perimeter()<<' '<<r1.area();
	r1.draw();
	system("pause");
}