#include "Date.h"

using namespace std;

//constructors
Date::Date()
{
	day = month = year = 1;
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	if (month < 1)
		month = 1;
	else if (month > 12)
		month = 12;
	if (day < 1)
		day = 1;
	else if (day > arr[month] && !(year % 4) && month == 2)
		day = 19;
	else if (day > arr[month])
		day = arr[month];
}

//input
void Date::SetDay(int d)
{
	day = d;
}

void Date::SetMonth(int m)
{
	month = m;
}

void Date::SetYear(int y)
{
	year = y;
}

//output
int Date::GetDay() const
{
	return day;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetYear() const
{
	return year;
}

int* Date::GetArr()
{
	return arr;
}

void Date::Print() const
{
	cout << day << '.' << month << '.' << year;
}

void Date::SumDay(const int a)
{
	day += a;
}

void Date::SumMonth(const int a)
{
	month += a;
}

void Date::SumYear(const int a)
{
	year += a;
}

Date operator--(Date& obj)
{
	if (obj.GetDay() == 1) {
		if (obj.GetYear() % 4) {
			if (obj.GetMonth() == 1) {
				obj.SetMonth(12);
				obj.SumYear(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
			else {
				obj.SumMonth(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
		}
		else if (obj.GetMonth() == 3) {
			obj.SetDay(29);
			obj.SumMonth(-1);
		}
		else
			if (obj.GetMonth() == 1) {
				obj.SetMonth(12);
				obj.SumYear(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
			else {
				obj.SetMonth(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
	}
	else
		obj.SumDay(-1);
	return obj;
}

Date operator--(Date& obj, int)
{
	if (obj.GetDay() == 1) {
		if (obj.GetYear() % 4) {
			if (obj.GetMonth() == 1) {
				obj.SetMonth(12);
				obj.SumYear(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
			else {
				obj.SumMonth(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
		}
		else if (obj.GetMonth() == 3) {
			obj.SetDay(29);
			obj.SumMonth(-1);
		}
		else
			if (obj.GetMonth() == 1) {
				obj.SetMonth(12);
				obj.SumYear(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
			else {
				obj.SetMonth(-1);
				obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
			}
	}
	else
		obj.SumDay(-1);
	return obj;
}

Date operator++(Date& obj)
{
	if (obj.GetYear() % 4)
		if (obj.GetDay() == obj.GetArr()[obj.GetMonth() - 1]) {
			obj.SetDay(1);
			if (obj.GetMonth() == 12) {
				obj.SetMonth(1);
				obj.SumYear(1);
			}
			else {
				obj.SumMonth(1);
			}
		}
		else {
			obj.SumDay(1);
		}
	else {
		if (obj.GetMonth() == 2)
			if (obj.GetDay() == 29) {
				obj.SetDay(1);
				obj.SumMonth(1);
			}
			else {
				obj.SumDay(1);
			}
		else {
			obj.SetDay(1);
		}
	}
}

Date operator++(Date& obj, int)
{
	if (obj.GetYear() % 4)
		if (obj.GetDay() == obj.GetArr()[obj.GetMonth() - 1]) {
			obj.SetDay(1);
			if (obj.GetMonth() == 12) {
				obj.SetMonth(1);
				obj.SumYear(1);
			}
			else {
				obj.SumMonth(1);
			}
		}
		else {
			obj.SumDay(1);
		}
	else {
		if (obj.GetMonth() == 2)
			if (obj.GetDay() == 29) {
				obj.SetDay(1);
				obj.SumMonth(1);
			}
			else {
				obj.SumDay(1);
			}
		else {
			obj.SetDay(1);
		}
	}
}

Date operator-=(Date& obj, int a)
{
	obj.SumDay(-a);
	for (int i = 0; obj.GetDay() <= 0; i++) {
		//day += !(year % 4) && month == 3 ? 29 : arr[--month - 1];
		if (!(obj.GetYear() % 4) && obj.GetMonth() == 3)
			obj.SetDay(29);
		else {
			obj.SumMonth(-1);
			obj.SetDay(obj.GetArr()[obj.GetMonth() - 1]);
		}
	}
}

Date operator+=(Date& obj, int a)
{
	obj.SumDay(a);
	for (int i = 0; obj.GetDay() > obj.GetArr()[obj.GetMonth() - 1]; i++) {
		if (!(obj.GetYear() % 4) && obj.GetMonth() == 2)
			break;
		obj.SumDay(obj.GetArr()[obj.GetMonth() - 1]);
		obj.SetMonth(obj.GetArr()[obj.GetMonth() - 1]);
		if (obj.GetMonth() == 1)
			obj.SumYear(1);
	}
}

bool operator<(Date& objL, Date& objR)
{
	if (objL.GetYear() < objR.GetYear())
		return 1;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() < objR.GetMonth())
		return 1;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() == objR.GetMonth() && objL.GetDay() > objR.GetDay())
		return 1;
	return 0;
}

bool operator>(Date& objL, Date& objR)
{
	if (objL.GetYear() < objR.GetYear())
		return 0;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() < objR.GetMonth())
		return 0;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() == objR.GetMonth() && objL.GetDay() > objR.GetDay())
		return 0;
	return 1;
}

bool operator<=(Date& objL, Date& objR)
{
	if (objL.GetYear() <= objR.GetYear())
		return 1;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() <= objR.GetMonth())
		return 1;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() == objR.GetMonth() && objL.GetDay() >= objR.GetDay())
		return 1;
	return 0;
}

bool operator>=(Date& objL, Date& objR)
{
	if (objL.GetYear() <= objR.GetYear())
		return 0;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() <= objR.GetMonth())
		return 0;
	else if (objL.GetYear() == objR.GetYear() && objL.GetMonth() == objR.GetMonth() && objL.GetDay() >= objR.GetDay())
		return 0;
	return 1;
}

bool operator==(const Date& objL, const Date& objR)
{
	if (objL.GetYear() == objR.GetYear() && objL.GetMonth() == objR.GetMonth() && objL.GetDay() == objR.GetDay())
		return 1;
	return 0;
}

bool operator!=(const Date& objL, const Date& objR)
{
	if (objL.GetYear() == objR.GetYear() && objL.GetMonth() == objR.GetMonth() && objL.GetDay() == objR.GetDay())
		return 0;
	return 1;
}
