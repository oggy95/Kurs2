#include "StdAfx.h"
#include "Triangle.h"
#include "Line.h"

Triangle::Triangle(void)
{

}

Triangle::Triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
	this->x1=x1;
	this->x2=x2;
	this->x3=x3;
	this->y1=y1;
	this->y2=y2;
	this->y3=y3;
	l1 = Line(x1,y1,x2,y2);
	l2 = Line(x2,y2,x3,y3);
	l3 = Line(x3,y3,x1,y1);
}

bool Triangle::intersection(Triangle t1)
{
	Line l4 = t1.l1;
	Line l5 = t1.l2;
	Line l6 = t1.l3;
	if((l1.inter(l4))||(l1.inter(l5))||(l1.inter(l6)))
		return TRUE;
	else if((l2.inter(l4))||(l2.inter(l5))||(l2.inter(l6)))
		return TRUE;
	else if((l3.inter(l4))||(l3.inter(l5))||(l3.inter(l6)))
		return TRUE;
	else return FALSE;
}

double Triangle::cos_a()
{
	double a = l1.length();
	double b = l2.length();
	double c = l3.length();
	return (c*c + b*b - a*a)/2*c*b;
}

double Triangle::cos_b()
{
	double a = l1.length();
	double b = l2.length();
	double c = l3.length();
	return (a*a + c*c - b*b)/2*a*c;
}

double Triangle::cos_c()
{
	double a = l1.length();
	double b = l2.length();
	double c = l3.length();
	return (a*a + b*b - c*c)/2*a*b;
}

bool Triangle::st()
{
	double a = l1.length();
	double b = l2.length();
	double c = l3.length();
	double cos_a = (c*c + b*b - a*a)/2*c*b;
	double cos_b = (a*a + c*c - b*b)/2*a*c;
	double cos_c = (a*a + b*b - c*c)/2*a*b;
	if(cos_a<0||cos_b<0||cos_c<0)
		return TRUE;
	else return FALSE;
}

 void Triangle::draw(CPaintDC &dc)
{
	CPen pen(PS_SOLID,3,f);
	dc.SelectObject(&pen);
	l1.draw(dc);
	l2.draw(dc);
	l3.draw(dc);
}

void Triangle::setColorTriangle(COLORREF f)
{
	this->f=f;
}

Triangle::~Triangle()
{
	
}
