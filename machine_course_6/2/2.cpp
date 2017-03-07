#include <iostream>
using namespace std;
class Polynomial
{
private:
	int Nterms;
	double* pCoeffs;
public:
	Polynomial()
	{
		Nterms = 1;
		pCoeffs = new double[1];
		pCoeffs[0] = 1;
	}
	Polynomial(const Polynomial& other)
	{
		Nterms = other.Nterms;
		pCoeffs = new double[Nterms];
		for (int i = 0; i < Nterms; ++i) pCoeffs[i] = other.pCoeffs[i];
	}
	Polynomial& operator=(const Polynomial& other)
	{
		if (this == &other) return (*this);
		delete[] pCoeffs;
		Nterms = other.Nterms;
		pCoeffs = new double[Nterms];
		for (int i = 0; i < Nterms; ++i) pCoeffs[i] = other.pCoeffs[i];
		return (*this);
	}
	~Polynomial()
	{
		if (pCoeffs)
		{
			delete[]pCoeffs;
			pCoeffs = NULL;
		}
	}
	Polynomial(double Coeffs[], int N_terms)
	{
		Nterms = N_terms;
		pCoeffs= new double[Nterms];
		for (int i = 0; i < Nterms; ++i) pCoeffs[i] = Coeffs[i];
	}
	friend istream& operator >> (istream& in, Polynomial p);
	friend ostream& operator << (ostream& out, const Polynomial p);
	double evaluateAt(double x)
	{
		double res = 0;
		int p = 0;
		for (int i = 0; i < Nterms; ++i)
		{
			if (i == 0) p = 1; else p *= x;
			res += p*pCoeffs[i];
		}
		return res;
	}
	friend Polynomial operator+(const Polynomial& a, const Polynomial& b);
	friend Polynomial operator-(const Polynomial& a, const Polynomial& b);
	friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
};
istream& operator >> (istream& in, Polynomial p)
{
	if (p.pCoeffs) delete[] p.pCoeffs;
	in >> p.Nterms;
	p.pCoeffs = new double[p.Nterms];
	for (int i = 0; i < p.Nterms; ++i) in >> p.pCoeffs[i];
	return in;
}
ostream& operator << (ostream& out, const Polynomial p)
{
	int highest;
	for (highest = p.Nterms - 1; highest >= 0 && p.pCoeffs[highest]<0.000002 && p.pCoeffs[highest]>-0.000002; --highest);
	for (int i = highest; i >= 0; --i) if (p.pCoeffs[i]>0.000002 || p.pCoeffs[i]<-0.000002)
	{
		if (i != highest && p.pCoeffs[i] > 0) out << "+ ";
		out << p.pCoeffs[i] << ' ';
		if (i != 0) out << "* x ";
		if (i > 1) out << "^ " << i << ' ';
	}
	return out;
}
Polynomial operator+(const Polynomial& a, const Polynomial& b)
{
	int i;
	if (a.Nterms > b.Nterms)
	{
		double *tmp = new double[a.Nterms];
		for (i = 0; i < b.Nterms; ++i) tmp[i] = a.pCoeffs[i] + b.pCoeffs[i];
		for (i = b.Nterms; i < a.Nterms; ++i) tmp[i] = a.pCoeffs[i];
		Polynomial res(tmp, a.Nterms);
		delete[] tmp;
		return res;
	}
	else
	{
		double *tmp = new double[b.Nterms];
		for (i = 0; i < a.Nterms; ++i) tmp[i] = a.pCoeffs[i] + b.pCoeffs[i];
		for (i = a.Nterms; i < b.Nterms; ++i) tmp[i] = b.pCoeffs[i];
		Polynomial res(tmp, b.Nterms);
		delete[] tmp;
		return res;
	}
}
Polynomial operator-(const Polynomial& a, const Polynomial& b)
{
	int i;
	if (a.Nterms > b.Nterms)
	{
		double *tmp = new double[a.Nterms];
		for (i = 0; i < b.Nterms; ++i) tmp[i] = a.pCoeffs[i] - b.pCoeffs[i];
		for (i = b.Nterms; i < a.Nterms; ++i) tmp[i] = a.pCoeffs[i];
		Polynomial res(tmp, a.Nterms);
		delete[] tmp;
		return res;
	}
	else
	{
		double *tmp = new double[b.Nterms];
		for (i = 0; i < a.Nterms; ++i) tmp[i] = a.pCoeffs[i] - b.pCoeffs[i];
		for (i = a.Nterms; i < b.Nterms; ++i) tmp[i] = -b.pCoeffs[i];
		Polynomial res(tmp, b.Nterms);
		delete[] tmp;
		return res;
	}
}
Polynomial operator*(const Polynomial& a, const Polynomial& b)
{
	int size = a.Nterms + b.Nterms - 1;
	double *tmp = new double[size];
	int i, j;
	for (i = 0; i < size; ++i) tmp[i] = 0;
	for (i = 0; i < a.Nterms; ++i) for (j = 0; j < b.Nterms; ++j) tmp[i + j] += a.pCoeffs[i] * b.pCoeffs[j];
	Polynomial res(tmp, size);
	delete[] tmp;
	return res;
}
int main()
{
	double Cnum[5] = { 1,1,1,1,1 };
	double Dnum[7] = { 1,1,1,1,1,0,1 };
	Polynomial Pnum(Cnum, 5), Qnum(Dnum, 7);
	cout << "Pnum = " << Pnum << '\n';
	cout << "Pnum(2.0) = " << Pnum.evaluateAt(2) << '\n';
	cout << "Qnum = " << Qnum << '\n';
	cout << "Pnum + Qnum = " << Pnum + Qnum << '\n';
	cout << "Pnum - Qnum = " << Pnum - Qnum << '\n';
	cout << "Pnum * Qnum = " << Pnum * Qnum << '\n';
	system("pause");
}