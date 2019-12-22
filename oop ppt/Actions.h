#pragma once

enum class Type{ add, remove, resize, rotate, move };

class IAction {
protected:
	Type a;
public:
	virtual IAction* apply() = 0;
	virtual Type type() = 0;
	virtual ~IAction() {}
};

class Remove_action;

//adds object to slideshow,with commandcontroller's add, frees redo stack
//pushs to undo stack Remove_action(with that object) 
class Add_action : public IAction { 
public:
	Add_action() { a = Type::add; }
	Type type() { return a; }
	IAction* apply() { return new Remove_action; }
};

//(redo stack Add_action(with that object))nope

//hides object from slide, pushs to undo stack Add_action(with that object)
//if undo stack is full removes bottom action from stack
//frees redo stack
class Remove_action : public IAction {
public:
	Remove_action() {a = Type::add;}
	Type type() { return a; }
	IAction* apply() { return new Add_action; }
};

//pushs to undo stack (Resize_action(with current size)) and resizes obj with 
//command controller's resize()
//frees redo stack
class Resize_action : public IAction {
public:
	Resize_action() { a = Type::resize; }
	Type type() { return a; }
	IAction* apply() { return new Resize_action; }
};

//same as resize, only pushs to undo stack (Rotate_action(with opposite to received angle)
//frees redo stack
class Rotate_action : public IAction {
public:
	Rotate_action() { a = Type::rotate; }
	Type type() { return a; }
	IAction* apply() { return new Rotate_action; }
};

//same as rotate (with opposite to received) e.g current(5,5) move to (10,10)
//pushs to undo stack (Move_action with(-10,10))
class Move_action : public IAction {
public:
	Move_action() { a = Type::move; }
	Type type() { return a; }
	IAction* apply() { return new Move_action; }
};

//
////if undo stack isnt empty pops from it and pushs to redo stack opposite action
//class Undo_action : public IAction {
//public:
//	Undo_action() { a = Type::undo; }
//	Type type() { return a; }
//	IAction* apply() { return new Redo_action; }
//};
//
////pops from redo stack and pushs to undo stack oposite action of popped one
//class Redo_action : public IAction {
//public:
//	Redo_action() { a = Type::redo; }
//	Type type() { return a; }
//};

