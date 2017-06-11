#include "StdAfx.h"
#include "Line.h"
#include "math.h"


Line::Line()
{

}

Line::Line(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

int Line::getY1(void)
{
	return y1;
}
int Line::getY2(void)
{
	return y2;
}
int Line::getX1(void)
{
	return x1;
}
int Line::getX2(void)
{
	return x2;
}

void Line::draw(CPaintDC &dc)
{
	dc.MoveTo(this->x1, this->y1);
	dc.LineTo(this->x2, this->y2);
}



bool Line::inter(Line l2)
{
	int x3 = l2.getX1();
	int y3 = l2.getY1();
	int x4 = l2.getX2();
	int y4 = l2.getY2();

	double A1 = y2 - y1; 
	double B1 = x1 - x2; 
	double C1 = - A1 * x1 - B1 * y1; 

	double A2 = y4 - y3; 
	double B2 = x3 - x4; 
	double C2 = -A2 * x3 - B2 * y3;

	double f1 = A1 * x3 + B1 * y3 + C1; 
	double f2 = A1 * x4 + B1 * y4 + C1; 
	double f3 = A2 * x1 + B2 * y1 + C2; 
	double f4 = A2 * x2 + B2 * y2 + C2; 

	bool intersect = (f1 * f2 < 0 && f3 * f4 < 0);
	return intersect;
}

double Line::length ()
{
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx*dx + dy*dy);
}

Line::~Line(void)
{

}
