#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <vector>
#include <cmath>

#include "Vector2.hpp"

class Graph	{

	std::vector<Vector2> _points;
	
	public:

		Graph() {}
		~Graph() {}

		void	addPoint(Vector2 newVector2);
		void	addPoint(float x, float y);
		void	removePoint(Vector2 newVector2);
		void	removePoint(float x, float y);

		void	print();

		std::vector<Vector2>	getPoints() const {return _points;}

		class AlreadyInGraph: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Point is already in the Graph");};
		};
		class NotInGraph: public std::exception
		{
			public:
				virtual const char* what() const throw()	{
					return ("Point is not in the Graph");};
		};

};

#endif
