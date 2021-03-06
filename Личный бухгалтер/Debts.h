#pragma once

#include "Date.h"
#include "Money.h"
#include "Text.h"
#include <iostream>

class Debts : private Date, private Money, private Text //����� ������(����� � ��������)
{
public:
	short int get_day_repayment()const;  //������� ��������, ����������� �� ���� ��������� �����(_day)
	short int get_month_repayment()const;//������� ��������, ����������� �� ����� ��������� �����(_month)
	short int get_year_repayment()const; //������� ��������, ����������� �� ��� ��������� �����(_year)

	void set_day_repayment(short int day);     //�������� ��������, ����������� �� ���� ��������� �����(_day)
	void set_month_repayment(short int month); //�������� ��������, ����������� �� ����� ��������� �����(_month)
	void set_year_repayment(short int year);   //�������� �������� d_year, ����������� �� ��� ��������� �����(_year)

	void change_date_debt(Date &obj);

	void set_money_repayment(float money);     //�������� ����� �����(_money)
	float get_money_repayment()const;          //������� ��������, ����������� �� ����� �����(_money)

	std::string get_name_debts()const;         //������� ��������, ����������� �� ��� �������� ��� ��������� _str
	void set_name_debts(std::string str);      //�������� ��������, ����������� �� ��� �������� ��� ��������� _str

	bool value_status()const;                  //������� ������ �����(true-�������, false-�� �������)
	void change_value_status(bool new_status); //�������� ������ �����(true-�������, false-�� �������)

	friend std::ostream & operator << (std::ostream &stream, Debts &obj);
	Debts & operator=(const Debts &obj);
	bool operator==(const Debts &obj)const;

	Debts();
	Debts(float money, short int day, short int month, short int year, std::string new_str);
	Debts(const Debts &obj);

	virtual ~Debts();

private:
	bool _status;
};