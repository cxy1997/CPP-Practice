#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
#include <math.h>
class Complex {
public:
	// default constructor
	Complex(double r = 0.0, double i = 0.0) { re = r; im = i; }
	// copy constructor
	Complex(const Complex& rhs) { re = rhs.re; im = rhs.im; }
	// destructor
	~Complex(void) {}
	// field access functions
	double real(void) const { return re; }
	double imag(void) const { return im; }
	// field modify functions
	void imag(double i) { im = i; }
	void real(double r) { re = r; }
	// assignment operator
	Complex& operator=(const Complex& rhs) {
		if (this == &rhs) return *this; // time-saving self-test
		re = rhs.re; im = rhs.im;
		return *this; // for daisy-chaining
	}
	// equality test operator
	bool operator==(const Complex& rhs) {
		return ((real() == rhs.real()) && (imag() == rhs.imag()));
	}
	// square of the magnitude
	double norm() {
		return real()*real() + imag()*imag();
	}
	// angle in the complex plane
	double arg() {
		if (imag() == 0.0 && real() == 0.0)
			return 0.0;
		else
			return atan2(imag(), real());
	}
	// addition operator
	const Complex operator+(const Complex& rhs) const {
		return Complex(re + rhs.re, im + rhs.im);
	}
	// multiplication operator
	const Complex operator*(const Complex& rhs) const {
		return Complex(re*rhs.re - im*rhs.im, re*rhs.im + im*rhs.re);
	}
private:
	double re, im;
};
// Polar coordinates constructor
Complex polar(double mag, double arg = 0.0) {
	return Complex(mag * cos(arg), mag * sin(arg));
}
// complex conjugate
Complex conj(const Complex& x) {
	return Complex(x.real(), -x.imag());
}
double norm(const Complex& x) {
	return x.real()*x.real() + x.imag()*x.imag();
}
const double epsilon = 1.0e-15;
// output operator
ostream& operator<<(ostream& output, const Complex& rhs) {
	if (-epsilon < rhs.real() && rhs.real() < epsilon)
		output << "(0,";
	else
		output << "(" << rhs.real() << ",";
	if (-epsilon < rhs.imag() && rhs.imag() < epsilon)
		output << "0i)"; 
	else
		output << rhs.imag() << "i)";
	return output;
}
#endif