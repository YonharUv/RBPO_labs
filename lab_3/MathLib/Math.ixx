module;
#include <math.h>
#include <iostream>
export module Math;
export class Complex
{
	double m_re;
	double m_im;
public:
	Complex() :m_re(0), m_im(0) {}
	Complex(double re) :m_re(re), m_im(0) {}
	Complex(double re, double im) :m_re(re), m_im(im) {}

	Complex static FromExponentialForm(double mod, double arg) {
		Complex newObj{ mod * cos(arg), mod * sin(arg) };
		return newObj;
	}

	Complex static FromAlgebraicForm(double re, double im) {
		Complex newObj{ re, im };
		return newObj;
	}

	double Re() const {
		return m_re;
	}

	double Im() const {
		return m_im;
	}

	double Mod() const {
		return sqrt(m_re * m_re + m_im * m_im);
	}

	double Arg() const {
		return atan2(m_im, m_re);
	}

	explicit operator double() { return m_re; }

	Complex operator-() const
	{
		return Complex(-m_re, -m_im);
	}

	Complex& operator++()
	{
		m_re++;
		return *this;
	}

	Complex operator++(int)
	{
		Complex newObj(*this);
		++(*this);
		return newObj;
	}

	Complex& operator--()
	{
		m_re--;
		return *this;
	}

	Complex operator--(int)
	{
		Complex newObj(*this);
		--(*this);
		return newObj;
	}

	Complex& operator+=(Complex rhs)
	{
		m_re += rhs.m_re;
		m_im += rhs.m_im;
		return *this;
	}

	Complex& operator-=(Complex rhs)
	{
		m_re -= rhs.m_re;
		m_im -= rhs.m_im;
		return *this;
	}

	Complex& operator*=(Complex rhs)
	{
		m_re *= rhs.m_re;
		m_im *= rhs.m_im;
		return *this;
	}

	Complex& operator/=(Complex rhs)
	{
		m_re /= rhs.m_re;
		m_im /= rhs.m_im;
		return *this;
	}
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend Complex operator ""i(long double);
	friend Complex operator ""i(unsigned long long);
	friend Complex pow(const Complex&, double);
	friend Complex tanh(const Complex&);
};

export Complex pow(const Complex& obj, double exp) {
	Complex newObj = obj;

	for (int i = 0; i <= abs(exp); ++i) {
		newObj *= obj;
	}
	return newObj;
}

export Complex tanh(const Complex& obj) {
	Complex newObj = obj;
	return Complex(tanh((double)newObj));
}

export Complex operator+(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.m_re + rhs.m_re, lhs.m_im + rhs.m_im);
}

export Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.m_re - rhs.m_re, lhs.m_im - rhs.m_im);
}

export Complex operator*(const Complex& lhs, const Complex& rhs)
{
	double re = lhs.m_re * rhs.m_re - lhs.m_im * rhs.m_im;
	double im = lhs.m_re * rhs.m_im + lhs.m_im * rhs.m_re;
	return Complex(re, im);
}

export Complex operator/(const Complex& lhs, const Complex& rhs)
{
	double reLhs = lhs.m_re, reRhs = rhs.m_re, re;
	double imLhs = lhs.m_im, imRhs = rhs.m_im, im;
	re = (reLhs * reRhs + imLhs * imRhs) / (reRhs * reRhs + imRhs * imRhs);
	im = (reRhs * imLhs - reLhs * imRhs) / (reRhs * reRhs + imRhs * imRhs);
	return Complex(re, im);
}

export Complex operator ""i(unsigned long long im) {
	return Complex(0.0, (double)im);
}
export Complex operator ""i(long double im) {
	return Complex(0.0, (double)im);
}
export std::ostream& operator<<(std::ostream& stream, const Complex& inst) {
	if (inst.m_im < 0) {
		stream << inst.m_re << inst.m_im << "i";
	}
	else {
		stream << inst.m_re << "+" << inst.m_im << "i";
	}
	return stream;
}

export int FindGreatestCommonDivisor(int a, int b) {
	if (a < 0) {
		a *= -1;
	}
	if (b < 0) {
		b *= -1;
	}
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

export int FindLeastCommonMultiple(int a, int b) {
	return abs(a * b) / FindGreatestCommonDivisor(a, b);
}

export class Rational {

	int m_nominator;
	int m_denominator;

	void norm() {
		int gcd = FindGreatestCommonDivisor(m_nominator, m_denominator);
		m_nominator /= gcd;
		m_denominator /= gcd;
		if (m_denominator < 0) {
			m_denominator *= -1;
			m_nominator *= -1;
		}
	}

public:
	Rational():m_nominator(0), m_denominator(1) {}
	Rational(int nominator, int denominator) :m_nominator(nominator), m_denominator(denominator) {norm();}
	Rational(int nominator) :m_nominator(nominator), m_denominator(1) { norm(); }

	int Nominator() const {
		return m_nominator;
	}

	int Denominator() const {
		return m_denominator;
	}

	explicit operator double() const {
		return (double)m_nominator / m_denominator;
	}

	Rational operator-() const{
		return Rational(-m_nominator, m_denominator);
	}


	Rational& operator++()
	{
		m_nominator += m_denominator;
		norm();
		return *this;
	}

	Rational operator++(int)
	{
		Rational newObj(*this);
		++(*this);
		norm();
		return newObj;
	}

	Rational& operator--()
	{
		m_nominator -= m_denominator;
		norm();
		return *this;
	}

	Rational operator--(int)
	{
		Rational newObj(*this);
		--(*this);
		norm();
		return newObj;
	}

	Rational& operator+=(Rational rhs)
	{
		m_nominator += rhs.m_nominator;
		m_denominator += rhs.m_denominator;
		norm();
		return *this;
	}

	Rational& operator-=(Rational rhs)
	{
		m_nominator -= rhs.m_nominator;
		m_denominator -= rhs.m_denominator;
		norm();
		return *this;
	}

	Rational& operator*=(Rational rhs)
	{
		m_nominator *= rhs.m_nominator;
		m_denominator *= rhs.m_denominator;
		norm();
		return *this;
	}

	Rational& operator/=(Rational rhs)
	{
		m_nominator /= rhs.m_nominator;
		m_denominator /= rhs.m_denominator;
		norm();
		return *this;
	}
	friend Rational operator+ (const Rational& lhs, const Rational& rhs);
	friend Rational operator- (const Rational& lhs, const Rational& rhs);
	friend Rational operator* (const Rational& lhs, const Rational& rhs);
	friend Rational operator/(const Rational& lhs, const Rational& rhs);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
	friend bool operator>(const Rational& lhs, const Rational& rhs);
	friend bool operator<(const Rational& lhs, const Rational& rhs);
	friend bool operator>=(const Rational& lhs, const Rational& rhs);
	friend bool operator<=(const Rational& lhs, const Rational& rhs);
	friend std::ostream& operator<<(std::ostream& stream, const Rational& instance);
	friend Rational pow(const Rational& base, double exponent);
	friend Rational tanh(const Rational& value);
};

export Rational pow(const Rational& obj, double exp) {
	Rational newObj = obj;

	for (int i = 0; i <= abs(exp); ++i) {
		newObj *= obj;
	}
	return newObj;
}

export Rational tanh(const Rational& value) {
	double result = tanh((double)value);
	double intPart;
	double fracPart = modf(result, &intPart);

	int num = (int)intPart;
	int denom = (int)(1.0 / fracPart);

	return Rational(num, denom);
}

export Rational operator+ (const Rational& lhs, const Rational& rhs) {
	int denominator = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
	int nominator = denominator / lhs.m_denominator * lhs.m_nominator;
	nominator += denominator / rhs.m_denominator * rhs.m_nominator;
	return Rational (nominator, denominator);
}

export Rational operator-(const Rational& lhs, const Rational& rhs)
{
	int denominator = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
	int nominator = denominator / lhs.m_denominator * lhs.m_nominator;
	nominator -= denominator / rhs.m_denominator * rhs.m_nominator;
	return Rational{ nominator, denominator };
}

export Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.m_nominator * rhs.m_nominator, rhs.m_denominator * lhs.m_denominator);
}

export Rational operator/(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.m_nominator * rhs.m_denominator,lhs.m_denominator * rhs.m_nominator);
}

export bool operator==(const Rational& lhs, const Rational& rhs)
{
	return lhs.m_nominator == rhs.m_nominator && lhs.m_denominator == rhs.m_denominator;
}

export bool operator>(const Rational& lhs, const Rational& rhs)
{
	int lcm = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
	return lcm / lhs.m_denominator * lhs.m_nominator > lcm / rhs.m_denominator * rhs.m_nominator;
}
export bool operator<(const Rational& lhs, const Rational& rhs)
{
	int lcm = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
	return lcm / lhs.m_denominator * lhs.m_nominator < lcm / rhs.m_denominator * rhs.m_nominator;
}
export bool operator>=(const Rational& lhs, const Rational& rhs)
{
	int lcm = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
	return lcm / lhs.m_denominator * lhs.m_nominator >= lcm / rhs.m_denominator * rhs.m_nominator;
}
export bool operator<=(const Rational& lhs, const Rational& rhs)
{
	int lcm = FindLeastCommonMultiple(lhs.m_denominator, rhs.m_denominator);
	return lcm / lhs.m_denominator * lhs.m_nominator <= lcm / rhs.m_denominator * rhs.m_nominator;
}

export std::ostream& operator<<(std::ostream& stream, const Rational& inst) {
	stream << inst.m_nominator << "/" << inst.m_denominator;
	return stream;
}

export Complex f(const Complex& u) {
	Complex a = Complex(1.0, 0.0);
	return a - pow(u, 5) - tanh(u / 2.0);
}

export Rational f(const Rational& r) {
	Rational a(1, 1);
	return a - pow(r, 5) - tanh(r / 2.0);
}

export double f(double x) {
	double a = 1.0;
	return a - pow(x, 5) - tanh(x / 2.0);
}
