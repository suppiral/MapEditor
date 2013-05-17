// this is the header file for canvas object 
// this object holds and manage the shapes on the canvas according to the users choises
#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Tile.h"

// ------- Canvas macros -------
const float CANVAS_POS_X = 0.f;
const float CANVAS_POS_Y = 0.f;

class Canvas {
public:
	Canvas();
	~Canvas(); // delete all canvas object kept.
	void clearShapes();
	void addTile(Tile& tile, Vertex pos );
	void fill(sf::Texture* txt, int tile);
	bool is_in_canvas(int,int) const;
	void saveMap();
	void loadMap(sf::Texture* txt);

	void display(sf::RenderWindow& window);

private:
	std::vector <Tile> _tiles; // holds all the shapes on the canvas 
	sf::RectangleShape _rect;
};

