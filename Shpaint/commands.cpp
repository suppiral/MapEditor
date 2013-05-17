#include "Commands.h"
#include "Controller.h"
#include "Canvas.h"

// #################### Cnvs Void Cmd ######################
// ---------------------------------------------------------
// constructor gets: Cnvs reference and it's function to run
CnvsVoidCmd::CnvsVoidCmd(Canvas& cnvs, void (Canvas::*funcptr)()) : _cnvs(cnvs), _action(funcptr) 
{

}

// execute
void CnvsVoidCmd::execute() { (_cnvs.*_action)(); }
// ---------------------------------------------------------
// #################### Cnvs Void Cmd ######################
// ---------------------------------------------------------
// constructor gets: Canvas reference and it's function to run
AddTile::AddTile(Controller& ctrl, void (Controller::*funcptr)(int), int num) : _ctrl(ctrl), _action(funcptr), _num(num)
{
}

void AddTile::execute() { (_ctrl.*_action)(_num); }


// #################### Ctrl Void Cmd ######################
// ---------------------------------------------------------
// constructor gets: Controller reference and it's function to run
CtrlVoidCmd::CtrlVoidCmd(Controller& ctrl, void (Controller::*funcptr)()) : _ctrl(ctrl), _action(funcptr) 
{

}

// execute
void CtrlVoidCmd::execute() { (_ctrl.*_action)(); }