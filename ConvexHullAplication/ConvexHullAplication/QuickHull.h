#pragma once
#include "Polygon.h"

class QuickHull
{
private:
	Polygon* polygon;
public:
	QuickHull(Polygon *p);
	~QuickHull();

	Point* getLeftPolygonPoint();
	Point* getRightPolygonPoint();
	void generatePolygonQuickHull();
	int area2(Point a, Point b, Point c);
	bool left(Point a, Point b, Point c);
	bool leftOn(Point a, Point b, Point c);
};

