// utility functions

#include "Utility.h"

extern const int empty;
// ----- min/max functions ------------
float max(float a, float b)
{
	if (a > b)
		return a;
	return b;
}
unsigned max(unsigned a, unsigned b)
{
	if (a > b)
		return a;
	return b;
}
unsigned min(unsigned a, unsigned b)
{
	if (max(a,b) == a)
		return b;
	return a;
}
// ---------------------------------
// round a up or don't (whichever is closeset)
unsigned round(float a)
{
	if (a-unsigned(a) > 0.5)
		return unsigned(a) +1;

	return unsigned(a);
}

// returns manhattan distance from v1 to v2
double distance(const sf::Vector2u& v1, const sf::Vector2u& v2)
{
	double x = std::sqrt(std::pow(double(v1.x) - v2.x,2) + std::pow( double(v1.y) - v2.y, 2));
	return std::sqrt(std::pow(double(v1.x) - v2.x,2) + std::pow( double(v1.y) - v2.y, 2));
}

// load font from filename
void LoadFont(sf::Font& font, const char* filename)
{
	if (!font.loadFromFile(filename))
	{
		std::cerr << "unable to load from file";
		exit(EXIT_FAILURE);
	}
}
// load texture from filename
void loadTexture(sf::Texture& texture, const std::string& filename)
{
	texture.create(TEXTURE_SIZE, TEXTURE_SIZE);
	if (!texture.loadFromFile(filename))
	{
		std::cerr << "fail to load texture from: " << filename;
		exit(EXIT_FAILURE);
	}
	texture.setRepeated(true);
}

sf::Vector2f point_to_2f(const Point& point) 
{
	sf::Vector2f new_ver;
	new_ver.x = (float)point.x;
	new_ver.y = (float)point.y;
	return new_ver;
}

sf::Vector2f vertex_to_2f(const Vertex &ver)
{
	sf::Vector2f new_ver;
	new_ver.x = (float)ver.x;
	new_ver.y = (float)ver.y;
	return new_ver;
}

Vertex point_to_vertex(const Point & point)
{
	Vertex new_ver;
	new_ver.x = (int)point.x;
	new_ver.y = (int)point.y;
	return new_ver;
}
// load texture from filename
void loadTexture(sf::Texture& texture, const std::string& filename, int width, int height)
{
	texture.create(width*TILE_SIZE, height*TILE_SIZE);
	if (!texture.loadFromFile(filename))
	{
		std::cerr << "fail to load texture from: " << filename;
		exit(EXIT_FAILURE);
	}
	texture.setRepeated(true);
}
// load Music from filename
void loadMusic(sf::Music& music, const char* filename)
{
	// Load a music to play
     if (!music.openFromFile(filename))
	{
		std::cerr << "fail to load texture from: " << filename;
		exit(EXIT_FAILURE);
	}
}