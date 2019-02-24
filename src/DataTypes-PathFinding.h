#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>

class ofVec2f;
struct Path
{
	std::vector<ofVec2f> m_Path;
};

enum class Heuristic
{
	Manhattan,
	Euclidean,
	Default,
	Zero
};

struct Heuristics
{
	static float Manhattan(float dx, float dy) { return dx + dy; }
	static float Euclidean(float dx, float dy) { return sqrt(dx * dx + dy * dy); }
};
