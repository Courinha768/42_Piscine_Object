#include "../includes/Graph.hpp"

Graph::Graph()	{

}

Graph::Graph(const Graph &copy)
	: _points(copy.getPoints()), _lines(copy.getLines()) {

}

Graph::~Graph()	{

}

Graph&	Graph::operator=(const Graph &assign)	{
	_points = assign.getPoints();
	_lines = assign.getLines();
	return *this;
}

bool	Graph::operator==(const Graph &graph) const	{
	std::vector<Vector2>::const_iterator _points_it = _points.begin();
	std::vector<Vector2> points = graph.getPoints();
	std::vector<Vector2>::const_iterator points_it = points.begin();

	while (_points_it != _points.end() && points_it != points.end())	{
		if (!(*_points_it == *points_it))
			return false;
		_points_it++;
		points_it++;
	}

	std::vector<Line>::const_iterator _lines_it = _lines.begin();
	std::vector<Line> lines = graph.getLines();
	std::vector<Line>::const_iterator lines_it = lines.begin();
	while (_lines_it != _lines.end() && lines_it != lines.end())	{
		if (!(*_lines_it == *lines_it))
			return false;
		_lines_it++;
		lines_it++;
	}

	return true;
}

bool	Graph::_exists(const Vector2 &point)	{
	std::vector<Vector2>::const_iterator it = _points.begin();

	while (it != _points.end())	{
		if (*it == point)
			return true;
		it++;
	}
	return false;
}

bool	Graph::_exists(const Line &line)	{
	std::vector<Line>::const_iterator it = _lines.begin();

	while (it != _lines.end())	{
		if (*it == line)
			return true;
		it++;
	}
	return false;
}

void	Graph::add(const Vector2 &new_point)	{
	if (_exists(new_point))
		throw PointAlreadyInGraph();
	_points.push_back(new_point);
}

void	Graph::add(float x, float y)	{
	if (_exists(Vector2(x, y)))
		throw PointAlreadyInGraph();
	_points.push_back(Vector2(x, y));
}

void	Graph::add(const Line &new_line)	{
	if (_exists(new_line))
		throw LineAlreadyInGraph();
	_lines.push_back(new_line);
}

void	Graph::add(float x1, float y1, float x2, float y2)	{
	if (_exists(Line(x1, y1, x2, y2)))
		throw LineAlreadyInGraph();
	_lines.push_back(Line(x1, y1, x2, y2));
}

void	Graph::remove(const Vector2 &new_point)	{
	if (!_exists(new_point))
		throw PointNotInGraph();
	_points.push_back(new_point);
}

void	Graph::remove(float x, float y)	{
	if (!_exists(Vector2(x, y)))
		throw PointNotInGraph();
	_points.push_back(Vector2(x, y));
}

void	Graph::remove(const Line &new_line)	{
	if (!_exists(new_line))
		throw LineNotInGraph();
	_lines.push_back(new_line);
}

void	Graph::remove(float x1, float y1, float x2, float y2)	{
	if (!_exists(Line(x1, y1, x2, y2)))
		throw LineNotInGraph();
	_lines.push_back(Line(x1, y1, x2, y2));
}

std::vector<Vector2>	Graph::getPoints() const	{
	return (_points);
}

std::vector<Line>	Graph::getLines() const	{
	return (_lines);
}

Graph::png_options::png_options()
	:	height(1000),
		width(1000),
		grid(true),
		axis(true),
		numbers(true),
		c_points(C_RED),
		c_lines(C_BLUE),
		c_axis(C_BLACK),
		c_grid(C_GREY),
		c_background(C_WHITE)
{}

Graph::png_options::~png_options()	{

}