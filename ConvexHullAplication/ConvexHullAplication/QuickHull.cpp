#include "stdafx.h"
#include "QuickHull.h"



QuickHull::QuickHull(Polygon * p)
{
	polygon = p;
}

QuickHull::~QuickHull()
{
}

Point* QuickHull::getLeftPolygonPoint()
{
	Point leftpoint;
	if (polygon != NULL && !polygon->points.empty()) {

		std::vector<Point> p = polygon->points;
		leftpoint = p.front();
		for (std::vector<Point>::iterator it = p.begin(); it != p.end(); ++it) {
			if (it->x < leftpoint.x) {
				leftpoint = *it;
			}
		}
	}
	return &leftpoint;
}

Point * QuickHull::getRightPolygonPoint()
{
	Point rightpoint;
	if (polygon != NULL && !polygon->points.empty()) {

		std::vector<Point> p = polygon->points;
		rightpoint = p.front();
		for (std::vector<Point>::iterator it = p.begin(); it != p.end(); ++it) {
			if (it->x > rightpoint.x) {
				rightpoint = *it;
			}
		}
	}
	return &rightpoint;
}

void QuickHull::generatePolygonQuickHull()
{

}

int QuickHull::area2(Point a, Point b, Point c)
{
	return((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y));
}

bool QuickHull::left(Point a, Point b, Point c)
{
	return area2(a,b,c)>0;
}

bool QuickHull::leftOn(Point a, Point b, Point c)
{
	return area2(a, b, c)>=0;
}
