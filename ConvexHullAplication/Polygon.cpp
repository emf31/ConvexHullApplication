#include "stdafx.h"
#include "Polygon.h"
#include <iostream>

Polygon::Polygon()
{
}

Polygon::~Polygon()
{
	points.clear();
}

void Polygon::addPoint(const Point p)
{
	points.push_back(p);
}

void Polygon::addPoint(const int x, const int y)
{
	points.push_back(Point(x, y));
}

const void Polygon::printPolygon()
{
	for (std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it)
		std::cout << "Point: ("<< (it)->x <<","<< (it)->y<<")"<<std::endl;
}
