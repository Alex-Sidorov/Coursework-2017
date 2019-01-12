#include "MainMenu.h"
#include "Menu.h"

int main()
{
	system("chcp 1251");
	system("cls");

	MainMenu obj;
	Menu<MainMenu> menu(obj);

	menu.add_menu_item("Записи доходов и расходов.");
	menu.add_submenu_item(0, "Изменить дату записи.", &MainMenu::menu_change_date_record);
	menu.add_submenu_item(0, "Добавить запись.", &MainMenu::menu_add_record);
	menu.add_submenu_item(0, "Удалить запись.", &MainMenu::menu_delete_record);
	menu.add_submenu_item(0, "Просмотреть записи.");

	menu.add_submenu_item(0, 3, "Просмотреть расходы.");
	menu.add_submenu_item(0, 3, 0, "Вывести расходы.", &MainMenu::menu_show_cost);
	menu.add_submenu_item(0, 3, 0, "Добавить запись расхода.", &MainMenu::menu_add_cost);
	menu.add_submenu_item(0, 3, 0, "Удалить запись расхода.", &MainMenu::menu_delete_cost);
	menu.add_submenu_item(0, 3, 0, "Изменить причину расхода.", &MainMenu::menu_change_name_cost);
	menu.add_submenu_item(0, 3, 0, "Изменить сумму расхода.", &MainMenu::menu_change_money_cost);
	menu.add_submenu_item(0, 3, 0, "Изменить дату расхода.", &MainMenu::menu_change_date_cost);
	menu.add_submenu_item(0, 3, 0, "Назад.", true);

	menu.add_submenu_item(0, 3, "Просмотреть доходы.");
	menu.add_submenu_item(0, 3, 1, "Вывести доходы.", &MainMenu::menu_show_income);
	menu.add_submenu_item(0, 3, 1, "Добавить запись дохода.", &MainMenu::menu_add_income);
	menu.add_submenu_item(0, 3, 1, "Удалить запись дохода.", &MainMenu::menu_delete_income);
	menu.add_submenu_item(0, 3, 1, "Изменить источник дохода.", &MainMenu::menu_change_name_income);
	menu.add_submenu_item(0, 3, 1, "Изменить сумму дохода.", &MainMenu::menu_change_money_income);
	menu.add_submenu_item(0, 3, 1, "Изменить дату дохода.", &MainMenu::menu_change_date_income);
	menu.add_submenu_item(0, 3, 1, "Назад.", true);

	menu.add_submenu_item(0, 3, "Назад.", true);
	menu.add_submenu_item(0, "Назад.", true);

	menu.add_menu_item("История доходов.", &MainMenu::menu_history_income);
	menu.add_menu_item("История расходов.", &MainMenu::menu_history_cost);

	menu.add_menu_item("Долги.");
	menu.add_submenu_item(3, "Просмотреть долги.", &MainMenu::menu_show_debts);
	menu.add_submenu_item(3, "Изменить имя занимателя/название организации.", &MainMenu::menu_change_name_debt);
	menu.add_submenu_item(3, "Изменить дату погашения долга.", &MainMenu::menu_change_date_debt);
	menu.add_submenu_item(3, "Изменить сумму долга.", &MainMenu::menu_change_money_debt);
	menu.add_submenu_item(3, "Изменить статус долга.", &MainMenu::menu_change_status_debt);
	menu.add_submenu_item(3, "Добавить запись.", &MainMenu::menu_add_debt);
	menu.add_submenu_item(3, "Удалить запись.", &MainMenu::menu_delete_debt);
	menu.add_submenu_item(3, "Назад.", true);
	
	menu.add_menu_item("Должники.");
	menu.add_submenu_item(4, "Просмотреть должников.", &MainMenu::menu_show_debtors);
	menu.add_submenu_item(4, "Изменить имя должника/название организации.", &MainMenu::menu_change_name_debtor);
	menu.add_submenu_item(4, "Изменить дату погашения долга.", &MainMenu::menu_change_date_debtor);
	menu.add_submenu_item(4, "Изменить сумму долга.", &MainMenu::menu_change_money_debtor);
	menu.add_submenu_item(4, "Изменить статус долга.", &MainMenu::menu_change_status_debtor);
	menu.add_submenu_item(4, "Добавить запись.", &MainMenu::menu_add_debtor);
	menu.add_submenu_item(4, "Удалить запись.", &MainMenu::menu_delete_debtor);
	menu.add_submenu_item(4, "Назад.", true);

	menu.add_menu_item("Среднее значение расходов за N дней.", &MainMenu::menu_average_cost);

	menu.add_menu_item("Среднее значение доходов за N дней.", &MainMenu::menu_average_income);

	menu.add_menu_item("Просмотреть значение баланса кошелька.", &MainMenu::print_show_money);

	menu.add_menu_item("Изменить значение баланса кошелька.", &MainMenu::menu_change_cash_flow);

	menu.add_menu_item("Конвертер валют.", &MainMenu::menu_currency_converter);

	menu.add_menu_item("Выход.", true);
	menu.open_menu();
		
	return 0;
}