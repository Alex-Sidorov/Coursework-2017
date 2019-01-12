#pragma once
#include <string>
#include <iostream>

class Text
{

public:
	std::string get_str()const;   //вернуть значение _str

	void set_str(std::string str);//изменить значение переменной _str 
	
	friend std::ostream & operator << (std::ostream &stream, Text &obj);

	Text();
	Text(const Text &obj);
	Text(std::string str);
	
	virtual ~Text();

private:
	std::string _str;
};
