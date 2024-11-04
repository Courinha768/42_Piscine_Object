#include "../includes/Shovel.hpp"

Shovel::Shovel()	{
	std::cout << "Shovel constructer called" << std::endl;
}

Shovel::~Shovel()	{
	std::cout << "Shovel destructer called" << std::endl;
}

void	Shovel::use()	{
	std::cout << "Shovel beeing used" << std::endl;
	(*this)++;
}