#pragma once
#include "Main.h"
#include <conio.h>

class MainMenu : public Main
{
public:
	void menu_show_debts()const;        //���� ��������� ������
	void menu_show_debtors()const;      //���� ��������� ���������
	void menu_change_status_debt();     //���� ��������� ������� �����
	void menu_change_status_debtor();   //���� ��������� ������� ��������
	void menu_change_name_debt();       //���� ��������� ����� �������
	void menu_change_name_debtor();	    //���� ��������� ����� ��������
	void menu_change_money_debt();      //���� ��������� ����� �����
	void menu_change_money_debtor();    //���� ��������� ����� ����� ��������
	void menu_change_date_debt();       //���� ��������� ���� ��������� �����
	void menu_change_date_debtor();     //���� ��������� ���� ��������� ����� ���������
	void menu_add_debt();			    //���� ���������� �����
	void menu_add_debtor();			    //���� ���������� ��������
	void menu_delete_debt();            //���� �������� �����
	void menu_delete_debtor();		    //���� �������� �����
	void menu_add_record();             //���� ���������� ������
	void menu_change_date_record();     //���� ��������� ���� ������
	void menu_delete_record();          //���� �������� ������
	void menu_add_cost();			    //���� ���������� ������ ��������
	void menu_change_date_cost();	    //���� ��������� ���� ��������
	void menu_change_money_cost();	    //���� ��������� ����� ��������
	void menu_change_name_cost();	    //���� ��������� ������� ��������
	void menu_delete_cost();		    //���� �������� ������ ��������
	void menu_add_income();             //���� ���������� ������ �������
	void menu_show_cost()const;         //���� ��������� ��������
	void menu_show_income()const;	    //���� ��������� �������
	void menu_change_date_income();     //���� ��������� ���� �������
	void menu_change_money_income();    //���� ��������� ����� �������
	void menu_change_name_income();     //���� ��������� ��������� �������
	void menu_delete_income();          //���� �������� ������ �������
	void menu_history_cost()const;      //���� ������� ��������
	void menu_history_income()const;    //���� ������� �������
	void menu_currency_converter()const;//���� ���������� �����
	void menu_change_cash_flow();       //���� ��������� ������� ��������
	void menu_average_cost()const;      //���� �������� �������� �������� ��������
	void menu_average_income()const;    //���� �������� �������� �������� �������
	void print_show_money()const;       //����� ������� ��������

	MainMenu();
	virtual ~MainMenu();

private:
	float input_value_float(float min_value, float max_value)const;//���� ����� ��������
	int   input_value_int(int min_value, int max_value)const;      //���� ������� ��������
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