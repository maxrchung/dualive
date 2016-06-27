#ifndef CONFIG_HPP
#define CONFIG_HPP

#define CONFIGPATH R"(C:\Users\Wax Chug da Gwad\Desktop\Dualive\Dualive\Dualive\config.txt)"

#include "Time.hpp"
#include "Vector2.hpp"
#include <map>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <winsock.h>

class Config {
public:
	static Config* I() {
		if (instance == NULL) {
			instance = new Config;
		}
		return instance;
	}

	static Vector2 GetImageSize(std::string path) {
		std::ifstream in(path);
		unsigned int width, height;

		in.seekg(16);
		in.read((char *)&width, 4);
		in.read((char *)&height, 4);

		width = ntohl(width);
		height = ntohl(height);

		return Vector2(width, height);
	}

	// BPM
	const float bpm = 190.0f;
	float mpb = 1 / bpm;
	float spb = mpb * 60;
	// ~316 ms per beat
	float mspb = 1000 * spb;
	float offset = mspb / 4;

	// Paths
	std::string beatmapDirectory = R"(C:\Users\Wax Chug da Gwad\AppData\Local\osu!\Songs\Quarks_Dualive_SDVX_NOFX)";
	std::string storyboardDirectory = R"(C:\Users\Wax Chug da Gwad\AppData\Local\osu!\Songs\Quarks_Dualive_SDVX_NOFX\Storyboard)";
	std::string storyboardPath = R"(C:\Users\Wax Chug da Gwad\AppData\Local\osu!\Songs\Quarks_Dualive_SDVX_NOFX\Quarks - Dualive (Osuuki).osb)";

	// Times
	Time songStart = Time("00:00:000");
	Time songEnd = Time("02:07:985");

private:
	static Config* instance;
	Config() {
		// For random
		srand(time(NULL));
	};
	Config(const Config&) {};
	Config& operator=(const Config&) {};
};

Config* Config::instance = NULL;

#endif//CONFIG_HPP