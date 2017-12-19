// ConvexHullAplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

//#include "Polygon.h"
#include "QuickHull.h"


int main()
{
	Polygon* p = new Polygon();
	p->addPoint(0, 0);
	p->addPoint(-8, 1);
	p->addPoint(1, 0);
	p->addPoint(7, 1);
	p->printPolygon();

	QuickHull* q = new QuickHull(p);
	Point *mypoint = q->getLeftPolygonPoint();
	Point *mypoint2 = q->getRightPolygonPoint();
	//system("pause");
}

