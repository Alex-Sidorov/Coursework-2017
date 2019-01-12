#pragma once

#include <ios>
#include "Record.h"
#include "Debts.h"
#include "Money.h"
#include "Work_debts_and_debtors.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <conio.h>

class Main :public Work_debts_and_debtors
{
public:

	float get_cash_flow()const;     
	void  set_cash_flow(float money);

	int get_count_records()const;  

	int get_count_history_cost()const; 
	int get_count_history_income()const;

	int get_count_cost(int index)const;  
	int get_count_income(int index)const; 

	float get_record_money_cost(int index_one, int index_two)const;  
	float get_record_money_income(int index_one, int index_two)const;

	Cost_or_Income get_cost(int index_one, int index_two)const;  
	Cost_or_Income get_income(int index_one, int index_two)const;

	void add_record(short int day, short int month, short int year);   
	bool delete_record(short int day, short int month, short int year);
	bool delete_record(int index);									  

	void change_name_cost(int index_one, int index_two, std::string name); 
	void change_name_income(int index_one, int index_two, std::string name);

	void change_money_cost(int index_one, int index_two, float money); 
	void change_money_income(int index_one, int index_two, float money);

	void change_data_cost(int index_one, int index_two, short int day, short int month, short int year);  
	void change_data_income(int index_one, int index_two, short int day, short int month, short int year);

	void change_date_record(int index, short int day, short int month, short int year);

	float average_cost(short int day_from, short int month_from, short int year_from, short int day_to, short int month_to, short int year_to)const;  
	float average_income(short int day_from, short int month_from, short int year_from, short int day_to, short int month_to, short int year_to)const;

	void add_cost_in_record(short int day, short int month, short int year, std::string name, float money); 
	void add_income_in_record(short int day, short int month, short int year, std::string name, float money);

	void add_cost_in_record(const Cost_or_Income &obj); 
	void add_income_in_record(const Cost_or_Income &obj);

	void delete_cost_in_record(int index_one, int index_two);
	void delete_income_in_record(int index_one, int index_two);

	void show_records()const;

	void show_cost(int index)const;  
	void show_income(int index)const;

	void show_history_cost()const; 
	void show_history_income()const;

	float currency_converter(float cash, float course)const;

	Main &operator=(const Main &obj);

	Main(const Main &obj);
	Main();
	virtual ~Main();

private:
	std::vector<Record>_records;

	std::vector<Cost_or_Income> _history_cost; 
	std::vector<Cost_or_Income> _history_income;

	Money _cash_flow; 
	std::fstream _file;

	int  find_place_insert_record(short int day, short int month, short int year)const;                    
	int  find_place_insert_in_history_cost(short int day, short int month, short int year)const;		  
	int  find_place_insert_in_history_income(short int day, short int month, short int year)const;	      
	int  find_record(Date &obj)const;                                
	int  find_history_cost(const Cost_or_Income &obj)const;                                                
	int  find_history_income(const Cost_or_Income &obj)const;											
	bool check_insert_date(short int day, short int month, short int year)const; 
	void read_records();
	void read_cost(int index, int count_cost, Date &obj);
	void read_income(int index, int count_income, Date &obj);
	
	void read_file();
	void write_file();

	void error_write()const;

	template<class Type>
	int find_place_insert(std::vector<Type> vector, Date &obj)const;

};

template<class Type>
int Main::find_place_insert(std::vector<Type> vector, Date &obj)const
{
	int index_insert = 0;
	if (vector.size() == 0) return 0;

	while (obj.get_year() > vector[index_insert].get_year())
	{
		index_insert++;
		if (index_insert == vector.size())
			return index_insert;
	}

	if (obj.get_year() < vector[index_insert].get_year())
		return index_insert;

	while (obj.get_year() == vector[index_insert].get_year() && obj.get_month() > vector[index_insert].get_month())
	{
		index_insert++;
		if (index_insert == vector.size())
			return index_insert;
	}

	if (obj.get_year() != vector[index_insert].get_year() || obj.get_month() < vector[index_insert].get_month())
		return index_insert;


	while (obj.get_year() == vector[index_insert].get_year() && obj.get_month() == vector[index_insert].get_month() && obj.get_day() > vector[index_insert].get_day())
	{
		index_insert++;
		if (index_insert == vector.size())
			return index_insert;
	}

	return index_insert;
}

