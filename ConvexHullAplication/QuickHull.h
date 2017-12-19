#pragma once
#include "Polygon.h"

class QuickHull
{
private:
	//conjunto de puntos inicial
	Polygon* polygon;

	//metodo recursivo que calcula los puntos del poligono convexo
	std::vector<Point> quickHull(const Point a, const Point b, const std::vector<Point> S);

	//obtiene todos los puntos a la derecha de a-b de vector S
	std::vector<Point> getAllRightPoints(const Point a, const Point b, const std::vector<Point> S);

	//obtiene todos los puntos a la izquierda de a-b del vector S
	std::vector<Point> getAllLeftPoints(const Point a, const Point b, const std::vector<Point> S);

public:
	QuickHull(Polygon *p);
	~QuickHull();

	//Devuelve el punto mas a la izquierda del poligono
	Point getLeftPolygonPoint();

	//Devuelve el punto mas a la derecha del poligono
	Point getRightPolygonPoint();

	//metodo que se llama y se devuelven los puntos que forman el poligono convexo
	std::vector<Point> generatePolygonQuickHull();

	//Obtiene el punto mas alejado del vector S de a-b
	Point getPointmaxDistance(const Point a, const Point b, const std::vector<Point> S);

	//calculo del area del paralepipedo de 3 puntos
	int area2(const Point a, const Point b, const Point c);

	//Devuelve si el punto c esta a la izquierda de a-b
	bool left(const Point a, const Point b, const Point c);

	//Devuelve si el punto c esta a la derecha de a-b
	bool right(const Point a, const Point b, const Point c);

	//Devuelve si el punto c esta a la izquierda o en linea de a-b
	bool leftOn(const Point a, const Point b, const Point c);
	
};

