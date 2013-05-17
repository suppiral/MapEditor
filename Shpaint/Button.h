// header file for Button class

#pragma once

#include <SFML/Graphics.hpp>
#include "Command.h"
#include "Macros.h"

//const unsigned BTN_SIZE = TILE_SIZE;

class Button
{
public:
	Button(const Vertex& loc, sf::Texture& texture, int pic_mark, Command* cmd);
	~Button();
	void display(sf::RenderWindow& window);
	bool mark(int mouse_pos_x, int mouse_pos_y);
	bool isPosIn(int mouse_pos_x, int mouse_pos_y) const;
	void setPosition(const Vertex& pos);
	bool execute(int mouse_pos_x, int mouse_pos_y);

private:
	sf::RectangleShape _rect; // surrounding rect
	sf::Sprite _sprite; // button sprite
	Command* _cmd; // command
	bool _is_marked;
};
