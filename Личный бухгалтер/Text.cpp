#include "Text.h"

std::string Text::get_str()const
{
	return _str;
}

void Text::set_str(std::string str)
{
	_str = str;
}

std::ostream & operator << (std::ostream &stream, Text &obj)
{
	stream << obj.get_str() << std::endl;
	return stream;
}

Text::Text(std::string str)
{
	_str = str;
}

Text::Text(const Text &obj)
{
	_str = obj._str;
}

Text::Text()
{
	_str = "";
}

Text::~Text()
{}