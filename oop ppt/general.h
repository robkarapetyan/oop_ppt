#pragma once
class Point {
	int m_x;
	int m_y;
public:
	Point() {}
	Point(int x, int y) : m_x(x), m_y(y) {}
	void set_pos(int x, int y) { m_x = x; m_y = y; }
	Point& operator=(const Point& new_p) { if (this == &new_p) return *this; else { m_x = new_p.x(); m_y = new_p.y(); return *this; } }
	int x() const { return m_x; }
	int y() const { return m_y; }
};

// * ---
//  |  |
//  --- *
class BoundingRect {
	Point fst;
	Point scnd;
public:
	BoundingRect() {}
	BoundingRect(Point a, Point b) : fst(a), scnd(b) {}
	BoundingRect(int a_x, int a_y, int b_x, int b_y) : fst(a_x, a_y), scnd(b_x, b_y) {}
	void set_geometry(Point a, Point b) { fst = a; scnd = b; }
	void set_geometry(int a_x, int a_y, int b_x, int b_y) { fst.set_pos(a_x, a_y); scnd.set_pos(b_x, b_y); }
};