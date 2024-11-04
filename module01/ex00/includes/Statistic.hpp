#ifndef STATISTIC_HPP
# define STATISTIC_HPP

#include <iostream>

struct Statistic	{

	int	level;
	int	xp;

	Statistic()						: level(0), xp(0)
	{std::cout << "Statistic default constructer called" << std::endl;}
	Statistic(int level)			: level(level), xp(0)
	{std::cout << "Statistic level constructer called" << std::endl;}
	Statistic(int level, int xp)	: level(level), xp(xp)
	{std::cout << "Statistic full constructer called" << std::endl;}
	~Statistic()
	{std::cout << "Statistic destructer called" << std::endl;}

};

#endif