#pragma once

#include "macros.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

// utility functions
float max(float a, float b);
unsigned max(unsigned a, unsigned b);
unsigned min(unsigned a, unsigned b);
unsigned round(float a);
void LoadFont(sf::Font&, const char* filename);
void loadTexture(sf::Texture& texture, const std::string& filename);
double distance(const sf::Vector2u& v1, const sf::Vector2u& v2);
sf::Vector2f point_to_2f(const Point &) ;
sf::Vector2f vertex_to_2f(const Vertex &);
Vertex point_to_vertex(const Point &);
void loadTexture(sf::Texture& texture, const std::string& filename, int width, int height);