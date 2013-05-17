/*
 * Header file for class Menu.
*/
#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Command.h"

class Button; // forward class declaration

class Menu
{
public:
	Menu(const Vertex& loc, const Vertex& size, const std::string btn_texture_filename);
	~Menu();
	void display(sf::RenderWindow& window);
	bool add(int pic_mark, Command* cmd); // add button
	bool execute(int mouse_pos_x, int mouse_pos_y); // execute button on position (mouse_pos_x, mouse_pos_y)

private:
	std::vector <Button*> _buttons; // buttons
	Vertex _size; // menu size
	sf::RectangleShape _rect; // menu background
	sf::Texture _btn_texture; // button texture
};
