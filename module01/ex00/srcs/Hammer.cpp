#include "../includes/Hammer.hpp"

Hammer::Hammer()	{
	std::cout << "Hammer constructer called" << std::endl;
}

Hammer::~Hammer()	{
	std::cout << "Hammer destructer called" << std::endl;
}

void	Hammer::use()	{
	std::cout << "Hammer beeing used" << std::endl;
	(*this)++;
}