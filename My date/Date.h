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
	int* GetArr();
	void Print() const;

	//other
	void SumDay(const int a);
	void SumMonth(const int a);
	void SumYear(const int a);

	//operators overloading
	//void operator ++ ();
	//void operator ++ (int);
	//void operator -- ();
	//void operator -- (int);

	//void operator += (const int x);
	//void operator -= (const int x);
	//Date operator + (const int x);
	//Date operator - (const int x);

	//bool operator < (Date& obj) const;
	//bool operator > (Date& obj) const;
	//bool operator == (Date& obj) const;
	//bool operator != (Date& obj) const;
	//bool operator <= (Date& obj) const;
	//bool operator >= (Date& obj) const;
};

Date operator-- (Date& obj);
Date operator-- (Date& obj, int);