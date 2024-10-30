#include "Graph.hpp"

void	Graph::addPoint(Vector2 newVector2)	{

	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)
			throw AlreadyInGraph();
		it++;
	}

	_points.push_back(newVector2);
}

void	Graph::addPoint(float x, float y)	{
	
	Vector2 newVector2(x, y);
	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)
			throw AlreadyInGraph();
		it++;
	}

	_points.push_back(newVector2);
}

void	Graph::removePoint(Vector2 newVector2)	{

	std::vector<Vector2>::iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)	{
			_points.erase(it);
			return ;
		}
		it++;
	}
	throw NotInGraph();
}

void	Graph::removePoint(float x, float y)	{

	Vector2 newVector2(x, y);
	std::vector<Vector2>::iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)	{
			_points.erase(it);
			return ;
		}
		it++;
	}
	throw NotInGraph();

}

void	Graph::print()	{

	int	max_height	= 0;
	int	min_height	= 0;
	int	max_width	= 0;
	int	min_width	= 0;

	std::vector<Vector2>::iterator it = _points.begin();

	while (it != _points.end())	{
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

	it = _points.begin();
	while (it != _points.end())	{
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
