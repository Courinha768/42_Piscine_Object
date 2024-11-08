#include "../includes/Line.hpp"

Line::Line() {

}

Line::Line(Vector2 point1, Vector2 point2)
	: point1(point1), point2(point2)	{
		
}

Line::Line(float x1, float y1, float x2, float y2)
	: point1(Vector2(x1, y1)), point2(Vector2(x2, y2)) {
	
}

Line::Line(const Line &copy)
	: point1(copy.point1), point2(copy.point2) {
	
}

Line::~Line() {

}

Line&	Line::operator=(const Line &assign)	{
	point1 = assign.point1;
	point2 = assign.point2;
	
	return *this;
}

bool Line::operator==(const Line &line) const	{
	if (point1 == line.point1 && point2 == line.point2)
		return true;
	return false;
}

std::ostream& operator << (std::ostream& os, const Line& line)	{

	os << "{" << line.point1 << ", " << line.point2 << "}";
	return (os);

}