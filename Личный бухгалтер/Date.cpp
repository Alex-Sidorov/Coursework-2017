#include "Date.h"

short int Date::get_day()const
{
	return _day;
}

short int Date::get_month()const
{
	return _month;
}

short int Date::get_year()const
{
	return _year;
}

void Date::set_day(short int day)
{
	_day = day;
}

void Date::set_month(short int month)
{
	_month = month;
}

void Date::set_year(short int year)
{
	_year = year;
}

std::ostream&operator<<(std::ostream &stream, Date &obj)
{
	stream << obj.get_day() << " " << obj.get_month() << " " << obj.get_year();
	return stream;
}

bool Date::operator < (Date &obj)
{
	if (_year > obj.get_year())
		return false;

	else if (_year < obj.get_year())
		return true;

	else if (_month > obj.get_month())
		return false;

	else if (_month < obj.get_month())
		return true;

	else if (_day > obj.get_day())
		return false;

	else if (_day < obj.get_day())
		return true;

	return false;
}

void Date::change_date(Date &obj)
{
	_day = obj._day;
	_month = obj._month;
	_year = obj._year;
}

Date::Date(const Date &obj)
{
	_day = obj._day;
	_month = obj._month;
	_year = obj._year;
}

Date::Date(short int day, short int month, short int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::~Date(){}