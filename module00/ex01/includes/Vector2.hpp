#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include <iostream>

struct Vector2	{

	float x;
	float y;

	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2 &copy);
	~Vector2() {}

	Vector2& operator=(const Vector2 &assign);

	bool operator==(const Vector2 &vector2) const;

};

std::ostream& operator << (std::ostream& os, const Vector2& vector2);

#endif
