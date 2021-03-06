#pragma once

#include "Money.h"
#include "Text.h"
#include "Date.h"
#include <string>
#include <iostream>

class Cost_or_Income :private Money, private Text, public Date // ����� �������� � �������
{
public:
	void change_money_cost_or_income(float money);   //�������� ����� ������� ��� ������
	void change_name_cost_or_income(std::string str);//�������� ������� ������� ��� ������

	float get_money_cost_or_income()const;           //������� ����� ������� ��� ������
	std::string get_name_cost_or_income()const;      //������� ������� ������� ��� ������

	Cost_or_Income & operator=(const Cost_or_Income &obj);

	bool operator==(const Cost_or_Income &obj)const;

	friend std::ostream & operator << (std::ostream &stream, Cost_or_Income &obj);

	Cost_or_Income();
	Cost_or_Income(float money, std::string str, short int day, short int month, short int year);
	Cost_or_Income(const Cost_or_Income &obj);
	
	virtual ~Cost_or_Income();
};