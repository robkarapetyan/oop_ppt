#pragma once
#include <stack>
#include "Actions.h"

class ActionController {
	std::stack<IAction*> undo_stack;
	std::stack<IAction*> redo_stack;
public:
	void Do(IAction*);
	void undo();
	void redo();
};