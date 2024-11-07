#ifndef LINE_HPP
# define LINE_HPP

#include <iostream>
#include "Vector2.hpp"

struct Line	{
	
	Vector2	point1;
	Vector2	point2;

	Line();
	Line(Vector2 point1, Vector2 point2);
	Line(float x1, float y1, float x2, float y2);
	Line(const Line &copy);
	~Line();

	Line& operator=(const Line &assign);

	bool operator==(const Vector2 &vector2) const;
};

std::ostream& operator << (std::ostream& os, const Vector2& vector2);

#endif