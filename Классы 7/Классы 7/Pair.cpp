#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator*(const Pair& t) 
{
	Pair p;
	p.first = first * t.first;
	p.second = (second * t.second);
	return p;
}
Pair& Pair::operator+(const int sum)
{
	first += sum;
	return *this;
}
Pair& Pair::operator+(const double sum)
{
	second += sum;
	return *this;
}
istream& operator>>(istream& in, Pair& t)
{
	setlocale(LC_ALL, "ru");
	cout << "������� ������ �����: ";
	in >> t.first;
	cout << "������� ������ ����� (�������): ";
	in >> t.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& t) 
{
	return (out << t.first << " : " << t.second);
}

