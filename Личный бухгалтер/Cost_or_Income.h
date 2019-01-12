#pragma once

#include "Money.h"
#include "Text.h"
#include "Date.h"
#include <string>
#include <iostream>

class Cost_or_Income :private Money, private Text, public Date // класс расходов и доходов
{
public:
	void change_money_cost_or_income(float money);   //изменить сумму расхода или дохода
	void change_name_cost_or_income(std::string str);//изменить причину расхода или дохода

	float get_money_cost_or_income()const;           //вернуть сумму расхода или дохода
	std::string get_name_cost_or_income()const;      //вернуть причину расхода или дохода

	Cost_or_Income & operator=(const Cost_or_Income &obj);

	bool operator==(const Cost_or_Income &obj)const;

	friend std::ostream & operator << (std::ostream &stream, Cost_or_Income &obj);

	Cost_or_Income();
	Cost_or_Income(float money, std::string str, short int day, short int month, short int year);
	Cost_or_Income(const Cost_or_Income &obj);
	
	virtual ~Cost_or_Income();
};