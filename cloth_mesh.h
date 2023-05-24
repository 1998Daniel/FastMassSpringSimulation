#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "core.h"

class ClothMesh {
private:
	GLuint m_vao;
	GLuint m_vbo[::VBO_SIZE];
	GLuint m_ebo;
	int m_num_particles;
	std::vector<glm::vec3> m_positions;
	std::vector<glm::vec3> m_normals;
	std::vector<glm::vec3> m_tex_coords;
	std::vector<glm::vec3> m_indices;

public:
	ClothMesh(int num_particles);

	void SetPositions(void* buffer, size_t size);
	void SetNormals(void* buffer, size_t size);
	void SetTextureCoordinates(void* buffer, size_t size);
	void SetIndices(void* buffer, size_t size);
};