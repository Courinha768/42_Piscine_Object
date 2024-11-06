#include "Graph.hpp"

void	Graph::addPoint(Vector2 newVector2)	{

	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)
			throw PointAlreadyInGraph();
		it++;
	}

	_points.push_back(newVector2);
}

void	Graph::addPoint(float x, float y)	{
	
	Vector2 newVector2(x, y);
	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == newVector2)
			throw PointAlreadyInGraph();
		it++;
	}

	_points.push_back(newVector2);
}

void	Graph::removePoint(Vector2 vector2)	{

	std::vector<Vector2>::iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == vector2)	{
			_points.erase(it);
			return ;
		}
		it++;
	}
	throw PointNotInGraph();
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
	throw PointNotInGraph();

}

bool	Graph::linesAreEqual(std::vector<Vector2> line1, std::vector<Vector2> line2)	{
	std::vector<Vector2>::iterator it1 = line1.begin();
	std::vector<Vector2>::iterator it2 = line2.begin();
	
	while (it1 != line1.end() && it2 != line2.end())	{
		if (!(*it1 == *it2))
			return (false);
	}
	return true;
}

void	Graph::addLine(std::vector<Vector2> newLine)	{
	std::vector<std::vector<Vector2>>::iterator line_it = _lines.begin();

	while (line_it != _lines.end())	{
		if (linesAreEqual(*line_it, newLine))
			throw LineAlreadyInGraph();
	}

	_lines.push_back(newLine);
}

void	Graph::removeLine(std::vector<Vector2> line)	{
	std::vector<std::vector<Vector2>>::iterator line_it = _lines.begin();

	while (line_it != _lines.end())	{
		if (linesAreEqual(*line_it, line))
			_lines.erase(line_it);
	}

	throw LineNotInGraph();
}