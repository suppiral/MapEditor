/*
 * Source file for class Menu.
*/
#include "Menu.h"
#include "Button.h"
#include "Utility.h"

// Menu's outer rectangle's border thickness 
const float OUTLINE_THICKNESS = 2.f;


// Constructor sets the location and size of the menu
// size is the number of buttons in each row and column
// gets: location, size and button texture filename
Menu::Menu(const Vertex& loc, const Vertex& size, const std::string btn_texture_filename) 
			: _size(size), _rect(sf::Vector2f(float(size.x*BTN_SIZE), float(size.y*BTN_SIZE)))
{
	// init background
	_rect.setPosition(sf::Vector2f(float(loc.x), float(loc.y)));
	_rect.setOutlineThickness(OUTLINE_THICKNESS);
	_rect.setOutlineColor(sf::Color::Black);
	loadTexture(_btn_texture, btn_texture_filename);
}

// destructor
Menu::~Menu()
{
	// delete buttons
	for (unsigned i = 0; i < _buttons.size(); i++)
		delete _buttons[i];
}
// add new button
// gets: pic mark on texture and command to execute
// return success
bool Menu::add(int pic_mark, Command* cmd)
{
	// if the buttons space is full
	if (unsigned(_size.x*_size.y) <= _buttons.size())
		return false;

	// set new location
	Vertex loc(int(_rect.getPosition().x) + (_buttons.size() % _size.x) * BTN_SIZE, int(_rect.getPosition().y) + (_buttons.size() / _size.x)* BTN_SIZE);

	// create button
	Button* btn = new Button(loc, _btn_texture, pic_mark, cmd);
	_buttons.push_back(btn);

	return true;
}

// draws buttons on screen
void Menu::display(sf::RenderWindow& window)
{
	window.draw(_rect);
	for (unsigned i = 0; i < _buttons.size(); i++)
		_buttons[i]->display(window);
}

// execute button's command currently pressed
// gets: location pressed
// returns: success
bool Menu::execute(int mouse_pos_x, int mouse_pos_y)
{
	bool executed = false;

	// check if click was in menu
	if(_rect.getGlobalBounds().contains(float(mouse_pos_x), float(mouse_pos_y)))
		for (unsigned i = 0; i < _buttons.size(); i++)
		{
			if (_buttons[i]->execute(mouse_pos_x, mouse_pos_y))
				executed = true;
		}

	return executed;
}