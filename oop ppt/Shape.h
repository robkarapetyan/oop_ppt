#pragma once
#include <map>
#include "general.h"

//almost complete

class IShape{
public:
	virtual IShape* clone() = 0;
};

class Circle :public IShape{
	int radius = 0;
public:
	Circle() {}
	Circle(int r) : radius(r) {}
	IShape* clone() override { return new Circle(*this); }
};

class Rectangle :public IShape {
	Point fst;
	Point scnd;
public:
	Rectangle() {}
	Rectangle(Point a, Point b) : fst(a), scnd(b) {}
	Rectangle(int a_x, int a_y, int b_x, int b_y) : fst(a_x, a_y), scnd(b_x, b_y) {}
	void set_geometry(Point a, Point b) { fst = a; scnd = b; }
	void set_geometry(int a_x, int a_y, int b_x, int b_y) { fst.set_pos(a_x, a_y); scnd.set_pos(b_x, b_y); }
	IShape* clone() override { return new Rectangle(*this); }
};

class Triangle :public IShape {
	int alfa;
	int betta;
	int length_ab;
public:
	Triangle() {}
	void set_geometry(int fst_angle, int scnd_angle, int ab) { alfa = fst_angle; betta = scnd_angle; length_ab = ab; }
	IShape* clone() override { return new Triangle(*this); }
};


class ShapeLibrary {
	std::map<std::string, IShape*> shape_map;
public:
	ShapeLibrary() { shape_map.emplace("circle", new Circle); shape_map.emplace("rectangle", new Rectangle);  shape_map.emplace("triangle", new Triangle); }
	void register_shape(std::pair<std::string, IShape*> new_shape) { shape_map.emplace(new_shape); }
	void remove_shape(std::string shape_name) { shape_map.erase(shape_name); }

};
