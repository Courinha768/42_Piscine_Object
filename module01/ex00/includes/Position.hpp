#ifndef POSITION_HPP
# define POSITION_HPP

#include <iostream>

struct	Position	{

	int	x;
	int y;
	int z;

	Position()						: x(0), y(0), z(0)
	{std::cout << "Position default constructer called" << std::endl;}
	Position(int x, int y)			: x(x), y(y), z(0)
	{std::cout << "Position 2d constructer called" << std::endl;}
	Position(int x, int y, int z)	: x(x), y(y), z(z)
	{std::cout << "Position full constructer called" << std::endl;}
	~Position()
	{std::cout << "Position destructer called" << std::endl;}

};

#endif