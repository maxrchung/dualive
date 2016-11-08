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
	BURGANDY,
	LAVENDER,
	NEONGREEN,
	SHALLOWSEA,
	ELECTRICITY,
	COTTONCANDY,
	SEAFOAM,
	GOLD,
	IRONGRIT,
	CHERRY,
	LEATHER,
	MOSS,
	DIAMONDSHINE,
	OPENSIGN,
	FAKEINDIGO,
	RUST,
	FLUFFPINK,
	ANGRYBLUE,
	WARNING,
	BABYGREEN,
	STEELBLUE,
	COUPLEMONTHSWORNBASKETBALLORANGE,
	ALIENWARE,
	MOSSYAQUARIUM,
	GOLDENGATERED,
	SANDPAPER,
	SUICIDEAD,
	BRUISE,
	HAPPYNESS,
	SADNESS,

	TRAFFICONE,
	AQUAMARINE,
	PARADELIGHTS,
	PARADENIGHT,
	EMERALD,
	COALMINE,
	STOICROCK,
	TENSIONSENVELOPMENT,
	CROW,
	SKYFALL,
	FLAMINGROCKET,
	THELIGHTOFSPACE,

	SATURN,
	URANUSDEATH,
	MARBLEGUMBALL,
	LIPSTICK,
	THEFORESTFIRE,
	THEFORESTTHATBURNED
};

extern std::unordered_map<GC, Color> GetColor;

#endif//GETCOLOR_HPP