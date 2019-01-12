#include "Debts.h"

short int Debts::get_day_repayment()const
{
	return get_day();
}

short int Debts::get_month_repayment()const
{
	return get_month();
}

short int Debts::get_year_repayment()const
{
	return get_year();
}

bool Debts::value_status()const
{
	return _status;
}

void Debts::change_value_status(bool new_status)
{
	_status = new_status;
}

void Debts::change_date_debt(Date &obj)
{
	change_date(obj);
}

void Debts::set_day_repayment(short int day)
{
	set_day(day);
}

void Debts::set_month_repayment(short int month)
{
	set_month(month);
}

void Debts::set_year_repayment(short int year)
{
	set_year(year);
}

float Debts::get_money_repayment()const
{
	return get_money();
}

void Debts::set_money_repayment(float money)
{
	set_money(money);
}

Debts::Debts(float money, short int day, short int month, short int year, std::string new_str) : Money(money), Date(day, month, year), Text(new_str)
{
	_status = false;
}

std::string Debts::get_name_debts()const
{
	return get_str();
}

void Debts::set_name_debts(std::string str)
{
	set_str(str);
}

bool Debts::operator==(const Debts &obj)const
{
	if (get_day() == obj.get_day() &&
		get_month() == obj.get_month() &&
		get_year() == obj.get_year() &&
		get_str() == obj.get_str() &&
		get_money() == obj.get_money())
		return true;
	else
		return false;
}

std::ostream & operator << (std::ostream &stream, Debts &obj)
{
	stream << obj.get_name_debts() << std::endl 
		<< obj.get_day_repayment() << " "
		<< obj.get_month_repayment() << " " 
		<< obj.get_year_repayment() << " "
		<< obj.get_money_repayment() << " " 
		<< obj.value_status() << std::endl;
	return stream;
}

Debts & Debts::operator=(const Debts &obj)
{
	set_money_repayment(obj.get_money_repayment());
	set_name_debts(obj.get_name_debts());

	set_day_repayment(obj.get_day_repayment());
	set_month_repayment(obj.get_month_repayment());
	set_year_repayment(obj.get_year_repayment());

	change_value_status(obj.value_status());

	return *this;
}

Debts::Debts(const Debts &obj)
{
	this->set_money_repayment(obj.get_money_repayment());
	this->set_name_debts(obj.get_name_debts());

	this->set_day_repayment(obj.get_day_repayment());
	this->set_month_repayment(obj.get_month_repayment());
	this->set_year_repayment(obj.get_year_repayment());

	this->change_value_status(obj.value_status());
}

Debts::Debts() : Money(), Date(), Text()
{
	_status = false;
}

Debts::~Debts()
{}