#pragma once

#include "Cost_or_Income.h"
#include "date.h"
#include <string>
#include <vector>


class Record : public Date
{
public:
	void add_to_cost(float money, std::string name);  //добавить запись траты денег
	void add_to_income(float money, std::string name);//добавить запись поступления денег

	bool delete_cost(int index);  //удаление записи траты денег 
	bool delete_income(int index);//удаление записи поступления денег

	int get_count_cost()const;  //вернуть количество расходов
	int get_count_income()const;//вернуть количество доходов

	float get_records_cost(int index)const;  //вернуть сумму дохода
	float get_records_income(int index)const;//вернуть сумму расхода

	const Cost_or_Income &get_reference_cost(int index)const;  //вернуть ссылку на запись расхода
	const Cost_or_Income &get_reference_income(int index)const;//вернуть ссылку на запись дохода

	void show_cost()const;  //вывести записи расходов
	void show_income()const;//вывести записи доходов

	void change_name_cost(int index, std::string name);  //изменить причину расхода
	void change_name_income(int index, std::string name);//изменить причину дохода

	void change_money_cost(int index, float money);  //изменить сумму расхода
	void change_money_income(int index, float money);//изменить сумму дохода

	void change_data_cost(int index, short int day, short int month, short int year);  //изменить дату расхода
	void change_data_income(int index, short int day, short int month, short int year);//изменить дату дохода

	void change_data_cost(int index, Date &obj);  //изменить дату расхода
	void change_data_income(int index, Date &obj);//изменить дату дохода

	friend std::ostream & operator << (std::ostream &stream, Record &obj);
	Record &operator=(const Record &obj);

	Record();
	Record(short int day, short int month, short int year);
	Record(const Record &obj);
	virtual ~Record();

private:
	std::vector<Cost_or_Income> _cost;  //вектор всех расходов
	std::vector<Cost_or_Income> _income;//вектор всех доходов

	bool delete_cost_or_income(std::vector<Cost_or_Income> vector, int index_delete);
	float get_records_cost_or_income(std::vector<Cost_or_Income> vector, int index)const;
	void change_date(int index, std::vector<Cost_or_Income> vector, Date &obj);


};
