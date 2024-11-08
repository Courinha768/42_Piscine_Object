#include "../../includes/Graph.hpp"

#define ARRAY_SIZE 51

std::ostream& operator << (std::ostream& os, const Graph& graph)	{

	char map[ARRAY_SIZE][ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++)	{
		for (int j = 0; j < ARRAY_SIZE; j++)	{
			if (i == floor(ARRAY_SIZE / 2) && j == floor(ARRAY_SIZE / 2))
				map[i][j] = '+';
			else if (i == floor(ARRAY_SIZE / 2))
				map[i][j] = '-';
			else if (j == floor(ARRAY_SIZE / 2))
				map[i][j] = '|';
			else
				map[i][j] = ' ';
		}
	}

	std::vector<Vector2>			points = graph.getPoints();
	std::vector<Vector2>::iterator	it = points.begin();
	while (it != points.end())	{
		if (round(it->x) + floor(ARRAY_SIZE / 2) > 0 && round(it->x) + floor(ARRAY_SIZE / 2) < ARRAY_SIZE
				&& round(it->y) + floor(ARRAY_SIZE / 2) > 0 && round(it->y) + floor(ARRAY_SIZE / 2) < ARRAY_SIZE)
			map[int(-1 * round(it->y) + floor(ARRAY_SIZE / 2))][int(round(it->x) + floor(ARRAY_SIZE / 2))] = 'X';
		it++;
	}

	for (int i = 0; i < ARRAY_SIZE; i++)	{
		for (int j = 0; j < ARRAY_SIZE; j++)	{
			os << map[i][j];
		}
		std::cout << std::endl;
	}

	return os;

}