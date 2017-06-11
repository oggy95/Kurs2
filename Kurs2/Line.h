#pragma once
class Line
{
	int x1,y1,x2,y2;
	COLORREF f;
public:
	Line();
	Line(int x1, int y1, int x2, int y2);
	double length ();
	bool inter (Line l2);
	int getX1();
	int getY1();
	int getX2();
	int getY2();
	void draw(CPaintDC &dc);
	~Line();
};

