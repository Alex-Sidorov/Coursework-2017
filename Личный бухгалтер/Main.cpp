#include "Main.h"

float Main::get_cash_flow()const
{
	return _cash_flow.get_money();
}

int Main::get_count_history_cost()const
{
	return _history_cost.size();
}

int Main::get_count_history_income()const
{
	return _history_income.size();
}

void Main::set_cash_flow(float money)
{
	return _cash_flow.set_money(money);
}

void Main::change_date_record(int index, short int day, short int month, short int year)
{
	if (index < 0 && index >= get_count_records())
		return;

	Record temp = _records[index];

	delete_record(index);

	add_record(day, month, year);

	int index_record = find_record(Date(day, month, year));

	for (int i = 0; i < temp.get_count_cost();i++)
	{
		add_cost_in_record(day, month, year, temp.get_reference_cost(i).get_name_cost_or_income(), temp.get_reference_cost(i).get_money_cost_or_income());
	}
	for (int i = 0; i < temp.get_count_income();i++)
	{
		add_income_in_record(day, month, year, temp.get_reference_cost(i).get_name_cost_or_income(), temp.get_reference_cost(i).get_money_cost_or_income());
	}
}

void Main::change_money_cost(int index_one, int index_two, float money)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_cost(index_one))
		return;

	_records[index_one].change_money_cost(index_two, money);
}

void Main::change_money_income(int index_one, int index_two, float money)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_income(index_one))
		return;

	_records[index_one].change_money_income(index_two, money);
}

void Main::change_data_cost(int index_one, int index_two, short int day, short int month, short int year)//
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_cost(index_one))
		return;

	Cost_or_Income temp = _records[index_one].get_reference_cost(index_two);

	temp.change_date(Date(day, month, year));
	delete_cost_in_record(index_one, index_two);
	add_cost_in_record(temp);
}

void Main::change_data_income(int index_one, int index_two, short int day, short int month, short int year)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_income(index_one))
		return;

	Cost_or_Income temp = _records[index_one].get_reference_income(index_two);
	temp.change_date(Date(day, month, year));
	delete_income_in_record(index_one, index_two);
	add_income_in_record(temp);
}

void Main::change_name_cost(int index_one, int index_two, std::string name)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_cost(index_one))
		return;

	_records[index_one].change_name_cost(index_two, name);
}

void Main::change_name_income(int index_one, int index_two, std::string name)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_income(index_one))
		return;

	_records[index_one].change_name_income(index_two, name);
}

float Main::get_record_money_cost(int index_one, int index_two)const
{
	if (index_one < 0 && index_one >= get_count_records())
		return -1;

	if (index_two < 0 && index_two >= get_count_cost(index_one))
		return -1;

	return _records[index_one].get_records_cost(index_two);
}

float Main::get_record_money_income(int index_one, int index_two)const
{
	if (index_one < 0 && index_one >= get_count_records())
		return -1;

	if (index_two < 0 && index_two >= get_count_income(index_one))
		return -1;

	return _records[index_one].get_records_income(index_two);
}

int Main::get_count_records()const
{
	return _records.size();
}

int Main::get_count_cost(int index)const
{
	if (index < 0 && index >= get_count_records())
		return -1;

	return _records[index].get_count_cost();
}

int Main::get_count_income(int index)const
{
	if (index < 0 && index >= get_count_records())
		return -1;

	return _records[index].get_count_income();
}

Cost_or_Income Main::get_cost(int index_one, int index_two)const
{
	if (index_one > 0 && index_one < get_count_records() && index_two > 0 && index_two < get_count_cost(index_one))
		return _records[index_one].get_reference_cost(index_two);
}

Cost_or_Income Main::get_income(int index_one, int index_two)const
{
	if (index_one > 0 && index_one < get_count_records() && index_two > 0 && index_two < get_count_income(index_one))
		return _records[index_one].get_reference_income(index_two);
}

void Main::delete_cost_in_record(int index_one, int index_two)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_cost(index_one))
		return;

	int index_history = find_history_cost(_records[index_one].get_reference_cost(index_two));
	_history_cost.erase(_history_cost.begin() + index_history);
	_records[index_one].delete_cost(index_two);
}

void Main::delete_income_in_record(int index_one, int index_two)
{
	if (index_one < 0 && index_one >= get_count_records())
		return;

	if (index_two < 0 && index_two >= get_count_income(index_one))
		return;

	int index_history = find_history_income(_records[index_one].get_reference_income(index_two));
	_history_income.erase(_history_income.begin() + index_history);
	_records[index_one].delete_income(index_two);
}

bool Main::delete_record(short int day, short int month, short int year)
{
	short int index = find_record(Date(day, month, year));

	int index_history = 0;

	if (index >= 0 && index<_records.size())
	{
		for (int i = 0; i < _records[index].get_count_cost(); i++)
		{
			index_history = find_history_cost(_records[index].get_reference_cost(i));
			_history_cost.erase(_history_cost.begin() + index_history);
		}
		for (int i = 0; i < _records[index].get_count_income(); i++)
		{
			index_history = find_history_income(_records[index].get_reference_income(i));
			_history_income.erase(_history_income.begin() + index_history);
		}
		_records.erase(_records.begin() + index);
		return true;
	}
	else
		return false;
}

bool Main::delete_record(int index)
{
	int index_history = 0;

	if (index >=0 && index<_records.size())
	{
		for (int i = 0; i < _records[index].get_count_cost(); i++)
		{
			index_history = find_history_cost(_records[index].get_reference_cost(i));
			_history_cost.erase(_history_cost.begin() + index_history);
		}

		for (int i = 0; i < _records[index].get_count_income(); i++)
		{
			index_history = find_history_income(_records[index].get_reference_income(i));
			_history_income.erase(_history_income.begin() + index_history);
		}
		_records.erase(_records.begin() + index);
		return true;
	}
	else
		return false;
}

void Main::show_records()const
{
	for (int i = 0; i < _records.size(); i++)
		std::cout << i + 1 <<"."<< std::endl << "Запись за " << _records[i].get_day() << '.' << _records[i].get_month() << '.' << _records[i].get_year() << std::endl;
}

void Main::show_history_cost()const
{
	for (int i = 0; i < _history_cost.size(); i++)
		std::cout << i + 1 << "." << std::endl << "Куда: " << _history_cost[i].get_name_cost_or_income() << std::endl << "Сумма: " << _history_cost[i].get_money_cost_or_income()
		<< std::endl << "Дата: " << _history_cost[i].get_day() << "." << _history_cost[i].get_month() << "." << _history_cost[i].get_year() << std::endl << std::endl;
}

void Main::show_history_income()const
{
	for (int i = 0; i < _history_income.size(); i++)
		std::cout << i + 1 << "." << std::endl << "Откуда: " << _history_income[i].get_name_cost_or_income() << std::endl << "Сумма: " << _history_income[i].get_money_cost_or_income()
		<< std::endl << "Дата: " << _history_income[i].get_day() << "." << _history_income[i].get_month() << "." << _history_income[i].get_year() << std::endl << std::endl;
}

void Main::show_cost(int index)const
{
	if (index >= 0 && index < _records.size())
		_records[index].show_cost();
}

void Main::show_income(int index)const
{
	if (index >= 0 && index < _records.size())
		_records[index].show_income();
}

float Main::currency_converter(float cash, float course)const
{
	return cash*course;
}

int Main::find_record(Date &obj)const
{
	for (int index_delete = 0; index_delete < _records.size(); index_delete++)
	{
		if (_records[index_delete].get_day() == obj.get_day() && _records[index_delete].get_month() == obj.get_month() && _records[index_delete].get_year() == obj.get_year())
			return index_delete;
	}

	return -1;
}

void Main::add_record(short int day, short int month, short int year)
{
	if (check_insert_date(day, month, year) == false) return;

	int index_insert = find_place_insert_record(day, month, year);
	_records.insert(_records.begin() + index_insert, Record(day, month, year));
}

int Main::find_place_insert_record(short int day, short int month, short int year)const
{
	return find_place_insert(_records, Date(day, month, year));
}

int Main::find_place_insert_in_history_cost(short int day, short int month, short int year)const
{
	return find_place_insert(_history_cost, Date(day, month, year));
}

int Main::find_place_insert_in_history_income(short int day, short int month, short int year)const
{
	return find_place_insert(_history_income, Date(day, month, year));
}

void Main::add_cost_in_record(short int day, short int month, short int year, std::string name, float money)
{
	int index = find_record(Date(day,month, year));
	
	if (index == -1)
		add_record(day, month, year);

	index = find_record(Date(day, month, year));
		
	_records[index].add_to_cost(money, name);

	int index_insert_history = find_place_insert_in_history_cost(day, month, year);

	_history_cost.insert((_history_cost.begin() + index_insert_history), Cost_or_Income(money, name, day, month, year));//
}

void Main::add_income_in_record(short int day, short int month, short int year, std::string name, float money)
{
	int index = find_record(Date(day, month, year));

	if (index == -1)
		add_record(day, month, year);

	index = find_record(Date(day, month, year));

	_records[index].add_to_income(money, name);

	int index_insert_history = find_place_insert_in_history_income(day, month, year);

	_history_income.insert((_history_income.begin() + index_insert_history), Cost_or_Income(money, name, day, month, year));//
}

void Main::add_cost_in_record(const Cost_or_Income &obj)
{
	int index = find_record(Date(obj.get_day(), obj.get_month(), obj.get_year()));

	if (index == -1)
		add_record(obj.get_day(), obj.get_month(), obj.get_year());

	index = find_record(Date(obj.get_day(), obj.get_month(), obj.get_year()));

	_records[index].add_to_cost(obj.get_money_cost_or_income(), obj.get_name_cost_or_income());

	int index_insert_history = find_place_insert_in_history_cost(obj.get_day(), obj.get_month(), obj.get_year());

	_history_cost.insert((_history_cost.begin() + index_insert_history), obj);
}

void Main::add_income_in_record(const Cost_or_Income &obj)
{
	int index = find_record(Date(obj.get_day(), obj.get_month(), obj.get_year()));

	if (index == -1)
		add_record(obj.get_day(), obj.get_month(), obj.get_year());

	index = find_record(Date(obj.get_day(), obj.get_month(), obj.get_year()));

	_records[index].add_to_income(obj.get_money_cost_or_income(), obj.get_name_cost_or_income());

	int index_insert_history = find_place_insert_in_history_income(obj.get_day(), obj.get_month(), obj.get_year());

	_history_income.insert((_history_income.begin() + index_insert_history), Cost_or_Income(obj));//
}

bool Main::check_insert_date(short int day, short int month, short int year)const
{
	for (int i = 0; i < _records.size(); i++)
	{
		if (_records[i].get_day() == day && _records[i].get_month() == month && _records[i].get_year() == year)
			return false;
	}
	return true;
}

int Main::find_history_cost(const Cost_or_Income &obj)const
{
	for (int index = 0; index < _history_cost.size(); index++)
	{
		if (_history_cost[index] == obj)
			return index;
	}
	return -1;
}

int Main::find_history_income(const Cost_or_Income &obj)const
{
	for (int index = 0; index < _history_income.size(); index++)
	{
		if (_history_income[index] == obj)
			return index;
	}
	return -1;
}

float Main::average_cost(short int day_from, short int month_from, short int year_from, short int day_to, short int month_to, short int year_to)const/////////
{
	if (_history_cost.size() == 0 || Date(day_to, month_to, year_to) < Date(day_from, month_from, year_from))
		return 0;

	int index_from = find_place_insert_in_history_cost(day_from, month_from, year_from);
	int index_to = find_place_insert_in_history_cost(day_to, month_to, year_to);

	if (Date(day_to, month_to, year_to)< Date(_history_cost[0].get_day(), _history_cost[0].get_month(), _history_cost[0].get_year()))
		return 0;

	int step = 0;
	float summa = 0;

	for (int i = index_from; i <= index_to && i<_history_cost.size(); i++)
	{
		summa += _history_cost[i].get_money_cost_or_income();
		step++;
	}

	if (summa == 0)
		return 0;
	else
		return summa / step;
}

float Main::average_income(short int day_from, short int month_from, short int year_from, short int day_to, short int month_to, short int year_to)const//////////
{
	if (_history_income.size() == 0 || Date(day_to, month_to, year_to) < Date(day_from, month_from, year_from))
		return 0;

	int index_from = find_place_insert_in_history_income(day_from, month_from, year_from);
	int index_to = find_place_insert_in_history_income(day_to, month_to, year_to);

	if (Date(day_to, month_to, year_to) < Date(_history_income[0].get_day(), _history_income[0].get_month(), _history_income[0].get_year()))
			return 0;

	int step = 0;
	float summa = 0;

	for (int i = index_from; i <= index_to && i<_history_income.size(); i++)
	{
		summa += _history_income[i].get_money_cost_or_income();
		step++;
	}

	if (summa == 0)
		return 0;
	else
		return summa / step;
}

void Main::write_file()
{
	write_debts(_file);

	write_debtors(_file);

	_file << _records.size();
	_file << std::endl;
	
	for (int i = 0; i < _records.size(); i++)
		_file << _records[i];

	_file << _cash_flow;
}

void Main::read_records()
{
	int count_records = 0;
	int count_cost = 0;
	int count_income = 0;
	int day = 0;
	int month = 0;
	int year = 0;

	_file >> count_records;

	for (int i = 0; i < count_records; i++)
	{
		_file >> count_cost;
		_file >> count_income;

		_file >> day;
		_file >> month;
		_file >> year;

		_records.push_back(Record(day, month, year));

		read_cost(i, count_cost, Date(day, month, year));
		read_income(i, count_income, Date(day, month, year));
	}
}

void Main::read_cost(int index, int count_cost, Date &obj)
{
	std::string name;
	float money = 0;
	int index_insert_history = 0;

	for (int j = 0; j < count_cost; j++)
	{
		std::getline(_file, name);
		std::getline(_file, name);
		_file >> money;
		_records[index].add_to_cost(money, name);

		index_insert_history = find_place_insert_in_history_cost(obj.get_day(), obj.get_month(), obj.get_year());
		_history_cost.insert(_history_cost.begin() + index_insert_history, Cost_or_Income(money, name, obj.get_day(), obj.get_month(), obj.get_year()));
	}
}

void Main::read_income(int index, int count_income, Date &obj)
{
	std::string name;
	float money = 0;
	int index_insert_history = 0;

	for (int j = 0; j < count_income; j++)
	{
		std::getline(_file, name);
		std::getline(_file, name);
		_file >> money;
		_records[index].add_to_income(money, name);

		index_insert_history = find_place_insert_in_history_income(obj.get_day(), obj.get_month(), obj.get_year());
		_history_income.insert(_history_income.begin() + index_insert_history, Cost_or_Income(money, name, obj.get_day(), obj.get_month(), obj.get_year()));//
	}
}

void Main::read_file()
{
	int count_debts_or_records = 0;
	int count_cost = 0;
	int count_income = 0;
	int day = 0;
	int month = 0;
	int year = 0;
	std::string name;
	float money = 0;
	int index_insert_history = 0;
	bool status = false;

	read_debts(_file);
	read_debtors(_file);

	read_records();

	_file >> money;
	set_cash_flow(money);
}

Main &Main::operator=(const Main &obj)
{
	_history_cost = obj._history_cost;
	_history_income = obj._history_income;
	_records = obj._records;
	_debts = obj._debts;
	_debtors = obj._debtors;

	_cash_flow.set_money(obj._cash_flow.get_money());
	return *this;
}

Main::Main(const Main &obj)
{
	_history_cost = obj._history_cost;
	_history_income = obj._history_income;
	_records = obj._records;
	_debts = obj._debts;
	_debtors = obj._debtors;
	_cash_flow.set_money(obj._cash_flow.get_money());
}

void Main::error_write()const
{
	std::cout << std::endl << "Сохранить данные не удалось. При последующем запуске данные останутся прежними." 
		<< std::endl << "Для выхода из программы нажмите любую кнопку.";
	_getch();
}

Main::Main()
{
	_file.open("file.txt",std::ios_base::in);
	if (_file.is_open() != false) 
	{
		read_file();
		_file.close();
	}
}

Main::~Main()
{
	_file.open("file.txt", std::ios_base::out);
	if (_file.is_open() == false)
		error_write();
	else
	{
		write_file();
		_file.close();
	}
}