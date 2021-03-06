#pragma once

#include <iostream>

class Date//����� ����
{
public:
	short int get_day()const;  //������� �������� _day
	short int get_month()const;//������� �������� _month
	short int get_year()const; //������� �������� _year
	
	void set_day(short int day);    //�������� �������� _day
	void set_month(short int month);//�������� �������� _month
	void set_year(short int year);  //�������� �������� _year

	void change_date(Date &obj);

	friend std::ostream & operator << (std::ostream &stream, Date &obj);
	bool operator < (Date &obj);

	Date(const Date &obj);
	Date(short int day, short int month, short int year);
	Date();	

	virtual ~Date();													      

private:
	short int _day;//����
	short int _month;//�����
	short int _year;//���
};