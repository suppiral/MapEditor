/*
	# Header file for Controller class, responsible for running the loop
	# and handling events.
*/
#pragma once

#include <SFML\Graphics.hpp>
#include "macros.h"
#include "Menu.h"
#include "Canvas.h"
#include "Tile.h"
#include <vector>

const int WINDOW_WIDTH = 1802;
const int WINDOW_HEIGHT = 1005;

class Controller
{
public:
	Controller();
	~Controller();
	void display();
	void handleEvents(const sf::Event& event);
	void runLoop();

private:
	Canvas _canvas;
	std::vector<Menu*> _menus;
	sf::RenderWindow _window;

	sf::View _fixed;
	sf::View _cnvs_view;

	sf::Texture* _texture;

	Vertex _mouse_pos;

	// Menu creation
	void createMenus();
	void createActionMenu();
	void createTileMenu();

	void setWindow();

	sf::Font _font;

	int _tile;

	/// FUNCTIONS FOR ACTIONS IN BUTTONS
	void addShape(int mouse_pos_x, int mouse_pos_y);
	void setTile(int num) { _tile = num; }
	void fillTile() { _canvas.fill(_texture, _tile); }
	void loadMap() { _canvas.loadMap(_texture); }

	void Controller::display_info();
};
