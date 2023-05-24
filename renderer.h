#pragma once
#include "core.h"
#include "mass_spring_system.h"
#include "shader.h"
#include "cloth_mesh.h"

class Renderer {
private:

public:
	static void Render(ClothMesh);
	static void UpdateNormalVectors();
	static void UpdatePositions();
	static void Update();
};