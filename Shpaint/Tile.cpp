#include "Tile.h"

Tile::Tile(sf::Texture* texture, int num) : _texture(texture), _num(num)
{  
	_sprite.setTexture(*texture);
	_sprite.setTextureRect(sf::IntRect(BTN_SIZE*((_num-1) % TILE_MAP_SIZE_W), BTN_SIZE*((_num-1) / TILE_MAP_SIZE_W), 
						BTN_SIZE, BTN_SIZE));
	_sprite.scale(TILE_SIZE/float(BTN_SIZE), TILE_SIZE/float(BTN_SIZE));
	sf::IntRect ra = _sprite.getTextureRect();
	
}