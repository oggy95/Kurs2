#pragma once
#include "Line.h"

class Triangle : public Line
{
	
	Line l1,l2,l3;
	COLORREF f;
public:
	int x1,y1, x2, y2, x3, y3;
	Triangle(void);
	Triangle(int x1,int y1,int x2,int y2,int x3,int y3);
	void setColorTriangle(COLORREF f);
	bool intersection(Triangle t1);
	bool st();
	double cos_a();
	double cos_b();
	double cos_c();
	void draw(CPaintDC &dc);
	~Triangle();
};

