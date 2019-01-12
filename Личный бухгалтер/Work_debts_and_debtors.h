#pragma once

#include "Debts.h"
#include <vector>
#include <fstream>
#include <iostream>

class Work_debts_and_debtors
{
	friend class Main;
public:
	void show_debts()const;
	void show_debtors()const;

	void add_debt(short int day, short int month, short int year, std::string name, float money);
	bool delete_debt(short int day, short int month, short int year, std::string name, float money);
	bool delete_debt(int index);

	void add_debtor(short int day, short int month, short int year, std::string name, float money);
	bool delete_debtor(short int day, short int month, short int year, std::string name, float money);
	bool delete_debtor(int index);

	bool change_status_debt(bool new_status, short int day, short int month, short int year, std::string name, float money);
	bool change_status_debtor(bool new_status, short int day, short int month, short int year, std::string name, float money);

	bool change_status_debt(int index, bool new_status);
	bool change_status_debtor(int index, bool new_status);

	void change_name_debt(int index, std::string name);
	void change_name_debtor(int index, std::string name);

	void change_money_debt(int index, float money);
	void change_money_debtor(int index, float money);

	void change_date_debt(int index, short int day, short int month, short int year);
	void change_date_debtor(int index, short int day, short int month, short int year);

	void change_date_debt(int index, Date &obj);
	void change_date_debtor(int index, Date &obj);

	bool value_status_debts(int index)const;
	bool value_status_debtors(int index)const;

	Debts get_debt(int index)const;
	Debts get_debtor(int index)const;

	int get_count_debts()const;
	int get_count_debtors()const;

	void read_debts(std::fstream &file);
	void read_debtors(std::fstream &file);

	void write_debts(std::fstream &file);
	void write_debtors(std::fstream &file);

	Work_debts_and_debtors();
	virtual ~Work_debts_and_debtors();

private:
	std::vector<Debts> _debts;
	std::vector<Debts> _debtors;

	void read_debt(std::fstream &_file, std::vector<Debts> &vector);
	void write_debt(std::fstream &_file, std::vector<Debts> &vector);

	int  find_debts(short int day, short int month, short int year, std::string name, float money)const;
	int  find_debtors(short int day, short int month, short int year, std::string name, float money)const;
};