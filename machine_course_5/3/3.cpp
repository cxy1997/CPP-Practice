#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Format_Error{};
class Matrix
{
private:
	double **data;
	int col, row;
public:
	Matrix(int r = 2, int c = 2) :col(c), row(r)
	{
		if (row > 0 && col > 0)
		{
			data = new double*[row];
			for (int i = 0; i < row; ++i)
			{
				data[i] = new double[col];
				for (int j = 0; j < col; ++j) data[i][j] = 0;
			}
		}
	}
	int colomns() { return col; }
	int rows() { return row; }
	~Matrix()
	{
		for (int i = 0; i < row; ++i) delete[] data[i];
		delete[] data;
	}
	void cover(int x, int y, const Matrix& p)
	{
		if (p.row == 0 || p.col == 0) return;
		int i, j;
		for (i = 0; i < p.row; ++i) for (j = 0; j < p.col; ++j) data[i + x][j + y] = p.data[i][j];
	}
	Matrix(const Matrix& other)
	{
		col = other.col;
		row = other.row;
		if (row > 0 && col > 0)
		{
			data = new double*[row];
			for (int i = 0; i < row; ++i)
			{
				data[i] = new double[col];
				for (int j = 0; j < col; ++j) data[i][j] = other.data[i][j];
			}
		}
	}
	Matrix& operator=(const Matrix& other)
	{
		if (this == &other) return (*this);
		if (row > 0 && col > 0)
		{
			for (int i = 0; i < row; ++i) delete[] data[i];
			delete[] data;
		}
		col = other.col;
		row = other.row;
		if (row > 0 && col > 0)
		{
			data = new double*[row];
			for (int i = 0; i < row; ++i)
			{
				data[i] = new double[col];
				for (int j = 0; j < col; ++j) data[i][j] = other.data[i][j];
			}
		}
		return (*this);
	}
	Matrix part(int rl, int rr, int cl, int cr) const
	{
		if (rl >= rr || cl >= cr) return Matrix(0, 0);
		Matrix res(rr - rl + 1, cr - cl + 1);
		int i, j;
		for (i = 0; i < rr - rl + 1; ++i) for (j = 0; j < cr - cl + 1; ++j) res.data[i][j] = data[i + rl][j + cl];
		return res;
	}
	friend Matrix operator+(const Matrix& a, const Matrix& b);
	friend Matrix operator*(const Matrix& a, const Matrix& b);
	friend istream& operator >> (istream& in, Matrix& m);
	friend ostream& operator << (ostream& out, const Matrix& m);
};
Matrix operator+(const Matrix& a, const Matrix& b)
{
	if (a.row != b.row || a.col != b.col) throw Format_Error();
	if (a.row == 0 || a.col == 0) return Matrix(0, 0);
	Matrix res(a.row, a.col);
	int i, j;
	for (i = 0; i < a.row; ++i) for (j = 0; j < a.col; ++j) res.data[i][j] = a.data[i][j] + b.data[i][j];
	return res;
}
Matrix operator*(const Matrix& a, const Matrix& b)
{
	if (a.col != b.row) throw Format_Error();
	if (a.row == 0 || a.col == 0 || b.col == 0) return Matrix(0,0);
	if ((a.row %2!=0 && a.col % 2 != 0 && b.col % 2 != 0) || (a.row <= 2 || a.col <= 2 || b.col <= 2))
	{
		Matrix res(a.row, b.col);
		int i, j, k;
		for (i = 0; i < a.row; ++i) for (j = 0; j < b.col; ++j) for (k = 0; k < a.col; ++k) res.data[i][j] += a.data[i][k] * b.data[k][j];
		return res;
	}
	else
	{
		Matrix res(a.row, b.col);
		Matrix alu = a.part(0, a.row / 2 - 1, 0, a.col / 2 - 1);
		Matrix aru = a.part(0, a.row / 2 - 1, a.col / 2, a.col - 1);
		Matrix ald = a.part(a.row / 2, a.row - 1, 0, a.col / 2 - 1);
		Matrix ard = a.part(a.row / 2, a.row - 1, a.col / 2, a.col - 1);
		Matrix blu = b.part(0, b.row / 2 - 1, 0, b.col / 2 - 1);
		Matrix bru = b.part(0, b.row / 2 - 1, b.col / 2, b.col - 1);
		Matrix bld = b.part(b.row / 2, b.row - 1, 0, b.col / 2 - 1);
		Matrix brd = b.part(b.row / 2, b.row - 1, b.col / 2, b.col - 1);
		Matrix leftup = alu*blu + aru*bld;
		Matrix leftdown = ald*blu + ard*bld;
		Matrix rightup = alu*bru + aru*brd;
		Matrix rightdown = ald*bru + ard*brd;
		res.cover(0, 0, leftup);
		res.cover(0, b.col / 2, rightup);
		res.cover(a.row / 2, 0, leftdown);
		res.cover(a.row / 2, b.col / 2, rightdown);
		return res;
	}
}
istream& operator >> (istream& in, Matrix& m)
{
	int i, j;
	for (i = 0; i < m.row; ++i) for (j = 0; j < m.col; ++j) in >> m.data[i][j];
	return in;
}
ostream& operator << (ostream& out, const Matrix& m)
{
	int i, j;
	for (i = 0; i < m.row; ++i)
	{
		for (j = 0; j < m.col; ++j) out << setw(6) << m.data[i][j];
		out << '\n';
	}
	return out;
}
int main()
{
	ifstream fin("3.in");
	Matrix a(4,4), b(4,4);
	fin >> a >> b;
	cout << a*b;
	system("pause");
}