#pragma once
#include "Commands.h"
#include <map>

class CommandController {
	std::map<std::string, ICommand*> cmd_map;
public:
	CommandController() {}
	size_t parse(std::string cmd_string);
};



CommandController::CommandController() {
	cmd_map.emplace("resize", new Cmd_resize);
	cmd_map.emplace("add", new Cmd_add); 
	cmd_map.emplace("remove", new Cmd_remove);
	cmd_map.emplace("rotate", new Cmd_rotate);
	cmd_map.emplace("move", new Cmd_move);
}

//trying to make an object instance with parsed string and to execute that object with correct
//command 
size_t CommandController::parse(std::string cmd_string)
{
	//parsing example str " resize (objptr) geometry "
	//										based on obj shape, geometry a,b,c or R

	//                      add    (objptr)  geometry
	//						move   objptr   new_pos
	//						remove objptr   
	//						rotate objptr   angle(int)
	if (cmd_string == "resize")
		cmd_map["resize"]->execute();
	else
		cmd_map["add"]->execute();
	return 0;
}