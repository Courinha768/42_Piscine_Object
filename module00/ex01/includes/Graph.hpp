#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <vector>
#include <cairo/cairo.h>
#include <math.h>
#include <sstream>

#include "Vector2.hpp"
#include "Line.hpp"

#define C_WHITE 100
#define C_BLACK 101
#define C_GREY 102
#define C_RED 103
#define C_GREEN 104
#define C_BLUE 105

#define	AXIS_WIDTH 2
#define	GRID_WIDTH 1

class Graph	{

	std::vector<Vector2>	_points;
	std::vector<Line>		_lines;

	bool	_exists(const Vector2 &point);
	bool	_exists(const Line &line);

	public:

		struct png_options	{

			int	height;
			int	width;

			bool	grid;
			bool	axis;
			bool	numbers;

			int	c_points;
			int	c_lines;
			int	c_axis;
			int c_grid;
			int c_background;

			png_options();
			~png_options();
		};

		Graph();
		Graph(const Graph &copy);
		~Graph();

		Graph&	operator=(const Graph &assign);
		bool	operator==(const Graph &graph) const;

		void	add(const Vector2 &new_point);
		void	add(float x, float y);
		void	add(const Line &new_line);
		void	add(float x1, float y1, float x2, float y2);

		void	remove(const Vector2 &new_point);
		void	remove(float x, float y);
		void	remove(const Line &new_line);
		void	remove(float x1, float y1, float x2, float y2);

		std::vector<Vector2>	getPoints() const;
		std::vector<Line>		getLines() const;

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
 
std::ostream& operator << (std::ostream& os, const Graph& graph);

void	writeToPng(const Graph &graph, const std::string &filename, const Graph::png_options &options);
void	writeToPng(const Graph &graph, const std::string &filename);

#endif
