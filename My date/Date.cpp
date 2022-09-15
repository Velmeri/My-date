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

void Date::Print() const
{
	cout << day << '.' << month << '.' << year;
}

//operators overloading
void Date::operator++()
{
	if (year % 4)
		if (day == arr[month - 1]) {
			day = 1;
			if (month == 12) {
				month == 1;
				year++;
			}
			else {
				month++;
			}
		}
		else {
			day++;
		}
	else {
		if (month == 2)
			if (day == 29) {
				day = 1;
				month++;
			}
			else {
				day++;
			}
		else {
			day++;
		}
	}
}

void Date::operator++(int)
{
	if (year % 4)
		if (day == arr[month - 1]) {
			day = 1;
			if (month == 12) {
				month == 1;
				++year;
			}
			else {
				++month;
			}
		}
		else {
			++day;
		}
	else {
		if (month == 2)
			if (day == 29) {
				day = 1;
				++month;
			}
			else {
				++day;
			}
		else {
			if (day == arr[month - 1]) {
				day = 1;
				if (month == 12) {
					month == 1;
					++year;
				}
				else {
					++month;
				}
			}
			else {
				++day;
			}
		}
	}
}

void Date::operator--()
{
	if (day == 1) {
		if (year % 4) {
			if (month == 1) {
				month = 12;
				--year;
				day = arr[month - 1];
			}
			else
				day = arr[--month - 1];
		}
		else if (month == 3) {
			day = 29;
			--month;
		}
		else
			if (month == 1) {
				month = 12;
				--year;
				day = arr[month - 1];
			}
			else
				day = arr[--month - 1];
	}
	else
		--day;
}

void Date::operator--(int)
{
	if (day == 1) {
		if (year % 4) {
			if (month == 1) {
				month = 12;
				--year;
				day = arr[month - 1];
			}
			else
				day = arr[--month - 1];
		}
		else if (--month == 2)
			day = 29;
	}
	else
		--day;
}

void Date::operator+=(int x)
{
	day += x;
	for (int i = 0; day > arr[month - 1]; i++) {
		if (!(year % 4) && month == 2)
			break;
		day -= arr[month - 1];
		month == arr[month - 1];
		if (month == 1)
			++year;
	}
}

void Date::operator-=(int x)
{
	day -= x;
	for (int i = 0; day <= 0; i++) {
		day += !(year % 4) && month == 3 ? 29 : arr[--month - 1];
	}
}

Date Date::operator+(int x)
{
	day += x;
	for (int i = 0; day > arr[month - 1]; i++) {
		if (!(year % 4) && month == 2)
			break;
		day -= arr[month - 1];
		month == arr[month - 1];
		if (month == 1)
			++year;
	}
	return Date(day, month, year);
}

Date Date::operator-(int x)
{
	day -= x;
	for (int i = 0; day <= 0; i++) {
		day += !(year % 4) && month == 3 ? 29 : arr[--month - 1];
	}
	return Date(day, month, year);
}

bool Date::operator<(Date& obj) const
{
	if (year < obj.year)
		return 1;
	else if (year == obj.year && month < obj.month)
		return 1;
	else if (year == obj.year && month == obj.month && day < obj.day)
		return 1;
	return 0;
}

bool Date::operator>(Date& obj) const
{
	if (year > obj.year)
		return 1;
	else if (year == obj.year && month > obj.month)
		return 1;
	else if (year == obj.year && month == obj.month && day > obj.day)
		return 1;
	return 0;
}

bool Date::operator==(Date& obj) const
{
	if (year == obj.year && month == obj.month && day == obj.day)
		return 1;
	return 0;
}

bool Date::operator!=(Date& obj) const
{
	if (year == obj.year && month == obj.month && day == obj.day)
		return 0;
	return 1;
}

bool Date::operator<=(Date& obj) const
{
	if (year <= obj.year)
		if (year == obj.year && month <= obj.month)
			if (year == obj.year && month == obj.month && day <= obj.day)
				return 1;
	return 0;
}

bool Date::operator>=(Date& obj) const
{
	if (year >= obj.year)
		if (year == obj.year && month >= obj.month)
			if (year == obj.year && month == obj.month && day >= obj.day)
				return 1;
	return 0;
}

Date operator --(const Date& obj) {

}