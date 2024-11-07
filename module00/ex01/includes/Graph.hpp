#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <cairo/cairo.h>
#include <string>
#include <sstream>
#include <math.h>

#include "Vector2.hpp"

// For anyone that is looking at this
// i believe the best solution would be to create a Line struct
// It would make more sense for things such as "LinesAreEqual", it could just be the operator ==
// And it would look a lottttt better
// Besides, I dont want to belive making a vector of type vector is, in any way, a good practice
// I'm just doing it like this for "fun" I guess
class Graph	{

	std::vector<Vector2>				_points;
	std::vector<std::vector<Vector2> >	_lines;
	
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
		std::vector<std::vector<Vector2> >	getLines() const {return _lines;}

		void	saveToPNG(const std::string &filename);

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


#endif
