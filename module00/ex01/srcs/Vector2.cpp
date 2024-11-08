#include "../includes/Vector2.hpp"

Vector2::Vector2(): x(0), y(0) {

}

Vector2::Vector2(float x, float y): x(x), y(y) {
	
}

Vector2::Vector2(const Vector2 &copy): x(copy.x), y(copy.y) {
	
}

Vector2::~Vector2() {

}

Vector2&	Vector2::operator=(const Vector2 &assign)	{
	x = assign.x;
	y = assign.y;
	
	return *this;
}

bool Vector2::operator==(const Vector2 &vector2) const	{
	if (x == vector2.x && y == vector2.y)
		return true;
	return false;
}

std::ostream& operator << (std::ostream& os, const Vector2& vector2)	{

	os << "(" << vector2.x << ", " << vector2.y << ")";
	return (os);

}