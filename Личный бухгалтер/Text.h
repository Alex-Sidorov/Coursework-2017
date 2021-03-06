#pragma once
#include <string>
#include <iostream>

class Text
{

public:
	std::string get_str()const;   //������� �������� _str

	void set_str(std::string str);//�������� �������� ���������� _str 
	
	friend std::ostream & operator << (std::ostream &stream, Text &obj);

	Text();
	Text(const Text &obj);
	Text(std::string str);
	
	virtual ~Text();

private:
	std::string _str;
};
