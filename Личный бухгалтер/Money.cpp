#include "Money.h"

float Money::get_money()const
{
	return _money;
}

void Money::set_money(float money)
{
	_money = money;
}

std::ostream & operator << (std::ostream &stream, Money &obj)
{
	stream << obj.get_money();
	return stream;
}

Money::Money(const Money &obj)
{
	_money = obj._money;
}

Money::Money()
{
	_money = 0;
}

Money::Money(float money)
{
	_money = money;
}

Money::~Money(){}