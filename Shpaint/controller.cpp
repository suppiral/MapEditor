// # source file for Controller class.


#include "Controller.h"
#include "Commands.h"
#include <sstream>
#include "Utility.h"

// ----- controller macros -------
const float MOUSE_POS_POS_X = 698;
const float MOUSE_POS_POS_Y = 546;
const int FONT_SIZE = 13;

const int SIDES_MENU_WIDTH = 2;
const int SIDES_MENU_HEIGHT = 8;
const int BOTTOM_MENU_WIDTH = 12;
const int BOTTOM_MENU_HEIGHT = 1;
const int COLOR_MENU_POS_X = 628;
const int SHAPE_MENU_POS_Y = 500;
// ------------------------------


// constructors
Controller::Controller() : _tile(0), _mouse_pos(BAD,BAD)
{
	createMenus();
	setWindow();
	// texture
	_texture = new sf::Texture;
	loadTexture(*_texture, tiles_filename, TILE_MAP_SIZE_W, TILE_MAP_SIZE_H);
}
// destructor
Controller::~Controller()
{
	// delete menus
	for (unsigned i = 0; i < _menus.size(); i++)
		delete _menus[i];
}
/// set the window
void Controller::setWindow()
{
	// create window
	_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Map Editor V1.0");
	
	
	_window.setVerticalSyncEnabled(true); // set refresh rate as screen's refresh rate
	_window.setJoystickThreshold(10000); // joystick threshold

	_fixed = _window.getView();
	_cnvs_view.reset(sf::FloatRect(0.f, 0.f, float(MAP_SIZE_W*TILE_SIZE), float(MAP_SIZE_H*TILE_SIZE)));
	_cnvs_view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	
}

// the main loop
void Controller::runLoop()
{
	while (_window.isOpen())
	{
		display();
		sf::Event event;
		_window.waitEvent(event);
		handleEvents(event);
	}
}

// display to screen
void Controller::display()
{
	_window.clear();

//	_window.setView(_cnvs_view);
	_canvas.display(_window);


//	_window.setView(_fixed);
	// draw menus
	for (unsigned i = 0; i < _menus.size(); i++)
		_menus[i]->display(_window);
	
	// draw information about the shapes
//	display_info();
		// draw shapes


	// display
	_window.display();
}

/*

// draw information about the shapes
void Controller::display_info()
{

	// write coordinates on canvas (if on canvas)
	if (_mouse_pos.x > BAD)
	{
		std::stringstream msstr;
		msstr << "(" << _mouse_pos.x << "," << _mouse_pos.y << ")";
		sf::Text mouse_pos(msstr.str(), sf::Font::getDefaultFont(), FONT_SIZE);
		mouse_pos.setColor(sf::Color::Black);
		mouse_pos.setPosition(MOUSE_POS_POS_X, MOUSE_POS_POS_Y);

		// draw
		_window.draw(mouse_pos);
	}
}
*/

// handle events
void Controller::handleEvents(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed: // X button has been pressed
		exit(EXIT_SUCCESS);
		break;

	case sf::Event::MouseButtonPressed: // Mouse Button pressed:
		// on canvas
		if (_canvas.is_in_canvas(event.mouseButton.x, event.mouseButton.y))
			addShape(event.mouseButton.x, event.mouseButton.y);

		else // on menu
			for (unsigned i = 0; i < _menus.size(); i++)
				_menus[i]->execute(event.mouseButton.x, event.mouseButton.y); // execute button command
		break;

	case sf::Event::MouseMoved: // moving mouse. save mouse position and display coordinates if on canvas
		if (_canvas.is_in_canvas(event.mouseMove.x, event.mouseMove.y))
		{
			_mouse_pos.x = event.mouseMove.x - 128;
			_mouse_pos.y = event.mouseMove.y;
		}
		else // not on canvas
		{
			_mouse_pos.x = BAD;
			_mouse_pos.y = BAD;
		}

		break;
	}
}


// adds a shape to the canvas where the user has clicked
void Controller::addShape(int mouse_pos_x, int mouse_pos_y)
{
	_canvas.addTile(Tile(_texture, _tile), Vertex(mouse_pos_x, mouse_pos_y));

}

// Menu creation
void Controller::createMenus() 
{
	createActionMenu();
	createTileMenu();

}
// creates the action menu
void Controller::createTileMenu() 
{ 
	// creates a menu at 0,0 with <SIDES_MENU_WIDTH> buttons in a line and <SIDES_MENU_HEIGHT> buttons in a column with action buttons texture
	Menu* action_menu = new Menu(Vertex(MAP_SIZE_W*TILE_SIZE,0), Vertex(3, TILE_MAP_SIZE_H*TILE_MAP_SIZE_W/3), tiles_filename);
	
	// add buttons: pic_mark and command

	for (int i = 0; i < TILE_MAP_SIZE_W * TILE_MAP_SIZE_H; i++)
		action_menu->add(i, new AddTile(*this, &Controller::setTile, i+1));

	// push menu
	_menus.push_back(action_menu);
}

// creates the action menu
void Controller::createActionMenu() 
{ 
	// creates a menu at 0,0 with <SIDES_MENU_WIDTH> buttons in a line and <SIDES_MENU_HEIGHT> buttons in a column with action buttons texture
	Menu* action_menu = new Menu(Vertex(0,MAP_SIZE_W*TILE_SIZE), Vertex(5, 1), act_btn_txt_filename);
	
	// add buttons: pic_mark and command
	action_menu->add(4, new CnvsVoidCmd(_canvas, &Canvas::clearShapes));
	action_menu->add(5, new AddTile(*this, &Controller::setTile, 0));
	action_menu->add(10, new CtrlVoidCmd(*this, &Controller::fillTile));
	action_menu->add(8, new CnvsVoidCmd(_canvas, &Canvas::saveMap));
	action_menu->add(9, new CtrlVoidCmd(*this, &Controller::loadMap));

	// push menu
	_menus.push_back(action_menu);
}