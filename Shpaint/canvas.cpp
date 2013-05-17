// this is the cpp file for the canvas object 
#include "Canvas.h"
#include "Macros.h"
#include <fstream>
#include <iostream>

// constructor
Canvas::Canvas() : _rect(sf::Vector2f(MAP_SIZE_W*TILE_SIZE, TILE_SIZE*MAP_SIZE_H))
{
	// init canvas area
	_rect.setFillColor(sf::Color::White);
	_rect.setPosition(CANVAS_POS_X, CANVAS_POS_Y);

	for (unsigned i = 0; i < MAP_SIZE_W*MAP_SIZE_H; i++)
		_tiles.push_back(Tile());
}

void Canvas::fill(sf::Texture* txt, int tile)
{
	for (unsigned i = 0; i < MAP_SIZE_W*MAP_SIZE_H; i++)
	{
		_tiles[i] = Tile(txt, tile);
		_tiles[i].setPos(sf::Vector2f((i%MAP_SIZE_W)*TILE_SIZE, (i/MAP_SIZE_W)*TILE_SIZE));
	}
}

// destructor
Canvas:: ~Canvas()
{
	clearShapes();
}

// display shapes on window
void Canvas::display(sf::RenderWindow& window)
{
	window.draw(_rect); // draw canvas area

	// draw each shape
	for (unsigned i = 0; i < _tiles.size(); i++)
		_tiles[i].draw(window);
}


// delete all shapes
void Canvas::clearShapes()
{
	for (unsigned i =0; i < _tiles.size(); i++)
		_tiles[i] = Tile();
}

//this function adds a new function on the canvas vector of shapes. 
void Canvas::addTile(Tile& tile, Vertex pos )
{
	if (((pos.x/TILE_SIZE) + (pos.y/TILE_SIZE)*MAP_SIZE_W) < _tiles.size())
	{
		tile.setPos(sf::Vector2f(pos.x - pos.x%TILE_SIZE, pos.y - pos.y%TILE_SIZE));
		_tiles[(pos.x/TILE_SIZE) + (pos.y/TILE_SIZE)*MAP_SIZE_W] = tile;
	}
}


// checks if the point (x,y) is in the canvas
bool Canvas::is_in_canvas(int x, int y) const
{
	return _rect.getGlobalBounds().contains(float(x), float(y));
}


void Canvas::saveMap() 
{
	std::ofstream mapfile;
	mapfile.open("map/map.mp");

	if (!mapfile)
	{
		std::cerr << "Failed to open file : map/map.mp" << std::endl;
		return;
	}
	mapfile << MAP_SIZE_W << " " << MAP_SIZE_H << std::endl;
	for (unsigned row = 0; row < MAP_SIZE_H; row++)
	{
		for (unsigned col = 0; col < MAP_SIZE_W; col++)
			mapfile << _tiles[col + (row*MAP_SIZE_W)].getNum() << " ";
		mapfile << std::endl;
	}
	mapfile.close();
}

void Canvas::loadMap(sf::Texture* txt) 
{
	std::ifstream mapfile;
	mapfile.open("map/loadmap.mp");

	if (!mapfile)
	{
		std::cerr << "Failed to open file : map/map.mp" << std::endl;
		return;
	}
		
	mapfile.exceptions( std::ifstream::failbit | std::ifstream::badbit );

	unsigned size_x, size_y;
	mapfile >> size_x >> size_y;
	if (!(size_x == MAP_SIZE_W && size_y == MAP_SIZE_H))
		return;

	for (unsigned i = 0; i < MAP_SIZE_H*MAP_SIZE_W; i++)
	{
		int tile;
		try {
			mapfile >> tile;
			_tiles[i] = Tile(txt, tile);
			_tiles[i].setPos(sf::Vector2f((i%MAP_SIZE_W)*TILE_SIZE, (i/MAP_SIZE_W)*TILE_SIZE));
		}
		catch (...) { }
	}
	mapfile.close();
}