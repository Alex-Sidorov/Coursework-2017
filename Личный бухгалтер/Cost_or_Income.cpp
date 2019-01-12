#include "Cost_or_Income.h"

void Cost_or_Income::change_money_cost_or_income(float money)
{
	set_money(money);
}

void Cost_or_Income::change_name_cost_or_income(std::string str)
{
	set_str(str);
}

float Cost_or_Income::get_money_cost_or_income()const
{
	return get_money();
}

std::string Cost_or_Income::get_name_cost_or_income()const
{
	return get_str();
}

Cost_or_Income & Cost_or_Income::operator=(const Cost_or_Income &obj)
{
	if(*this==obj)
		return *this;

	change_money_cost_or_income(obj.get_money_cost_or_income());
	change_name_cost_or_income(obj.get_name_cost_or_income());
	
	set_day(obj.get_day());
	set_month(obj.get_month());
	set_year(obj.get_year());

	return *this;
}

std::ostream & operator << (std::ostream &stream, Cost_or_Income &obj)
{
	stream << obj.get_name_cost_or_income() << std::endl << std::endl << obj.get_money_cost_or_income();
	return stream;
}

Cost_or_Income::Cost_or_Income(const Cost_or_Income& obj)
{
	this->change_money_cost_or_income(obj.get_money_cost_or_income());
	this->change_name_cost_or_income(obj.get_name_cost_or_income());
	this->set_day(obj.get_day());
	this->set_month(obj.get_month());
	this->set_year(obj.get_year());
}

bool Cost_or_Income::operator==(const Cost_or_Income &obj)const
{
	if (get_day() == obj.get_day() && 
		get_month() == obj.get_month() && 
		get_year() == obj.get_year() && 
		get_name_cost_or_income() == obj.get_name_cost_or_income() && 
		get_money_cost_or_income() == obj.get_money_cost_or_income())
		return true;
	else
		false;
}

Cost_or_Income::Cost_or_Income(float money, std::string new_str, short int day, short int month, short int year) 
	: Money(money), Text(new_str), Date(day, month, year)
{
}

Cost_or_Income::Cost_or_Income() 
	: Money(), Text()
{
}

Cost_or_Income::~Cost_or_Income()
{
}
