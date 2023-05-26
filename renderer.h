#pragma once
#include "core.h"
#include "mass_spring_system.h"
#include "shader.h"
#include "cloth_mesh.h"

class Renderer {
private:
	Shader* m_shader;
	ClothMesh* m_cloth;

public:

	Renderer(ClothMesh* cloth);
	void Draw();
	void InitModelViewProjection();
};