#pragma once

#include "Date.h"
#include "Money.h"
#include "Text.h"
#include <iostream>

class Debts : private Date, private Money, private Text //класс долгов(долги и должники)
{
public:
	short int get_day_repayment()const;  //вернуть значение, указывающие на день погашения долга(_day)
	short int get_month_repayment()const;//вернуть значение, указывающие на месяц погашения долга(_month)
	short int get_year_repayment()const; //вернуть значение, указывающие на год погашения долга(_year)

	void set_day_repayment(short int day);     //изменить значение, указывающие на день погашения долга(_day)
	void set_month_repayment(short int month); //изменить значение, указывающие на месяц погашения долга(_month)
	void set_year_repayment(short int year);   //изменить значение d_year, указывающие на год погашения долга(_year)

	void change_date_debt(Date &obj);

	void set_money_repayment(float money);     //изменить сумму долга(_money)
	float get_money_repayment()const;          //вернуть значение, указывающие на сумму долга(_money)

	std::string get_name_debts()const;         //вернуть значение, указываюшие на имя должника или кредитора _str
	void set_name_debts(std::string str);      //изменить значение, указываюшие на имя должника или кредитора _str

	bool value_status()const;                  //вернуть статус долга(true-погашен, false-не погашен)
	void change_value_status(bool new_status); //изменить статус долга(true-погашен, false-не погашен)

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