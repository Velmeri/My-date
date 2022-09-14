#pragma once
#include <iostream>

class Date
{
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day;
	int month;
	int year;
public:
	//constructors
	Date();
	Date(int d, int m, int y);

	//input
	void SetDay(int d);
	void SetMonth(int m);
	void SetYear(int y);

	//output
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void Print() const;

	//operators overloading
	void operator ++ ();
	void operator ++ (int);
	void operator -- ();
	void operator -- (int);

	void operator += (const int x);
	void operator -= (const int x);
	Date operator + (const int x);
	Date operator - (const int x);

	bool operator < (Date& obj) const;
	bool operator > (Date& obj) const;
	bool operator == (Date& obj) const;
	bool operator != (Date& obj) const;
	bool operator <= (Date& obj) const;
	bool operator >= (Date& obj) const;
};

