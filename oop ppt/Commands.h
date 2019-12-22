#pragma once
#include <iostream>
#include <string>
#include "Shape.h"

class ICommand {
public:
	virtual void execute() = 0 {}
};


class Cmd_add : public ICommand {
	IShape* shape = nullptr;
public:
	void set_shape(IShape* shape_to_execute) {if(shape_to_execute)  }
	void execute() override { std::cout << "add" << std::endl; }

};

class Cmd_remove : public ICommand {
public:
	void execute() override { std::cout << "remove" << std::endl; }
};

class Cmd_resize : public ICommand {
public:
	void execute() override { std::cout << "resize" << std::endl; }
};

class Cmd_rotate : public ICommand {
public:
	void execute() override { std::cout << "rotate" << std::endl; }
};

class Cmd_move : public ICommand {
public:
	void execute() override { std::cout << "move" << std::endl; }
};