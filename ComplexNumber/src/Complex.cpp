#include "../include/Complex.h"

void Complex::operator+=(const Complex& c) {
	*this = *this + c;
}

void Complex::operator-=(const Complex& c) {
	*this = *this - c;
}

void Complex::operator*=(const Complex& c) {
	*this = *this * c;
}

void Complex::operator/=(const Complex& c) {
	*this = *this / c;
}

Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex{ c1.m_real + c2.m_real, c1.m_imag + c2.m_imag };
}

Complex operator-(const Complex& c1, const Complex& c2) {
	return Complex{ c1.m_real - c2.m_real, c1.m_imag - c2.m_imag };
}

Complex operator*(const Complex& c1, const Complex& c2) {
	return Complex{ (c1.m_real * c2.m_real) - (c1.m_imag * c2.m_imag), (c1.m_real * c2.m_imag) + (c2.m_real * c1.m_imag) };
}

Complex operator/(const Complex& c1, const Complex& c2) {

	double denominator = (c2.m_real * c2.m_real) + (c2.m_imag * c2.m_imag);
	if (denominator == 0) {
		throw "Division by 0 is not possible";
	}
	else {
		double temp_real = ((c1.m_real * c2.m_real) + (c1.m_imag * c2.m_imag)) / denominator;
		double temp_imag = ((c1.m_imag * c2.m_real) - (c1.m_real * c2.m_imag)) / denominator;
		return Complex{ temp_real, temp_imag };
	}
}

std::ostream& operator<<(std::ostream& stream, const Complex& c) {
	stream << '(' << c.m_real << ", " << c.m_imag << ')';
	return stream;
}