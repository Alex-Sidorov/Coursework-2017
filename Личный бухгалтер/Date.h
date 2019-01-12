#pragma once

#include <iostream>

class Date//класс даты
{
public:
	short int get_day()const;  //вернуть значение _day
	short int get_month()const;//вернуть значение _month
	short int get_year()const; //вернуть значение _year
	
	void set_day(short int day);    //изменить значение _day
	void set_month(short int month);//изменить значение _month
	void set_year(short int year);  //изменить значение _year

	void change_date(Date &obj);

	friend std::ostream & operator << (std::ostream &stream, Date &obj);
	bool operator < (Date &obj);

	Date(const Date &obj);
	Date(short int day, short int month, short int year);
	Date();	

	virtual ~Date();													      

private:
	short int _day;//день
	short int _month;//месяц
	short int _year;//год
};