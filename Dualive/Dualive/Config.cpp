#include "Config.hpp"

Config* Config::instance = NULL;

Config* Config::I() {
	if (instance == NULL) {
		instance = new Config;
	}
	return instance;
}

float Config::DToR(int degrees) {
	return degrees * M_PI / 180.0f;
}

Vector2 Config::GetImageSize(const std::string& path) {
	std::ifstream in(path);
	unsigned int width, height;

	in.seekg(16);
	in.read((char *)&width, 4);
	in.read((char *)&height, 4);
	in.close();

	width = ntohl(width);
	height = ntohl(height);

	return Vector2(width, height);
}

Time Config::GetClosestTime(Time time) {
	return Time(roundf(time.ms / 100.0f) * 100.0f);
}

void Config::SwitchSpriteColor(Sprite* sprite, int start, int end, Color first, Color second, float offset, float frequency) {
	sprite->Color(start - offset, start, sprite->color, first);
	bool switchColor = true;
	for (int time = start + frequency; time <= end; time += frequency) {
		if (switchColor) {
			sprite->Color(time - offset, time, first, second);
		}
		else {
			sprite->Color(time - offset, time, second, first);
		}
		switchColor = !switchColor;
	}
}