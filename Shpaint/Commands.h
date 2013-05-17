// In this file is the definition of a few command classes.
// a command class holds an certain execution that can be executed by pressing a button for instance.

#pragma once

#include "Command.h"
#include "Controller.h"
#include "Canvas.h"
#include "Tile.h"

// runs a Controller's function with the signature: void <funcname>()
class CnvsVoidCmd : public Command
{
public:
	CnvsVoidCmd(Canvas& canvas, void (Canvas::*funcptr)());
	void execute();
private:
	Canvas& _cnvs;
	void (Canvas::*_action)();
};

class CtrlVoidCmd : public Command
{
public:
	CtrlVoidCmd(Controller& _ctrl, void (Controller::*funcptr)());
	void execute();
private:
	Controller& _ctrl;
	void (Controller::*_action)();
};

// runs a Canvas's function with the signature: void <funcname>()
class AddTile : public Command
{
public:
	AddTile(Controller& ctrl, void (Controller::*funcptr)(int), int num);
	void execute();
private:
	void (Controller::*_action)(int);
	Controller& _ctrl;
	int _num;
};
