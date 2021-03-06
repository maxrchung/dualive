#include "Pocket.hpp"

Pocket::Pocket() {}

Pocket::Pocket(Vector2 vector)
	: points({ vector }) {}

void Pocket::CalculateAverage(Pocket* pocket) {
	if (pocket->points.empty()) {
		throw std::exception("Cannot calculate average; pocket is empty");
	}

	Vector2 total = Vector2();
	for (auto point : pocket->points) {
		total += point;
	}
	pocket->average = total / pocket->points.size();
}

void Pocket::AddPockets(std::unordered_set<Pocket*>& pockets, Pair pair, float cutOffDistance) {
	Pocket* firstPocket = addVectorToPocket(pockets, pair.first, cutOffDistance);
	Pocket* secondPocket = addVectorToPocket(pockets, pair.second, cutOffDistance);
	connectPockets(firstPocket, secondPocket);
}

float Pocket::cutOffDistanceMin = 20.0f;
float Pocket::cutOffDistanceMax = 30.0f;
Pocket* Pocket::addVectorToPocket(std::unordered_set<Pocket*>& pockets, Vector2 vector, float cutOffDistance) {
	for (auto pocket : pockets) {
		// Add vector to pocket if distance is < some distance
		Vector2 pocketPoint = *(pocket->points.begin());
		if ((pocketPoint - vector).Magnitude() < cutOffDistance) {
			pocket->points.insert(vector);
			return pocket;
		}
	}

	// Else make a new pocket and add vector to it
	Pocket* pocket = new Pocket(vector);
	pockets.insert(pocket);
	return pocket;
}

void Pocket::connectPockets(Pocket* firstPocket, Pocket* secondPocket) {
	firstPocket->pockets.insert(secondPocket);
	secondPocket->pockets.insert(firstPocket);
}