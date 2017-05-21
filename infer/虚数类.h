/*-------------------------------------
利用getconjugate(a)来获得a的复共轭
利用swap(a,b)来交换两个虚数的值
--------------------------------------*/
#ifndef _IMAGE
#define _IMAGE
#include<iostream>
class imag{
	double real, vir;
public:
	//构造函数
	imag() = default;
	imag(double _real, double _vir) :real(_real), vir(_vir) {};
	imag(const imag& _a) :real(_a.real), vir(_a.vir) {};

	//友元
	friend void swap(imag&, imag&);
	friend void print(const imag&);
	friend imag&& getconjugate(const imag&);

	friend imag operator+(const imag&, const imag&);
	friend imag operator-(const imag&, const imag&);
	friend imag operator*(const imag&, const imag&);
	friend imag operator/(const imag&, const imag&);
	friend bool operator==(const imag&, const imag&);
	friend bool operator!=(const imag&, const imag&);
	friend std::ostream& operator<<(std::ostream &a,const imag&);
	friend std::istream& operator>>(std::istream &a, imag&);

	//复合赋值运算符
	void operator=(const imag& a) {
		this->real = a.real;
		this->vir = a.vir;
	}
	void operator+=(const imag& a) {
		this->real += a.real;
		this->vir += a.vir;
	}
	void operator-=(const imag& a) {
		this->real -= a.real;
		this->vir -= a.vir;
	}
	void operator*=(const imag& a) {
		imag temp;
		temp.real = this->real*(a.real) - this->vir*(a.vir);
		temp.vir = this->real*(a.vir) + this->vir*(a.real);
		swap(*this, temp);
	}
	void operator/=(const imag& a) {
		double temp1 = a.real*(a.real) + a.vir*(a.vir);
		imag temp2 = *this * getconjugate(a);
		this->real = temp2.real / temp1;
		this->vir = temp2.vir / temp1;
	}

};


void swap(imag&a, imag&b) {
	imag temp(a);
	a = b;
	b = temp;}

void print(const imag&a) {
	std::cout << a.real << " " << a.vir << "i";}

imag&& getconjugate(const imag& a) {
	imag temp(a);
	temp.vir = -temp.vir;
	return temp;};


imag operator+(const imag& a, const imag& b) {
	imag temp(a); temp += b;
	return temp;}
imag operator-(const imag& a, const imag& b) {
	imag temp(a);
	temp -= b;
	return temp;}
imag operator*(const imag& a, const imag& b) {
	imag temp(a);
	temp *= b;
	return temp;}
imag operator/(const imag& a, const imag& b) {
	imag temp(a);
	temp /= b;
	return temp;}
bool operator==(const imag&a, const imag&b) {
	return a.real == b.real && a.vir == b.vir;}
bool operator!=(const imag&a, const imag&b) {
	return !(a == b);}

inline std::ostream & operator<<(std::ostream & os, const imag &a){
	os<< a.real << " " << a.vir << "i";
	return os;}
inline std::istream & operator >> (std::istream & in, imag &a){
	in >> a.real >> a.vir;
	return in;}
#endif