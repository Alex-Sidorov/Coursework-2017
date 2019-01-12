#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Main.h"
#include <Windows.h>
#include <conio.h>

template<class Type>
class Menu
{
	using Action_const = void(Type::*) ()const; //указатель на константный метод
	using Action = void(Type::*) ();			//указатель на не константный метод

public:

	void add_menu_item(std::string title, Action_const process) //добавление пункта меню
	{
		_menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_menu_item(std::string title, Action process)
	{
		_menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_menu_item(std::string title, bool exit)
	{
		_menu_items.push_back(Menu<Type>(_obj, title, exit));
	}

	void add_menu_item(std::string title)
	{
		_menu_items.push_back(Menu<Type>(_obj, title));
	}

	void add_submenu_item(int index, std::string title, Action_const process)//добавление подпункта меню
	{
		_menu_items[index]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index, std::string title, Action process)
	{
		_menu_items[index]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index, std::string title, bool process)
	{
		_menu_items[index]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index, std::string title)
	{
		_menu_items[index]._menu_items.push_back(Menu<Type>(_obj, title));
	}

	void add_submenu_item(int index_one, int index_two, std::string title, Action_const process)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index_one, int index_two, std::string title, Action process)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index_one, int index_two, std::string title, bool process)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index_one, int index_two, std::string title)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items.push_back(Menu<Type>(_obj, title));
	}

	void add_submenu_item(int index_one, int index_two, int index_three, std::string title, Action_const process)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items[index_three]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index_one, int index_two, int index_three, std::string title, Action process)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items[index_three]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index_one, int index_two, int index_three, std::string title, bool process)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items[index_three]._menu_items.push_back(Menu<Type>(_obj, title, process));
	}

	void add_submenu_item(int index_one, int index_two, int index_three, std::string title)
	{
		_menu_items[index_one]._menu_items[index_two]._menu_items[index_three]._menu_items.push_back(Menu<Type>(_obj, title));
	}

	short int work_menu() // вывод и выбор пункта меню
	{
		char ascii_kod = 0;
		
		while (1)
		{
			show_menu();

			rewind(stdin);

			ascii_kod = _getch();	

			if (ascii_kod == '\r')
				return _index_menu;
			else if (ascii_kod == 8)          //8-backspace
				return _menu_items.size() - 1;

			ascii_kod = _getch();

			change_index_menu(ascii_kod);
		}	
	}

	void open_menu()//запуск меню
	{
		_index_menu = 0;
		while (1)
		{
			rewind(stdin);
			short int index = work_menu();
			
			if (_menu_items[index]._exit == false && _menu_items[index]._process == NULL && _menu_items[index]._process_const != NULL)
				(_obj->*_menu_items[index]._process_const)();

			else if (_menu_items[index]._exit == false && _menu_items[index]._process != NULL && _menu_items[index]._process_const == NULL)
				(_obj->*_menu_items[index]._process)();
			
			else if(_menu_items[index]._exit != false)
				return;
			
			if (_menu_items[index]._menu_items.size() != 0)
				_menu_items[index].open_menu();
		}
	}

	Menu(Type &obj)
	{
		_obj = &obj;
	}

	virtual ~Menu() {};

private:

	Type *_obj; //указатель на объект класса

	std::vector<Menu<Type>> _menu_items;//вектор пунктов меню

	std::string _title;//текст пункта меню

	Action _process;
	Action_const _process_const;
	bool _exit;

	short int _index_menu;

	Menu(Type *obj, std::string title, Action_const process) : _title(title), _process_const(process), _exit(false), _process(NULL), _index_menu(0) { _obj = obj; }
	Menu(Type *obj, std::string title, Action process) : _title(title), _process(process), _exit(false), _process_const(NULL), _index_menu(0) { _obj = obj; }
	Menu(Type *obj, std::string title, bool exit) : _title(title), _process(NULL), _exit(true), _process_const(NULL), _index_menu(0) { _obj = obj; }
	Menu(Type *obj, std::string title) : _title(title), _process(NULL), _exit(false), _process_const(NULL), _index_menu(0) { _obj = obj; }

	void show_menu()
	{
		HANDLE descriptor = GetStdHandle(STD_OUTPUT_HANDLE);

		system("cls");
		for (int i = 0; i < _menu_items.size(); i++)
		{
			if (_index_menu == i)
			{
				SetConsoleTextAttribute(descriptor, 5);
				std::cout << "->";
			}
			else
				SetConsoleTextAttribute(descriptor, 15);
			std::cout << _menu_items[i]._title << std::endl;
		}
	}

	void change_index_menu(char ascii_kod)
	{
		if (ascii_kod == 72 && _index_menu != 0)     //72-стрелка вверх
			_index_menu--;
		else if (ascii_kod == 72 && _index_menu == 0)
			_index_menu = _menu_items.size() - 1;
		else if (ascii_kod == 80 && _index_menu != _menu_items.size() - 1)//80-стрелка вниз
			_index_menu++;
		else if (ascii_kod == 80 && _index_menu == _menu_items.size() - 1)
			_index_menu = 0;
	}

};