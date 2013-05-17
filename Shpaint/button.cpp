//this is the Button cpp file

#include "Button.h"
#include <sstream>
#include <iostream>

// Constructor:
// gets: location, texture, pic mark on texture and command
Button::Button(const Vertex& loc, sf::Texture& texture, int pic_mark, Command* cmd) : _is_marked(false), _cmd(cmd), _rect(sf::Vector2f(float(BTN_SIZE), float(BTN_SIZE)))
{
	// init rect and sprite
	_rect.setPosition(float(loc.x), float(loc.y));
	_rect.setFillColor(sf::Color::Blue);
	_sprite.setPosition(float(loc.x), float(loc.y));
	_sprite.setTexture(texture);
	_sprite.scale(float(BTN_SIZE)/TEXTURE_SIZE, float(BTN_SIZE)/TEXTURE_SIZE);
	_sprite.setTextureRect(sf::IntRect(pic_mark * BTN_SIZE % texture.getSize().x, (pic_mark * BTN_SIZE / texture.getSize().x)* BTN_SIZE, BTN_SIZE, BTN_SIZE));
}
// destructor deletes command
Button::~Button()
{
	delete _cmd;
}

// will mark the button with underline if mouse_pos is in _rect
// gets: mouse position x and y
// returns whether the button is marked or not
bool Button::mark(int mouse_pos_x, int mouse_pos_y)
{
	if (isPosIn(mouse_pos_x, mouse_pos_y)) // check if mouse is on button
	{
		if (!_is_marked) // check if button is marked
		{
			// if not, mark it
			_rect.setOutlineThickness(1.f);
			_is_marked = true;
		}
	}

	else if (_is_marked) // if mouse is not on button but is marked
	{
		
		// set as unmarked
		_rect.setOutlineThickness(0.f);
		_is_marked = false;
	}
	return _is_marked; // return button status 
}

// draw button on window
void Button::display(sf::RenderWindow& window)
{
	if (_is_marked)
		window.draw(_rect);
	window.draw(_sprite);
}

// check if mouse is on button
// gets: mouse x,y position
// returns: whether mouse is on button or not
bool Button::isPosIn(int mouse_pos_x, int mouse_pos_y) const
{
	// check if mouse position is on the sprite
	if(_sprite.getGlobalBounds().contains(float(mouse_pos_x), float(mouse_pos_y)))
		return true;
	return false;
}

// set button position
void Button::setPosition(const Vertex& pos)
{
	_sprite.setPosition(float(pos.x), float(pos.y));
}

// runs the preset action if the button is marked
bool Button::execute(int mouse_pos_x, int mouse_pos_y)
{
	if (mark(mouse_pos_x, mouse_pos_y))
	{
		_cmd->execute();
		return true;
	}
	return false;
}