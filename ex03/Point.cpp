#include "Point.hpp"

Point::Point()
{
}
Point::~Point()
{
}
Point::Point(const Point &other)
{
	*this = other;
}
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
	}
	return *this;
}
