#ifndef _ComplexNumber_h_
#define _ComplexNumber_h_

#include<iostream>

class Complex {
private:
	double m_real;
	double m_imag;

public:
	Complex(double real = 0.0, double imag = 0.0) : m_real{ real }, m_imag{ imag } {}

	void operator+=(const Complex&);
	void operator-=(const Complex&);
	void operator*=(const Complex&);
	void operator/=(const Complex&);


	friend Complex operator+(const Complex& c1, const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend Complex operator/(const Complex& c1, const Complex& c2);

	friend std::ostream& operator<<(std::ostream&, const Complex&);
};



#endif // !_ComplexNumber_h_
