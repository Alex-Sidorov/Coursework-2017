#pragma once

#include "Cost_or_Income.h"
#include "date.h"
#include <string>
#include <vector>


class Record : public Date
{
public:
	void add_to_cost(float money, std::string name);  //�������� ������ ����� �����
	void add_to_income(float money, std::string name);//�������� ������ ����������� �����

	bool delete_cost(int index);  //�������� ������ ����� ����� 
	bool delete_income(int index);//�������� ������ ����������� �����

	int get_count_cost()const;  //������� ���������� ��������
	int get_count_income()const;//������� ���������� �������

	float get_records_cost(int index)const;  //������� ����� ������
	float get_records_income(int index)const;//������� ����� �������

	const Cost_or_Income &get_reference_cost(int index)const;  //������� ������ �� ������ �������
	const Cost_or_Income &get_reference_income(int index)const;//������� ������ �� ������ ������

	void show_cost()const;  //������� ������ ��������
	void show_income()const;//������� ������ �������

	void change_name_cost(int index, std::string name);  //�������� ������� �������
	void change_name_income(int index, std::string name);//�������� ������� ������

	void change_money_cost(int index, float money);  //�������� ����� �������
	void change_money_income(int index, float money);//�������� ����� ������

	void change_data_cost(int index, short int day, short int month, short int year);  //�������� ���� �������
	void change_data_income(int index, short int day, short int month, short int year);//�������� ���� ������

	void change_data_cost(int index, Date &obj);  //�������� ���� �������
	void change_data_income(int index, Date &obj);//�������� ���� ������

	friend std::ostream & operator << (std::ostream &stream, Record &obj);
	Record &operator=(const Record &obj);

	Record();
	Record(short int day, short int month, short int year);
	Record(const Record &obj);
	virtual ~Record();

private:
	std::vector<Cost_or_Income> _cost;  //������ ���� ��������
	std::vector<Cost_or_Income> _income;//������ ���� �������

	bool delete_cost_or_income(std::vector<Cost_or_Income> vector, int index_delete);
	float get_records_cost_or_income(std::vector<Cost_or_Income> vector, int index)const;
	void change_date(int index, std::vector<Cost_or_Income> vector, Date &obj);


};
