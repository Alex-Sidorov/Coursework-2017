#include "Record.h"

void Record::add_to_cost(float money, std::string name)
{
	_cost.push_back(Cost_or_Income(money, name, get_day(), get_month(), get_year()));
}

void Record::add_to_income(float money, std::string name)
{
	_income.push_back(Cost_or_Income(money, name, get_day(), get_month(), get_year()));
}

bool Record::delete_cost(int index_delete)
{
	return delete_cost_or_income(_cost, index_delete);
}

bool Record::delete_income(int index_delete)
{
	return delete_cost_or_income(_income, index_delete);
}

bool Record::delete_cost_or_income(std::vector<Cost_or_Income> vector, int index_delete)
{
	if (index_delete >= 0 && index_delete < vector.size())
	{
		vector.erase(vector.begin() + index_delete);
		return true;
	}
	else
		return false;
}

int Record::get_count_cost()const
{
	return _cost.size();
}

int Record::get_count_income()const
{
	return _income.size();
}

float Record::get_records_cost(int index)const
{
	return get_records_cost_or_income(_cost, index);
}

float Record::get_records_income(int index)const
{
	return get_records_cost_or_income(_income, index);
}

float Record::get_records_cost_or_income(std::vector<Cost_or_Income> vector, int index)const
{
	if (index >= 0 && index < vector.size())
		return vector[index].get_money_cost_or_income();
	else
		return -1;
}

const Cost_or_Income &Record::get_reference_cost(int index)const
{
	if (index >= 0 && index < _cost.size())
		return _cost[index];
}

const Cost_or_Income &Record::get_reference_income(int index)const
{
	if (index >= 0 && index < _income.size())
		return _income[index];
}

void Record::show_cost()const
{
	for (int i = 0; i < _cost.size(); i++)
		std::cout << std::endl << std::endl << i + 1 << "." 
		<< std::endl << "Куда: " << _cost[i].get_name_cost_or_income() 
		<< std::endl << "Сумма: " << _cost[i].get_money_cost_or_income()
		<< std::endl << "Дата: " << _cost[i].get_day() << "." 
		<< _cost[i].get_month() << "." << _cost[i].get_year() 
		<< std::endl << std::endl;
}

void Record::show_income()const
{
	for (int i = 0; i < _income.size(); i++)
		std::cout << std::endl << std::endl << i + 1 << "." 
		<< std::endl << "Откуда: " << _income[i].get_name_cost_or_income()
		<< std::endl << "Сумма: " << _income[i].get_money_cost_or_income()
		<< std::endl << "Дата: " << _income[i].get_day() << "." << _income[i].get_month()
		<< "." << _income[i].get_year() << std::endl << std::endl;
}

void Record::change_data_cost(int index, short int day, short int month, short int year)
{
	change_date(index, _cost, Date(day, month, year));
}

void Record::change_data_income(int index, short int day, short int month, short int year)
{
	change_date(index, _income, Date(day, month, year));
}

void Record::change_data_cost(int index, Date &obj)
{
	change_date(index, _cost, obj);
}

void Record::change_data_income(int index, Date &obj)
{
	change_date(index, _income, obj);
}

void Record::change_date(int index, std::vector<Cost_or_Income> vector, Date &obj)
{
	if (index < 0 || index >= vector.size())
		return;

	vector[index].set_day(obj.get_day());
	vector[index].set_month(obj.get_month());
	vector[index].set_year(obj.get_year());
}

void Record::change_money_cost(int index, float money)
{
	if (index < 0 || index >= _cost.size())
		return;

	_cost[index].change_money_cost_or_income(money);
}

void Record::change_money_income(int index, float money)
{
	if (index < 0 || index >= _income.size())
		return;

	_income[index].change_money_cost_or_income(money);
}

void Record::change_name_cost(int index, std::string name)
{
	if (index < 0 || index >= _cost.size())
		return;

	_cost[index].change_name_cost_or_income(name);
}

void Record::change_name_income(int index, std::string name)
{
	if (index < 0 || index >= _income.size())
		return;

	_income[index].change_name_cost_or_income(name);
}

std::ostream & operator << (std::ostream &stream, Record &obj)
{
	stream << obj.get_count_cost();
	stream << std::endl;

	stream << obj.get_count_income();
	stream << std::endl;

	stream << obj.get_day() << " " << obj.get_month() << " " << obj.get_year() << std::endl;
	for (int i = 0; i < obj.get_count_cost(); i++)
	{
		Cost_or_Income temp(obj.get_reference_cost(i));
		stream << temp << std::endl;
	}

	for (int i = 0; i < obj.get_count_income(); i++)
	{
		Cost_or_Income temp(obj.get_reference_income(i));
		stream << temp << std::endl;
	}

	return stream;
}

Record & Record::operator=(const Record &obj)
{
	this->set_day(obj.get_day());
	this->set_month(obj.get_month());
	this->set_year(obj.get_year());

	_cost = obj._cost;
	_income = obj._income;

	return *this;
}

Record::Record(const Record &obj)
{
	this->set_day(obj.get_day());
	this->set_month(obj.get_month());
	this->set_year(obj.get_year());

	_cost = obj._cost;
	_income = obj._income;
}

Record::Record() : Date()
{
}

Record::Record(short int day, short int month, short int year) : Date(day, month, year)
{
}

Record::~Record()
{
}