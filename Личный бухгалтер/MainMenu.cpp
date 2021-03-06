#include "MainMenu.h"

void MainMenu::menu_history_cost()const
{
	system("cls");
	if (get_count_history_cost() == 0)
		print_one_history_cost();
	else
		show_history_cost();

	print_two_history_cost();
}

void MainMenu::menu_history_income()const
{
	system("cls");
	if (get_count_history_income() == 0)
		print_one_history_cost();
	else
		show_history_income();

	print_two_history_cost();
}

void MainMenu::menu_change_name_debt()
{
	system("cls");
	if (get_count_debts() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debts();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_debts());
	if (index == 0)
		return;

	system("cls");
	print_two_menu_change_name_debt(get_debt(index - 1).get_name_debts());
	std::string new_name;
	std::getline(std::cin,new_name);

	change_name_debt(index-1, new_name);
}

void MainMenu::menu_change_name_debtor()
{
	system("cls");
	if (get_count_debtors() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debtors();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_debtors());
	if (index == 0)
		return;

	system("cls");
	print_two_menu_change_name_debtor(get_debtor(index - 1).get_name_debts());

	std::string new_name;
	std::getline(std::cin, new_name);

	change_name_debtor(index-1, new_name);
}

void MainMenu::menu_change_money_debt()
{
	system("cls");
	if (get_count_debts() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debts();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_debts());
	if (index == 0)
		return;

	system("cls");
	print_one_menu_change_money_debt(get_debt(index - 1).get_money_repayment());
	float summa = input_value_float(0, FLT_MAX);

	change_money_debt(index - 1, summa);
}

void MainMenu::menu_show_debts()const
{
	system("cls");
	if (get_count_debts() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debts();
	print_two_history_cost();
}

void MainMenu::menu_show_debtors()const
{
	system("cls");
	if (get_count_debtors() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debtors();
	print_two_history_cost();
}

void MainMenu::menu_change_money_debtor()
{
	system("cls");
	if (get_count_debtors() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debtors();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_debtors());
	if (index == 0)
		return;

	system("cls");
	print_one_menu_change_money_debt(get_debtor(index - 1).get_money_repayment());
	float summa = input_value_float(0, FLT_MAX);

	change_money_debtor(index - 1, summa);
}

void MainMenu::menu_change_date_debt()
{
	system("cls");
	if (get_count_debts() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debts();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_debts());
	if (index == 0)
		return;

	system("cls");
	print_one_menu_add_record();
	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	change_date_debt(index - 1, day, month, year);
}

void MainMenu::menu_change_date_debtor()
{
	system("cls");
	if (get_count_debtors() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debtors();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_debtors());
	if (index == 0)
		return;

	system("cls");
	print_one_menu_add_record();
	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	change_date_debtor(index - 1, day, month, year);
}

void MainMenu::menu_add_debt()
{
	system("cls");
	print_one_menu_add_debt();

	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	print_two_menu_add_debt();
	float summa = input_value_float(0, FLT_MAX);

	print_three_menu_add_debt();
	std::string name;
	std::getline(std::cin,name);

	add_debt(day, month, year, name, summa);
}

void MainMenu::menu_add_debtor()
{
	system("cls");
	print_one_menu_add_debt();

	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	print_two_menu_add_debt();
	float summa = input_value_float(0, FLT_MAX);

	print_one_menu_add_debtor();
	std::string name;
	std::getline(std::cin, name);

	add_debtor(day, month, year, name, summa);
}

void MainMenu::menu_delete_debt()
{
	system("cls");
	if (get_count_debts() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	while (1)
	{
		system("cls");
		show_debts();
		print_one_menu_delete_debt();
		int index = input_value_int(0, get_count_debts());
		if (index == 0)
			return;

		system("cls");
		print_two_menu_delete_debt();
		if (input_value_int(1, 2) == 1)
		{
			delete_debt(index - 1);
			return;
		}
	}
}

void MainMenu::menu_delete_debtor()
{
	system("cls");
	if (get_count_debtors() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	while (1)
	{
		system("cls");
		show_debtors();
		print_one_menu_delete_debt();
		int index = input_value_int(0, get_count_debtors());
		if (index == 0)
			return;

		system("cls");
		print_two_menu_delete_debt();
		if (input_value_int(1, 2) == 1)
		{
			delete_debtor(index - 1);
			return;
		}
	}
}

void MainMenu::menu_add_record()
{
	system("cls");
	print_one_menu_add_record();

	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	add_record(day, month, year);
}

void MainMenu::menu_delete_record()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_delete_debt();
		int index = input_value_int(0, get_count_records());
		if (index == 0)
			return;

		system("cls");
		print_two_menu_delete_debt();
		if (input_value_int(1, 2) == 1)
		{
			delete_record(index - 1);
			return;
		}
	}
}

void MainMenu::menu_change_date_record()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_records();
	print_one_menu_change_name_debt();
	int index = input_value_int(0, get_count_records());
	if (index == 0)
		return;

	system("cls");
	print_one_menu_add_record();
	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	change_date_record(index - 1, day, month, year);
}

void MainMenu::menu_add_cost()
{
	system("cls");
	print_one_menu_add_record();

	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	std::string name_cost;
	print_one_menu_add_cost();
	std::getline(std::cin, name_cost);

	print_two_menu_add_cost();
	float summa = input_value_float(0, FLT_MAX);

	add_cost_in_record(day, month, year, name_cost, summa);
}

void MainMenu::menu_add_income()
{
	print_one_menu_add_record();

	print_three_menu_average();
	short int day = input_value_int(0, 31);
	if (day == 0)
		return;

	print_four_menu_average();
	short int month = input_value_int(0, 12);
	if (month == 0)
		return;

	print_five_menu_average();
	short int year = input_value_int(0, USHRT_MAX);
	if (year == 0)
		return;

	std::string name_income;
	print_one_menu_add_income();
	std::getline(std::cin, name_income);

	print_two_menu_add_cost();
	float summa = input_value_float(0, FLT_MAX);

	add_income_in_record(day, month, year, name_income, summa);
}

void MainMenu::menu_delete_cost()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_delete_cost();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		while (1)
		{
			system("cls");
			if (get_count_cost(index_one - 1) == 0)
			{
				print_empty_records();
				print_two_history_cost();
				break;
			}
			show_cost(index_one - 1);
			print_one_menu_delete_debt();
			int index_two = input_value_int(0, get_count_cost(index_one-1));
			if (index_two == 0)
				break;

			system("cls");
			print_two_menu_delete_debt();
			if (input_value_int(1, 2) == 1)
			{
				delete_cost_in_record(index_one-1, index_two-1);
				return;
			}
		}	
	}
}

void MainMenu::menu_delete_income()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_delete_income();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		while (1)
		{
			system("cls");
			if (get_count_income(index_one - 1) == 0)
			{
				print_empty_records();
				print_two_history_cost();
				break;
			}

			system("cls");
			print_one_menu_delete_debt();
			show_income(index_one - 1);
			int index_two = input_value_int(0, get_count_income(index_one-1));
			if (index_two == 0)
				break;

			system("cls");
			print_two_menu_delete_debt();
			if (input_value_int(1, 2) == 1)
			{
				delete_income_in_record(index_one-1, index_two-1);
				return;
			}
		}
	}
}

void MainMenu::menu_change_name_cost()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_change_name_cost();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		system("cls");
		if (get_count_cost(index_one - 1) == 0)
		{
			print_empty_records();
			print_two_history_cost();
			return;
		}

		show_cost(index_one-1);
		print_two_menu_change_name_cost();
		int index_two = input_value_int(0, get_count_cost(index_one-1));
		if (index_two == 0)
			continue;

		system("cls");
		print_three_menu_change_name_cost();
		std::string name;
		std::getline(std::cin, name);

		change_name_cost(index_one - 1, index_two-1, name);
	}
}

void MainMenu::menu_change_name_income()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_change_name_income();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		system("cls");
		if (get_count_income(index_one - 1) == 0)
		{
			print_empty_records();
			print_two_history_cost();
			break;
		}

		show_income(index_one-1);
		print_two_menu_change_name_cost();
		int index_two = input_value_int(0, get_count_income(index_one-1));
		if (index_two == 0)
			continue;

		system("cls");
		print_two_menu_change_name_income();
		std::string name;
		std::getline(std::cin, name);

		change_name_income(index_one - 1, index_two-1, name);
	}
}

void MainMenu::menu_change_money_cost()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_change_money_cost();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		system("cls");
		if (get_count_cost(index_one - 1) == 0)
		{
			print_empty_records();
			print_two_history_cost();
			return;
		}

		show_cost(index_one-1);
		print_two_menu_change_name_cost();
		int index_two = input_value_int(0, get_count_cost(index_one - 1));
		if (index_two == 0)
			continue;

		system("cls");
		print_one_menu_change_money_debt(get_record_money_cost(index_one - 1, index_two - 1));
		float summa = input_value_float(0, FLT_MAX);

		change_money_cost(index_one - 1, index_two - 1, summa);
	}
}

void MainMenu::menu_change_money_income()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_change_money_income();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		system("cls");
		if (get_count_income(index_one - 1) == 0)
		{
			print_empty_records();
			print_two_history_cost();
			break;
		}

		show_income(index_one - 1);
		print_two_menu_change_name_cost();
		int index_two = input_value_int(0, get_count_income(index_one - 1));
		if (index_two == 0)
			continue;

		system("cls");
		print_one_menu_change_money_debt(get_record_money_income(index_one - 1, index_two - 1));
		float summa = input_value_float(0, FLT_MAX);

		change_money_income(index_one - 1, index_two - 1, summa);
	}
}

void MainMenu::menu_change_date_cost()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_change_data_cost();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		system("cls");
		if (get_count_cost(index_one - 1) == 0)
		{
			print_empty_records();
			print_two_history_cost();
			return;
		}

		show_cost(index_one - 1);
		print_two_menu_change_name_cost();
		int index_two = input_value_int(0, get_count_cost(index_one - 1));
		if (index_two == 0)
			continue;

		system("cls");
		print_one_menu_add_record();

		print_three_menu_average();
		short int day = input_value_int(0, 31);
		if (day == 0)
			return;

		print_four_menu_average();
		short int month = input_value_int(0, 12);
		if (month == 0)
			return;

		print_five_menu_average();
		short int year = input_value_int(0, USHRT_MAX);
		if (year == 0)
			return;

		change_data_cost(index_one - 1, index_two - 1, day, month, year);
	}
}

void MainMenu::menu_change_date_income()
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	while (1)
	{
		system("cls");
		show_records();
		print_one_menu_change_data_income();
		int index_one = input_value_int(0, get_count_records());
		if (index_one == 0)
			return;

		system("cls");
		if (get_count_income(index_one - 1) == 0)
		{
			print_empty_records();
			print_two_history_cost();
			break;
		}

		show_income(index_one - 1);
		print_two_menu_change_name_cost();
		int index_two = input_value_int(0, get_count_income(index_one - 1));
		if (index_two == 0)
			continue;

		system("cls");
		print_one_menu_add_record();

		print_three_menu_average();
		short int day = input_value_int(0, 31);
		if (day == 0)
			return;

		print_four_menu_average();
		short int month = input_value_int(0, 12);
		if (month == 0)
			return;

		print_five_menu_average();
		short int year = input_value_int(0, USHRT_MAX);
		if (year == 0)
			return;

		change_data_income(index_one - 1, index_two - 1, day, month, year);
	}
}

void MainMenu::menu_show_cost()const
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_records();
	print_one_menu_show_cost();
	int index_one = input_value_int(0, get_count_records());
	if (index_one == 0)
		return;

	system("cls");
	if(get_count_cost(index_one-1)==0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_cost(index_one - 1);
	print_two_menu_show_cost();
}

void MainMenu::menu_show_income()const
{
	system("cls");
	if (get_count_records() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}
	show_records();
	print_one_menu_show_cost();
	int index_one = input_value_int(0, get_count_records());
	if (index_one == 0)
		return;

	system("cls");
	if (get_count_income(index_one - 1) == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_income(index_one - 1);
	print_two_menu_show_cost();
}

void MainMenu::menu_change_status_debt()
{
	system("cls");
	if (get_count_debts() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debts();
	print_one_menu_change_status_debt();
	int index = input_value_int(0, get_count_debts());
	if (index == 0)
		return;

	system("cls");
	print_two_menu_change_status_debt(value_status_debts(index - 1));
	change_status_debt(index - 1, (bool)(input_value_int(1, 2) - 1));
}

void MainMenu::menu_change_status_debtor()
{
	system("cls");
	if (get_count_debtors() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	show_debtors();
	print_one_menu_change_status_debt();
	int index = input_value_int(0, get_count_debtors());
	if (index == 0)
		return;

	system("cls");
	print_two_menu_change_status_debt(value_status_debtors(index - 1));
	change_status_debtor(index - 1, (bool)(input_value_int(1, 2) - 1));
}

void MainMenu::menu_currency_converter()const
{
	float cash = 0;
	float course = 0;

	print_one_menu_currency_converter();
	cash = input_value_float(0, FLT_MAX);
	if (cash == 0.0)
		return;

	print_two_menu_currency_converter();
	course = input_value_float(0, FLT_MAX);
	if (course == 0.0)
		return;

	print_three_menu_currency_converter(currency_converter(cash, course));
}

void MainMenu::menu_change_cash_flow()
{
	print_one_menu_change_cash_flow();
	set_cash_flow(input_value_float(0, FLT_MAX));
	print_two_menu_change_cash_flow();
}

void MainMenu::menu_average_cost()const
{
	system("cls");
	
	print_eight_menu_average();

	if (get_count_history_cost() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	short int day_from = 0;
	short int month_from = 0;
	short int year_from = 0;

	short int day_to = 0;
	short int month_to = 0;
	short int year_to = 0;

	print_one_menu_average();
	print_three_menu_average();
	day_from = input_value_int(0, 31);
	if (day_from == 0)
		return;

	print_four_menu_average();
	month_from = input_value_int(0, 12);
	if (month_from == 0)
		return;

	print_five_menu_average();
	year_from = input_value_int(0, USHRT_MAX);
	if (year_from == 0)
		return;

	print_two_menu_average();
	print_three_menu_average();
	day_to = input_value_int(0, 31);
	if (day_to == 0)
		return;

	print_four_menu_average();
	month_to = input_value_int(0, 12);
	if (month_to == 0)
		return;

	print_five_menu_average();
	year_to = input_value_int(0, USHRT_MAX);
	if (year_to == 0)
		return;
	
	print_six_menu_average(average_cost(day_from, month_from, year_from, day_to, month_to, year_to));
}

void MainMenu::menu_average_income()const
{

	system("cls");
	print_seven_menu_average();

	if (get_count_history_cost() == 0)
	{
		print_empty_records();
		print_two_history_cost();
		return;
	}

	short int day_from = 0;
	short int month_from = 0;
	short int year_from = 0;

	short int day_to = 0;
	short int month_to = 0;
	short int year_to = 0;

	print_one_menu_average();
	print_three_menu_average();
	day_from = input_value_int(0, 31);
	if (day_from == 0)
		return;

	print_four_menu_average();
	month_from = input_value_int(0, 12);
	if (month_from == 0)
		return;

	print_five_menu_average();
	year_from = input_value_int(0, USHRT_MAX);
	if (year_from == 0)
		return;

	print_two_menu_average();
	print_three_menu_average();
	day_to = input_value_int(0, 31);
	if (day_to == 0)
		return;

	print_four_menu_average();
	month_to = input_value_int(0, 12);
	if (month_to == 0)
		return;

	print_five_menu_average();
	year_to = input_value_int(0, USHRT_MAX);
	if (year_to == 0)
		return;

	print_six_menu_average(average_income(day_from, month_from, year_from, day_to, month_to, year_to));
}

float MainMenu::input_value_float(float min_value, float max_value)const
{
	float value = 0;
	do
	{
		rewind(stdin);
		std::cin >> value;

		if (std::cin.fail() || value<min_value || value > max_value)//true ����� �� ������ ���
		{
			std::cout << std::endl << "������. ��������� ����:";
			std::cin.clear();
		}
		else
			break;
	} while (1);
	rewind(stdin);
	return value;
}

int MainMenu::input_value_int(int min_value, int max_value)const
{
	int value = 0;
	do
	{
		rewind(stdin);
		std::cin >> value;

		if (std::cin.fail() || value<min_value || value > max_value)//true ����� �� ������ ���
		{
			std::cout << std::endl << "������. ��������� ����:";
			std::cin.clear();
		}
		else
			break;
	} while (1);
	rewind(stdin);
	return value;
}

void MainMenu::print_one_menu_average()const
{
	std::cout << std::endl << "������� ����, ������ ����� ���������� ������� �������� �������� ����� �����(��� '0' � ����� �� �����)." << std::endl << std::endl;
}

void MainMenu::print_two_menu_average()const
{
	std::cout << std::endl << "������� ����, ������ ����� ���� ������� �������� �������� ����� �����(��� '0' � ����� �� �����)." << std::endl << std::endl;
}

void MainMenu::print_three_menu_average()const
{
	std::cout << std::endl << "����:";
}

void MainMenu::print_four_menu_average()const
{
	std::cout << std::endl << "�����:";
}

void MainMenu::print_five_menu_average()const
{
	std::cout << std::endl << "���:";
}

void MainMenu::print_six_menu_average(float value)const
{
	std::cout << std::endl << "������� ��������:" << value << std::endl << std::endl << "������� ����� ������ ��� ������ � ������� ����.";
	_getch();
}

void MainMenu::print_seven_menu_average()const
{
	std::cout << std::endl << "������� �������� �������.";
}

void MainMenu::print_eight_menu_average()const
{
	std::cout << std::endl << "������� �������� ��������.";
}

void MainMenu::print_one_menu_change_cash_flow()const
{
	system("cls");
	std::cout << std::endl << "������� ������:" << get_cash_flow() << std::endl << std::endl << "������� ����� ��������:";
}

void MainMenu::print_two_menu_change_cash_flow()const
{
	std::cout << std::endl << "������ �������." << std::endl << std::endl << "������� ����� ������ ��� ������ � ������� ����.";
	_getch();
}

void MainMenu::print_one_menu_currency_converter()const
{
	system("cls");
	std::cout << std::endl << "������� �����, ������� ������ ��������������(��� '0' ��� ������ � ������� ����):";
}

void MainMenu::print_two_menu_currency_converter()const
{
	std::cout << std::endl << "������� ���� ������, � ������� ������ �������������� ���� �����(��� '0' ��� ������ � ������� ����):";
}

void MainMenu::print_three_menu_currency_converter(float cash)const
{
	std::cout << std::endl << "�������� �����:"<<cash << std::endl << std::endl <<"������� ����� ������ ��� ������ � ������� ����.";
	_getch();
}

void MainMenu::print_one_menu_change_status_debt()const
{
	std::cout << std::endl << "������� ����� ����, ������ �������� ������ ��������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_two_menu_change_status_debt(bool status)const
{
	std::cout << std::endl << "���������� ������:";
	if(status==true)
		std::cout << "�������." << std::endl << std::endl;
	else
		std::cout << "�� �������." << std::endl << std::endl;

	std::cout << "������� ����� ������(1-���� �� �������, 2- ���� �������):";
}

void MainMenu::print_one_menu_change_name_debt()const
{
	std::cout << std::endl << "������� ����� ������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_two_menu_change_name_debt(std::string name)const
{
	std::cout << "������� ������:" << name << std::endl << std::endl;
	std::cout << "������� ����� ���/�������� �����������:";
}

void MainMenu::print_two_menu_change_name_debtor(std::string name)const
{
	std::cout << "������� �������:" << name << std::endl << std::endl;
	std::cout << "������� ����� ���/�����������:";
}

void MainMenu::print_one_menu_change_money_debt(float money)const
{
	std::cout << "������� �����:" << money << std::endl << std::endl;
	std::cout << "������� ����� ��������:";
}

void MainMenu::print_one_menu_change_date_debt()const
{
	std::cout << std::endl << "������� ����� ����(��� '0' � ����� �� ����� ��� ������ � ����)." << std::endl << std::endl;
}

void MainMenu::print_one_menu_add_debt()const
{
	std::cout << std::endl << "������� ���� ��������� �����(��� '0' � ����� �� ����� ��� ������ � ����)." << std::endl << std::endl;
}

void MainMenu::print_two_menu_add_debt()const
{
	std::cout << std::endl << "������� ����� ����:";
}

void MainMenu::print_three_menu_add_debt()const
{
	std::cout << std::endl << "������� ��� �������/�������� �����������:";
}

void MainMenu::print_one_menu_add_debtor()const
{
	std::cout << std::endl << "������� ��� ��������/�������� �����������:";
}

void MainMenu::print_one_menu_delete_debt()const
{
	std::cout << std::endl << "������� ������, ������� ������ �������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_two_menu_delete_debt()const
{
	std::cout << std::endl << "�� �������(1-��, 2- ���)?" << std::endl << std::endl;
}

void MainMenu::print_one_menu_add_record()const
{
	std::cout << std::endl << "������� ���� ������(��� '0' � ����� �� ����� ��� ������ � ����)." << std::endl << std::endl;
}

void MainMenu::print_one_menu_add_cost()const
{
	std::cout << std::endl << std::endl << "������� ������� �������:";
}

void MainMenu::print_two_menu_add_cost()const
{
	std::cout << std::endl << std::endl << "������� �����:";
}

void MainMenu::print_one_menu_add_income()const
{
	std::cout << std::endl << "������� �������� ������:" << std::endl << std::endl;
}

void MainMenu::print_one_menu_delete_cost()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ ������� ���������� � ��������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_two_menu_delete_cost()const
{
	std::cout << std::endl << "������� ������, ������� ������ �������(��� '0' ����� �������� �����):";
}

void MainMenu::print_one_menu_delete_income()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ ������� ���������� � �������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_one_menu_change_name_cost()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ �������� ������� �����(��� '0' ��� ������ � ����):";
}

void MainMenu::print_one_menu_change_name_income()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ �������� �������� ������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_two_menu_change_name_income()const
{
	std::cout << std::endl << "������� ����� �������� ������:";
}

void MainMenu::print_two_menu_change_name_cost()const
{
	std::cout << std::endl << "�������� ������, ������� ������ ��������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_three_menu_change_name_cost()const
{
	std::cout << std::endl << "������� ����� ������� �����:";
}

void MainMenu::print_one_menu_change_money_cost()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ �������� ����� �������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_one_menu_change_money_income()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ �������� ����� ������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_one_menu_change_data_cost()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ �������� ���� �������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_one_menu_change_data_income()const
{
	std::cout << std::endl << "�������� ������ � ������� ������ �������� ���� ������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_one_menu_show_cost()const
{
	std::cout << std::endl << "�������� ������, ������� ������ �����������(��� '0' ��� ������ � ����):";
}

void MainMenu::print_two_menu_show_cost()const
{
	std::cout << std::endl << std::endl << "������� ����� ������ ��� ������ � ����.";
	_getch();
}

void MainMenu::print_one_history_cost()const
{
	std::cout << std::endl << std::endl << "������� �����.";
}

void MainMenu::print_two_history_cost()const
{
	std::cout << std::endl << std::endl << "������� ����� ������ ��� ������ � ����.";
	_getch();
}

void MainMenu::print_empty_records()const
{
	std::cout << std::endl << std::endl << "������� ���.";
}

void MainMenu::print_show_money()const
{
	system("cls");
	std::cout << "������ ��������:" << get_cash_flow() << std::endl << std::endl << "������� ����� ������ ��� ������ � ����.";
	_getch();
}

MainMenu::MainMenu()
{}

MainMenu::~MainMenu()
{}