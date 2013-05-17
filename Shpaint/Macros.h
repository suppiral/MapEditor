#pragma once

#include <cmath>
#include <string>

const int BAD = -1;

// a point on the screen
struct Vertex {
	Vertex() { }
	Vertex(int x1, int y1) { x = x1; y = y1; }
	int x, y;
};

// a point on the screen
struct Point {
	Point() { }
	Point(double x1, double y1) { x = x1; y = y1; }
	double x, y;
};

//for shapes
const float thickness = 1.7f;
const int TILE_SIZE = 32;
const int MAP_SIZE_W = 20;
const int MAP_SIZE_H = 20;
const int TILE_MAP_SIZE_W = 6;
const int TILE_MAP_SIZE_H = 3;
const int BTN_SIZE = 64;

// ####################################################
// ------------- Menus related consts -----------------

const std::string tiles_filename = "resources/tiles.png";
const std::string act_btn_txt_filename = "resources/action_menu.png";
const std::string shape_btn_txt_filename = "resources/shape_menu.png";
const std::string color_btn_txt_filename = "resources/color_menu.png";
const int TEXTURE_SIZE = 64;

// ####################################################