#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include <iostream>

struct Vector2	{

		float x;
		float y;

		Vector2(): x(0), y(0) {}
		Vector2(float x, float y): x(x), y(y) {}
		~Vector2() {}

		bool operator==(const Vector2 &vector2) const;

};

#endif
