#ifndef CONFIG_HPP
#define CONFIG_HPP

#define CONFIGPATH R"(C:\Users\Wax Chug da Gwad\Desktop\Dualive\Dualive\Dualive\config.txt)"

#include "GetColor.hpp"
#include "MusicAnalysis.hpp"
#include "Sprite.hpp"
#include "Tetrahedron.hpp"
#include "TetPoints.hpp"
#include "Time.hpp"
#include "Vector2.hpp"
#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <winsock.h>

typedef std::unordered_map<Vector2, std::unordered_set<Vector2>> VectorMap;
typedef std::pair<Vector2, Vector2> Pair;
typedef std::pair<Vector3, Vector3> Pair3;
typedef std::deque<std::pair<int, float>> ScaleTimings;
typedef std::pair<int, float> ScaleTiming;

// Pair hash
namespace std {
	template<>
	struct hash<std::pair<Vector2, Vector2>> {
		size_t operator()(const std::pair<Vector2, Vector2>& value) const {
			return (std::hash<Vector2>()(value.first) * 0x1f1f1f1f) ^ (std::hash<Vector2>()(value.second) << 1);
		}
	};
}

class Config {
public:
	static Config* I();

	// Convert degrees to radians
	float DToR(int degrees);
	Vector2 GetImageSize(const std::string& path);
	Time GetClosestTime(Time time);
	void SwitchSpriteColor(Sprite* sprite, int start, int end, Color first, Color second, float offset, float frequency);
	void AddScaleTimings(ScaleTimings& scaleTimings, Time timeStart, Time timeEnd, float freq, float scaleLarge, float scaleSmall);
	float GetScale(ScaleTimings& scaleTimings, float time);
	std::vector<Vector2> GetPositions();

	// Background dimensions
	Vector2 bgDims = Vector2(853.0f, 480.0f);

	// Kappa
	float reallySmallNumber = 0.00001f;

	// BPM
	float bpm = 190.0f;
	float mpb = 1 / bpm;
	float spb = mpb * 60;
	// ~316 ms per beat
	float mspb = 1000 * spb;
	float offset = mspb / 4;

	// Camera
	float cameraZ = 500.0f;
	float projectionDistance = 400.0f;

	// Scaling
	float patternScale = 0.35f * 2; // Halved size of pictures
	float lineWidth = 1000.0f;
	float lineScaleHeight = 0.1f;

	// Paths
	std::string beatmapDirectory = R"(C:\Users\Wax Chug da Gwad\AppData\Local\osu!\Songs\Quarks_Dualive_SDVX_NOFX\)";
	std::string dataPath = R"(C:\Users\Wax Chug da Gwad\Desktop\Dualive\Dualive\Debug\MusicAnalysisData.txt)";
	std::string storyboardPath = R"(C:\Users\Wax Chug da Gwad\AppData\Local\osu!\Songs\474742 Quarks - Dualive\Quarks - Dualive (Osuuki).osb)";

	// MusicAnalysisData
	MusicAnalysisData data = MusicAnalysis::LoadData(dataPath);

	// Times
	Time songStart = Time("00:00:000");
	Time songEnd = Time("02:07:985");

	// For PhaseTextGeneration
	int afterImages = 4;

private:
	static Config* instance;
	Config() {};
	Config(const Config&) {};
	Config& operator=(const Config&) {};
};

#endif//CONFIG_HPP