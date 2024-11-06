#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <vector>
#include <cmath>

#include "Vector2.hpp"

//For anyone that is looking at this
//i believe the best solution would be to create a Line struct
//It would make more sense for things such as "LinesAreEqual", it could just be the operator ==
//And it would look a lottttt better
//Besides, I dont want to belive making a vector of type vector is, in any way, a good practice
//I'm just doing it like this for "fun" I guess
class Graph	{

	std::vector<Vector2>				_points;
	std::vector<std::vector<Vector2>>	_lines;
	
	bool					linesAreEqual(std::vector<Vector2> vector1, std::vector<Vector2> vector2);

	public:

		Graph() {}
		~Graph() {}

		void	addPoint(Vector2 newVector2);
		void	addPoint(float x, float y);
		void	removePoint(Vector2 vector2);
		void	removePoint(float x, float y);

		void	addLine(std::vector<Vector2> newLine);
		void	removeLine(std::vector<Vector2> Line);


		std::vector<Vector2>				getPoints() const {return _points;}
		std::vector<std::vector<Vector2>>	getLines() const {return _lines;}

		class PointAlreadyInGraph: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Point is already in the Graph");};
		};
		class LineAlreadyInGraph: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Line is already in the Graph");};
		};
		class PointNotInGraph: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Point is not in the Graph");};
		};
		class LineNotInGraph: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Line is not in the Graph");};
		};

};

std::ostream& operator << (std::ostream& os, const Graph& bank)	{

	int	max_height	= 0;
	int	min_height	= 0;
	int	max_width	= 0;
	int	min_width	= 0;

	std::vector<Vector2>::iterator it = bank.getPoints().begin();

	while (it != bank.getPoints().end())	{
		if (max_height < it->y)
			max_height = it->y;
		if (min_height > it->y)
			min_height = it->y;
		if (max_width < it->x)
			max_width = it->x;
		if (min_width > it->x)
			min_width = it->x;
		it++;
	}
	max_height++;
	min_height--;
	max_width++;
	min_width--;

	// std::cout << max_height << std::endl;
	// std::cout << min_height << std::endl;
	// std::cout << max_width << std::endl;
	// std::cout << min_width << std::endl;

	int	height = max_height - min_height + 1;
	int	width = max_width - min_width + 1;

	char	ASCIImap[height][width];

	// std::cout << height << std::endl;
	// std::cout << width << std::endl;

	for (int i = 0; i < height; i++)	{
		for (int j = 0; j < width; j++)	{
			if (i == height - abs(min_height) - 1 && j == abs(min_width))
				ASCIImap[i][j] = '+';
			else if (i == height - abs(min_height) - 1)
				ASCIImap[i][j] = '-';
			else if (j == abs(min_width))
				ASCIImap[i][j] = '|';
			else
				ASCIImap[i][j] = ' ';
		}
	}

	it = bank.getPoints().begin();
	while (it != bank.getPoints().end())	{
		// std::cout << (int)round(it->x) << std::endl;
		ASCIImap[height - (int)round(it->y) + min_height - 1][(int)round(it->x) + abs(min_width)] = 'X';
		it++;
	}

	for (int i = 0; i < height; i++)	{
		if ((height - i - 1 - abs(min_height)) % 10 >= 0)
			std::cout << " ";
		std::cout << (height - i - 1 - abs(min_height)) % 10;
		for (int j = 0; j < width; j++)	{
			std::cout << ASCIImap[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "  ";
	for (int j = 0; j < width; j++)	{
		std::cout << abs((j + min_width) % 10);
	}
	std::cout << std::endl;
}

#endif
