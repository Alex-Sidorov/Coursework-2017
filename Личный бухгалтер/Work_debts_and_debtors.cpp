#include "Work_debts_and_debtors.h"

int Work_debts_and_debtors::get_count_debts()const
{
	return _debts.size();
}

int Work_debts_and_debtors::get_count_debtors()const
{
	return _debtors.size();
}

Debts Work_debts_and_debtors::get_debt(int index)const
{
	if (index >= 0 && index<get_count_debts())
		return _debts[index];
}

Debts Work_debts_and_debtors::get_debtor(int index)const
{
	if (index >= 0 && index<get_count_debtors())
		return _debtors[index];
}

bool Work_debts_and_debtors::value_status_debts(int index)const
{
	if (index >= 0 && index < get_count_debts())
		return _debts[index].value_status();
	else
		return false;
}

bool Work_debts_and_debtors::value_status_debtors(int index)const
{
	if (index >= 0 && index < get_count_debtors())
		return _debtors[index].value_status();
	else
		return false;
}

void Work_debts_and_debtors::change_name_debt(int index, std::string name)
{
	if (index >= 0 && index < get_count_debts())
		_debts[index].set_name_debts(name);
}

void Work_debts_and_debtors::change_name_debtor(int index, std::string name)
{
	if (index >= 0 && index < get_count_debtors())
		_debtors[index].set_name_debts(name);
}

void Work_debts_and_debtors::change_money_debt(int index, float money)
{
	if (index >= 0 && index < get_count_debts())
		_debts[index].set_money_repayment(money);
}

void Work_debts_and_debtors::change_money_debtor(int index, float money)
{
	if (index >= 0 && index < get_count_debtors())
		_debtors[index].set_money_repayment(money);
}

void Work_debts_and_debtors::change_date_debt(int index, short int day, short int month, short int year)
{
	if (index < 0 && index >= get_count_debts())
		return;

	_debts[index].change_date_debt(Date(day, month, year));
}

void Work_debts_and_debtors::change_date_debtor(int index, short int day, short int month, short int year)
{
	if (index < 0 && index >= get_count_debtors())
		return;

	_debtors[index].change_date_debt(Date(day, month, year));
}

void Work_debts_and_debtors::change_date_debt(int index, Date &obj)
{
	if (index < 0 && index >= get_count_debts())
		return;

	_debts[index].change_date_debt(obj);
}

void Work_debts_and_debtors::change_date_debtor(int index, Date &obj)
{
	if (index < 0 && index >= get_count_debtors())
		return;

	_debtors[index].change_date_debt(obj);
}

void Work_debts_and_debtors::show_debts()const
{
	system("cls");
	for (int i = 0; i < _debts.size(); i++)
	{
		std::cout << i + 1 << "." << std::endl << "Кому: " << _debts[i].get_name_debts() << std::endl << "Сумма: " << _debts[i].get_money_repayment() << std::endl
			<< "Крайний срок погашения долга: " << _debts[i].get_day_repayment() << '.' << _debts[i].get_month_repayment() << '.' << _debts[i].get_year_repayment()
			<< std::endl << "Статус долга:";

		if (_debts[i].value_status() == true)
			std::cout << "Погашен." << std::endl << std::endl;
		else
			std::cout << "Не погашен." << std::endl << std::endl;
	}
}

void Work_debts_and_debtors::show_debtors()const
{
	for (int i = 0; i < _debtors.size(); i++)
	{
		std::cout << i + 1 << "." << std::endl << "Кто: " << _debtors[i].get_name_debts() << std::endl << "Сумма: " << _debtors[i].get_money_repayment() << std::endl
			<< "Крайний срок погашения долга: " << _debtors[i].get_day_repayment() << '.' << _debtors[i].get_month_repayment() << '.' << _debtors[i].get_year_repayment()
			<< std::endl << "Статус долга:";

		if (_debtors[i].value_status() == true)
			std::cout << "Погашен." << std::endl << std::endl;
		else
			std::cout << "Не погашен." << std::endl << std::endl;
	}

}

void Work_debts_and_debtors::add_debt(short int day, short int month, short int year, std::string name, float money)
{
	_debts.push_back(Debts(money, day, month, year, name));
}

bool Work_debts_and_debtors::delete_debt(short int day, short int month, short int year, std::string name, float money)
{
	short int index_delete = find_debts(day, month, year, name, money);
	if (index_delete != -1)
	{
		_debts.erase(_debts.begin() + index_delete);
		return true;
	}
	else
		return false;
}

bool Work_debts_and_debtors::delete_debt(int index)
{
	if (index >= 0 && index<_debts.size())
	{
		_debts.erase(_debts.begin() + index);
		return true;
	}
	else
		return false;
}

bool Work_debts_and_debtors::delete_debtor(int index)
{
	if (index >= 0 && index<_debtors.size())
	{
		_debtors.erase(_debtors.begin() + index);
		return true;
	}
	else
		return false;
}

void Work_debts_and_debtors::add_debtor(short int day, short int month, short int year, std::string name, float money)
{
	_debtors.push_back(Debts(money, day, month, year, name));
}

bool Work_debts_and_debtors::delete_debtor(short int day, short int month, short int year, std::string name, float money)
{
	short int index_delete = find_debtors(day, month, year, name, money);
	if (index_delete != -1)
	{
		_debtors.erase(_debtors.begin() + index_delete);
		return true;
	}
	else
		return false;
}

int Work_debts_and_debtors::find_debts(short int day, short int month, short int year, std::string name, float money)const
{
	for (int index_delete = 0; index_delete < _debts.size(); index_delete++)
	{
		if (_debts[index_delete] == Debts(money, day, month, year, name))
			return index_delete;
	}

	return -1;
}

int Work_debts_and_debtors::find_debtors(short int day, short int month, short int year, std::string name, float money)const
{
	for (int index_delete = 0; index_delete < _debtors.size(); index_delete++)
	{
		if (_debtors[index_delete] == Debts(money, day, month, year, name))
			return index_delete;
	}

	return -1;
}

bool Work_debts_and_debtors::change_status_debt(bool new_status, short int day, short int month, short int year, std::string name, float money)
{
	int index = find_debts(day, month, year, name, money);
	if (index != -1)
	{
		_debts[index].change_value_status(new_status);
		return true;
	}
	else
		return false;
}

bool Work_debts_and_debtors::change_status_debt(int index, bool new_status)
{
	if (index >= 0 && index<_debts.size())
	{
		_debts[index].change_value_status(new_status);
		return true;
	}
	else
		return false;
}

bool Work_debts_and_debtors::change_status_debtor(int index, bool new_status)
{
	if (index >= 0 && index<_debtors.size())
	{
		_debtors[index].change_value_status(new_status);
		return true;
	}
	else
		return false;
}

bool Work_debts_and_debtors::change_status_debtor(bool new_status, short int day, short int month, short int year, std::string name, float money)
{
	int index = find_debts(day, month, year, name, money);
	if (index != -1)
	{
		_debtors[index].change_value_status(new_status);
		return true;
	}
	else
		return false;
}

void Work_debts_and_debtors::read_debt(std::fstream &file, std::vector<Debts> &vector)
{
	int count_debts = 0;
	int day = 0;
	int month = 0;
	int year = 0;
	float money = 0;
	bool status = false;
	std::string name;

	file >> count_debts;
	for (int i = 0; i < count_debts; i++)
	{
		std::getline(file, name);
		std::getline(file, name);
		file >> day;
		file >> month;
		file >> year;
		file >> money;
		file >> status;
		vector.push_back(Debts(money, day, month, year, name));
		vector[i].change_value_status(status);
	}
}

void Work_debts_and_debtors::write_debt(std::fstream &_file, std::vector<Debts> &vector)
{
	_file << vector.size();
	_file << std::endl;

	for (int i = 0; i < vector.size(); i++)
		_file << vector[i];
}

void Work_debts_and_debtors::write_debts(std::fstream &file)
{
	write_debt(file, _debts);
}

void Work_debts_and_debtors::write_debtors(std::fstream &file)
{
	write_debt(file, _debtors);
}

void Work_debts_and_debtors::read_debts(std::fstream &_file)
{
	read_debt(_file, _debts);
}

void Work_debts_and_debtors::read_debtors(std::fstream &_file)
{
	read_debt(_file, _debtors);
}

Work_debts_and_debtors::Work_debts_and_debtors()
{
}

Work_debts_and_debtors::~Work_debts_and_debtors()
{
}
