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

//operators overloading
//void Date::operator++()
//{
//	if (year % 4)
//		if (day == arr[month - 1]) {
//			day = 1;
//			if (month == 12) {
//				month == 1;
//				year++;
//			}
//			else {
//				month++;
//			}
//		}
//		else {
//			day++;
//		}
//	else {
//		if (month == 2)
//			if (day == 29) {
//				day = 1;
//				month++;
//			}
//			else {
//				day++;
//			}
//		else {
//			day++;
//		}
//	}
//}
//
//void Date::operator++(int)
//{
//	if (year % 4)
//		if (day == arr[month - 1]) {
//			day = 1;
//			if (month == 12) {
//				month == 1;
//				++year;
//			}
//			else {
//				++month;
//			}
//		}
//		else {
//			++day;
//		}
//	else {
//		if (month == 2)
//			if (day == 29) {
//				day = 1;
//				++month;
//			}
//			else {
//				++day;
//			}
//		else {
//			if (day == arr[month - 1]) {
//				day = 1;
//				if (month == 12) {
//					month == 1;
//					++year;
//				}
//				else {
//					++month;
//				}
//			}
//			else {
//				++day;
//			}
//		}
//	}
//}
//
//void Date::operator--()
//{
//	if (day == 1) {
//		if (year % 4) {
//			if (month == 1) {
//				month = 12;
//				--year;
//				day = arr[month - 1];
//			}
//			else
//				day = arr[--month - 1];
//		}
//		else if (month == 3) {
//			day = 29;
//			--month;
//		}
//		else
//			if (month == 1) {
//				month = 12;
//				--year;
//				day = arr[month - 1];
//			}
//			else
//				day = arr[--month - 1];
//	}
//	else
//		--day;
//}
//
//void Date::operator--(int)
//{
//	if (day == 1) {
//		if (year % 4) {
//			if (month == 1) {
//				month = 12;
//				--year;
//				day = arr[month - 1];
//			}
//			else
//				day = arr[--month - 1];
//		}
//		else if (--month == 2)
//			day = 29;
//	}
//	else
//		--day;
//}
//
//void Date::operator+=(int x)
//{
//	day += x;
//	for (int i = 0; day > arr[month - 1]; i++) {
//		if (!(year % 4) && month == 2)
//			break;
//		day -= arr[month - 1];
//		month == arr[month - 1];
//		if (month == 1)
//			++year;
//	}
//}
//
//void Date::operator-=(int x)
//{
//	day -= x;
//	for (int i = 0; day <= 0; i++) {
//		day += !(year % 4) && month == 3 ? 29 : arr[--month - 1];
//	}
//}
//
//Date Date::operator+(int x)
//{
//	day += x;
//	for (int i = 0; day > arr[month - 1]; i++) {
//		if (!(year % 4) && month == 2)
//			break;
//		day -= arr[month - 1];
//		month == arr[month - 1];
//		if (month == 1)
//			++year;
//	}
//	return Date(day, month, year);
//}
//
//Date Date::operator-(int x)
//{
//	day -= x;
//	for (int i = 0; day <= 0; i++) {
//		day += !(year % 4) && month == 3 ? 29 : arr[--month - 1];
//	}
//	return Date(day, month, year);
//}
//
//bool Date::operator<(Date& obj) const
//{
//	if (year < obj.year)
//		return 1;
//	else if (year == obj.year && month < obj.month)
//		return 1;
//	else if (year == obj.year && month == obj.month && day < obj.day)
//		return 1;
//	return 0;
//}
//
//bool Date::operator>(Date& obj) const
//{
//	if (year > obj.year)
//		return 1;
//	else if (year == obj.year && month > obj.month)
//		return 1;
//	else if (year == obj.year && month == obj.month && day > obj.day)
//		return 1;
//	return 0;
//}
//
//bool Date::operator==(Date& obj) const
//{
//	if (year == obj.year && month == obj.month && day == obj.day)
//		return 1;
//	return 0;
//}
//
//bool Date::operator!=(Date& obj) const
//{
//	if (year == obj.year && month == obj.month && day == obj.day)
//		return 0;
//	return 1;
//}
//
//bool Date::operator<=(Date& obj) const
//{
//	if (year <= obj.year)
//		if (year == obj.year && month <= obj.month)
//			if (year == obj.year && month == obj.month && day <= obj.day)
//				return 1;
//	return 0;
//}
//
//bool Date::operator>=(Date& obj) const
//{
//	if (year >= obj.year)
//		if (year == obj.year && month >= obj.month)
//			if (year == obj.year && month == obj.month && day >= obj.day)
//				return 1;
//	return 0;
//}

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
