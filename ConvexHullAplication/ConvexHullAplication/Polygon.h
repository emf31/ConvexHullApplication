#pragma once
#include <vector>
#include "Point.h"

class Polygon {

public:
	std::vector<Point> points;

	Polygon();
	~Polygon();

	void addPoint(const Point p);
	void addPoint(const int x, const int y);
	void printPolygon();
};