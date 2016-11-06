#ifndef GETCOLOR_HPP
#define GETCOLOR_HPP

#include "Color.hpp"
#include <string>
#include <unordered_map>

enum class GC {
	PINK,
	CYAN,
	GREEN,
	NAVY,
	PURPLE,
	YELLOW,
	ORANGE,
	BLUE,
	SUNLIGHT,
	TOMATOSAUCE,
	MUSTARD,
	BUBBLEGUM,
	CHEWEDBUBBLEGUM,
	INDIGOPRIDE,
	LEMONGRASS,
	TURQUOISE,
	FOREST,
	SPIDERMANRED,
	SPIDERMANBLUE,
	CLOUD,
	PEACH,
	MAROON,
	VOMIT,
	ICE,
	BURGANDY
};

extern std::unordered_map<GC, Color> GetColor;

#endif//GETCOLOR_HPP