#pragma once

#include "../core/glm-master/glm/glm.hpp"

struct Vertex
{
	Vertex() : x(0.0f), y(0.0f), z(0.0f) {}

	Vertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	Vertex(glm::vec3 position) : x(position.x), y(position.y), z(position.z) {}

	float x, y, z;
};