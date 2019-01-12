#pragma once

#include <iostream>

class Money//класс денег
{
public:
	void set_money(float money);//изменить значение _money

	float get_money()const;//вернуть значение _money

	friend std::ostream & operator << (std::ostream &stream, Money &obj);

	Money();
	Money(const Money &obj);
	Money(float money);

	virtual ~Money();

private:
	float _money;//сумма денег
};
