#pragma once
#include <iostream>
using namespace std;

class Pair 
{
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; };
	Pair(int m, double s) { first = m; second = s; }
	Pair(const Pair& t) { first = t.first; second = t.second; }
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int m) { first = m; }
	void set_second(double s) { second = s; }
	Pair& operator*(const Pair&);
	Pair& operator+(const int);
	Pair& operator+(const double);
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
};

