#pragma once
#include "general.h"
#include "Shape.h"
#include <vector>

//todo  
//complete IObject
// complete constructors,(property, shape)

class IObject {

};


class ObjectBase : public IObject {
protected:
	size_t Id;
	Point position;
	int rotation;
	BoundingRect brect;
public:
	size_t get_ID() { return Id; }
};

class Object : public ObjectBase {
	IShape* shape;
public:
	
};

class Group : public ObjectBase {
	std::vector<IObject*> vec_of_objects;
public:
	void add(IObject* p) { vec_of_objects.push_back(p); } /// update brect 

	//id starting with 1
	void remove(size_t ID){
		auto it = vec_of_objects.begin() + ID - 1; 
		delete *it; 
		it = vec_of_objects.erase(it);
		///update brect
	}

	// 
	//void update_brect(){}

};