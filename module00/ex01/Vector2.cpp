#include "Vector2.hpp"

bool Vector2::operator==(const Vector2 &vector2) const	{
	if (x == vector2.x && y == vector2.y)
		return true;
	return false;
}

std::ostream& operator << (std::ostream& os, const Vector2& vector2)	{

	std::cout << "(" << vector2.x << ", " << vector2.y << ")";
	return (os);

}