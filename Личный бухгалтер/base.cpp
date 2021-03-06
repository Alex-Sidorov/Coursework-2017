#include "MainMenu.h"
#include "Menu.h"

int main()
{
	system("chcp 1251");
	system("cls");

	MainMenu obj;
	Menu<MainMenu> menu(obj);

	menu.add_menu_item("������ ������� � ��������.");
	menu.add_submenu_item(0, "�������� ���� ������.", &MainMenu::menu_change_date_record);
	menu.add_submenu_item(0, "�������� ������.", &MainMenu::menu_add_record);
	menu.add_submenu_item(0, "������� ������.", &MainMenu::menu_delete_record);
	menu.add_submenu_item(0, "����������� ������.");

	menu.add_submenu_item(0, 3, "����������� �������.");
	menu.add_submenu_item(0, 3, 0, "������� �������.", &MainMenu::menu_show_cost);
	menu.add_submenu_item(0, 3, 0, "�������� ������ �������.", &MainMenu::menu_add_cost);
	menu.add_submenu_item(0, 3, 0, "������� ������ �������.", &MainMenu::menu_delete_cost);
	menu.add_submenu_item(0, 3, 0, "�������� ������� �������.", &MainMenu::menu_change_name_cost);
	menu.add_submenu_item(0, 3, 0, "�������� ����� �������.", &MainMenu::menu_change_money_cost);
	menu.add_submenu_item(0, 3, 0, "�������� ���� �������.", &MainMenu::menu_change_date_cost);
	menu.add_submenu_item(0, 3, 0, "�����.", true);

	menu.add_submenu_item(0, 3, "����������� ������.");
	menu.add_submenu_item(0, 3, 1, "������� ������.", &MainMenu::menu_show_income);
	menu.add_submenu_item(0, 3, 1, "�������� ������ ������.", &MainMenu::menu_add_income);
	menu.add_submenu_item(0, 3, 1, "������� ������ ������.", &MainMenu::menu_delete_income);
	menu.add_submenu_item(0, 3, 1, "�������� �������� ������.", &MainMenu::menu_change_name_income);
	menu.add_submenu_item(0, 3, 1, "�������� ����� ������.", &MainMenu::menu_change_money_income);
	menu.add_submenu_item(0, 3, 1, "�������� ���� ������.", &MainMenu::menu_change_date_income);
	menu.add_submenu_item(0, 3, 1, "�����.", true);

	menu.add_submenu_item(0, 3, "�����.", true);
	menu.add_submenu_item(0, "�����.", true);

	menu.add_menu_item("������� �������.", &MainMenu::menu_history_income);
	menu.add_menu_item("������� ��������.", &MainMenu::menu_history_cost);

	menu.add_menu_item("�����.");
	menu.add_submenu_item(3, "����������� �����.", &MainMenu::menu_show_debts);
	menu.add_submenu_item(3, "�������� ��� ����������/�������� �����������.", &MainMenu::menu_change_name_debt);
	menu.add_submenu_item(3, "�������� ���� ��������� �����.", &MainMenu::menu_change_date_debt);
	menu.add_submenu_item(3, "�������� ����� �����.", &MainMenu::menu_change_money_debt);
	menu.add_submenu_item(3, "�������� ������ �����.", &MainMenu::menu_change_status_debt);
	menu.add_submenu_item(3, "�������� ������.", &MainMenu::menu_add_debt);
	menu.add_submenu_item(3, "������� ������.", &MainMenu::menu_delete_debt);
	menu.add_submenu_item(3, "�����.", true);
	
	menu.add_menu_item("��������.");
	menu.add_submenu_item(4, "����������� ���������.", &MainMenu::menu_show_debtors);
	menu.add_submenu_item(4, "�������� ��� ��������/�������� �����������.", &MainMenu::menu_change_name_debtor);
	menu.add_submenu_item(4, "�������� ���� ��������� �����.", &MainMenu::menu_change_date_debtor);
	menu.add_submenu_item(4, "�������� ����� �����.", &MainMenu::menu_change_money_debtor);
	menu.add_submenu_item(4, "�������� ������ �����.", &MainMenu::menu_change_status_debtor);
	menu.add_submenu_item(4, "�������� ������.", &MainMenu::menu_add_debtor);
	menu.add_submenu_item(4, "������� ������.", &MainMenu::menu_delete_debtor);
	menu.add_submenu_item(4, "�����.", true);

	menu.add_menu_item("������� �������� �������� �� N ����.", &MainMenu::menu_average_cost);

	menu.add_menu_item("������� �������� ������� �� N ����.", &MainMenu::menu_average_income);

	menu.add_menu_item("����������� �������� ������� ��������.", &MainMenu::print_show_money);

	menu.add_menu_item("�������� �������� ������� ��������.", &MainMenu::menu_change_cash_flow);

	menu.add_menu_item("��������� �����.", &MainMenu::menu_currency_converter);

	menu.add_menu_item("�����.", true);
	menu.open_menu();
		
	return 0;
}