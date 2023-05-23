#pragma once
#include "core.h"
#include "mass_spring_system.h"
#include "shader.h"

class Renderer {
private:

public:
	static void Render(MassSpringSystem);
	static void UpdateNormalVectors();
	static void UpdatePositions();
	static void Update();
};