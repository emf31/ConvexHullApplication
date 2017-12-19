#include "stdafx.h"
#include "QuickHull.h"




std::vector<Point> QuickHull::quickHull(const Point a, const Point b, const std::vector<Point> S)
{
	/*Se compreba que el vector no este vacio(no hay mas puntos posibles)
	Despues se calcula el vector de puntos a la izq y der de a-b
	De le pasa recursivamente a-c con los puntos a la izquierda y el c-b con los puntos a la derecha
	Los 2 vectores resultantes se juntan y se añaden a la solucion final
	*/
	if (!S.empty()) {
		Point c = (getPointmaxDistance(a, b, S));
		std::vector<Point> A = getAllLeftPoints(a, c, S);
		std::vector<Point> B = getAllLeftPoints(c, b, S);
		std::vector<Point> rVector1 = quickHull(a, c, A);
		std::vector<Point> rVector2 = quickHull(c, b, B);
		std::vector<Point> rVector = rVector1;
		rVector.push_back(c);
		rVector.insert(rVector.end(), rVector2.begin(), rVector2.end());
		return rVector;
	}
	return(a,b,std::vector<Point>());
}

std::vector<Point> QuickHull::getAllRightPoints(const Point a, const Point b, std::vector<Point> S)
{
	std::vector<Point> rightPoints;
	for (std::vector<Point>::iterator it = S.begin(); it != S.end(); ++it) {
		if (right(a, b, *it)) {
			rightPoints.push_back(*it);
		}
	}
	return rightPoints;
}

std::vector<Point> QuickHull::getAllLeftPoints(const Point a, const Point b, std::vector<Point> S)
{
	std::vector<Point> leftPoints;
	for (std::vector<Point>::iterator it = S.begin(); it != S.end(); ++it) {
		if (left(a, b, *it)) {
			leftPoints.push_back(*it);
		}
	}
	return leftPoints;
}

QuickHull::QuickHull(Polygon * p)
{
	polygon = p;
}

QuickHull::~QuickHull()
{
}

Point QuickHull::getLeftPolygonPoint()
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
	return leftpoint;
}

Point QuickHull::getRightPolygonPoint()
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
	return rightpoint;
}

std::vector<Point> QuickHull::generatePolygonQuickHull()
{
	/*Primero se obtienen los puntos mas extremos y se calculan los vectores de puntos a la derecha y a la izquierda
	Se calcula el quickull a la derecha y a la izquireda
	Una vez calculado se juntan y es la solucion final del poligono convexo
	*/
	Point left = getLeftPolygonPoint();
	Point right = getRightPolygonPoint();
	std::vector<Point> vleft = getAllLeftPoints(left,right, polygon->points);
	std::vector<Point> vright = getAllRightPoints(left, right, polygon->points);

	std::vector<Point> v1 = quickHull(left, right, vleft);
	v1.push_back(right);
	std::vector<Point> v2 = quickHull(right, left, vright);
	std::vector<Point> v = v1;
	v.insert(v.end(), v2.begin(), v2.end());
	v.push_back(left);

	polygon->points = v;
	polygon->printPolygon();
	return v;


}

Point QuickHull::getPointmaxDistance(const Point a, const Point b, std::vector<Point> S)
{
	Point PointMaxDistance=S.front();
	int maxDistance = area2(a, b, PointMaxDistance);
	for (std::vector<Point>::iterator it = S.begin(); it != S.end(); ++it) {
		int tdistance = area2(a, b, *it);
		if (tdistance > maxDistance) {
			maxDistance = tdistance;
			PointMaxDistance = *it;
		}
	}
	return PointMaxDistance;
}

int QuickHull::area2(const Point a,const Point b, const Point c)
{
	return((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y));
}

bool QuickHull::left(const Point a, const Point b, const Point c)
{
	return area2(a,b,c)>0;
}

bool QuickHull::right(const Point a, const Point b, const Point c)
{
	return area2(a, b, c)<0;
}

bool QuickHull::leftOn(const Point a, const Point b, const Point c)
{
	return area2(a, b, c)>=0;
}
