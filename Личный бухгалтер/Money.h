#pragma once

#include <iostream>

class Money//����� �����
{
public:
	void set_money(float money);//�������� �������� _money

	float get_money()const;//������� �������� _money

	friend std::ostream & operator << (std::ostream &stream, Money &obj);

	Money();
	Money(const Money &obj);
	Money(float money);

	virtual ~Money();

private:
	float _money;//����� �����
};
