#pragma once
#include "Main.h"
#include <conio.h>

class MainMenu : public Main
{
public:
	void menu_show_debts()const;        //меню просмотра долгов
	void menu_show_debtors()const;      //меню просмотра должников
	void menu_change_status_debt();     //меню изменения статуса долга
	void menu_change_status_debtor();   //меню изменения статуса должника
	void menu_change_name_debt();       //меню изменения имени заёмщика
	void menu_change_name_debtor();	    //меню изменения имени должника
	void menu_change_money_debt();      //меню изменения суммы долга
	void menu_change_money_debtor();    //меню изменения суммы долга должника
	void menu_change_date_debt();       //меню изменения даты погашения долга
	void menu_change_date_debtor();     //меню изменения даты погашения долга должником
	void menu_add_debt();			    //меню добавления долга
	void menu_add_debtor();			    //меню добавления должника
	void menu_delete_debt();            //меню удаления долга
	void menu_delete_debtor();		    //меню удаления долга
	void menu_add_record();             //меню добавления записи
	void menu_change_date_record();     //меню изменения даты записи
	void menu_delete_record();          //меню удаления записи
	void menu_add_cost();			    //меню добавления записи расходов
	void menu_change_date_cost();	    //меню изменения даты расходов
	void menu_change_money_cost();	    //меню изменения суммы расходов
	void menu_change_name_cost();	    //меню изменения причины расходов
	void menu_delete_cost();		    //меню удаления записи расходов
	void menu_add_income();             //меню добавления записи доходов
	void menu_show_cost()const;         //меню просмотра расходов
	void menu_show_income()const;	    //меню просмотра доходов
	void menu_change_date_income();     //меню изменения даты доходов
	void menu_change_money_income();    //меню изменения суммы доходов
	void menu_change_name_income();     //меню изменения источника доходов
	void menu_delete_income();          //меню удаления записи доходов
	void menu_history_cost()const;      //меню истории расходов
	void menu_history_income()const;    //меню истории доходов
	void menu_currency_converter()const;//меню конвертера валют
	void menu_change_cash_flow();       //меню изменения баланса кошелька
	void menu_average_cost()const;      //меню подсчета среднего значения расходов
	void menu_average_income()const;    //меню подсчета среднего значения доходов
	void print_show_money()const;       //вывод баланса кошелька

	MainMenu();
	virtual ~MainMenu();

private:
	float input_value_float(float min_value, float max_value)const;//ввод целых значений
	int   input_value_int(int min_value, int max_value)const;      //ввод дробных значений
	void  print_one_menu_currency_converter()const;
	void  print_two_menu_currency_converter()const;
	void  print_three_menu_currency_converter(float cash)const;
	void  print_one_menu_change_cash_flow()const;
	void  print_two_menu_change_cash_flow()const;
	void  print_one_menu_average()const;
	void  print_two_menu_average()const;
	void  print_three_menu_average()const;
	void  print_four_menu_average()const;
	void  print_five_menu_average()const;
	void  print_six_menu_average(float value)const;
	void  print_seven_menu_average()const;
	void  print_eight_menu_average()const;
	void  print_one_menu_change_name_debt()const;
	void  print_two_menu_change_name_debt(std::string name)const;
	void  print_two_menu_change_name_debtor(std::string name)const;
	void  print_one_menu_change_status_debt()const;
	void  print_two_menu_change_status_debt(bool status)const;
	void  print_one_menu_change_money_debt(float money)const;
	void  print_one_menu_change_date_debt()const;
	void  print_one_menu_add_debt()const;
	void  print_two_menu_add_debt()const;
	void  print_three_menu_add_debt()const;
	void  print_one_menu_add_debtor()const;
	void  print_one_menu_delete_debt()const;
	void  print_two_menu_delete_debt()const;
	void  print_one_menu_add_record()const;
	void  print_one_menu_add_cost()const;
	void  print_two_menu_add_cost()const;
	void  print_one_menu_add_income()const;
	void  print_one_menu_delete_cost()const;
	void  print_two_menu_delete_cost()const;
	void  print_one_menu_delete_income()const;
	void  print_one_menu_change_name_cost()const;
	void  print_two_menu_change_name_cost()const;
	void  print_three_menu_change_name_cost()const;
	void  print_one_menu_change_name_income()const;
	void  print_two_menu_change_name_income()const;
	void  print_one_menu_change_money_cost()const;
	void  print_one_menu_change_money_income()const;
	void  print_one_menu_change_data_cost()const;
	void  print_one_menu_change_data_income()const;
	void  print_one_menu_show_cost()const;
	void  print_two_menu_show_cost()const;
	void  print_one_history_cost()const;
	void  print_two_history_cost()const;
	void  print_empty_records()const;
};