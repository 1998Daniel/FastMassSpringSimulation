#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "cloth_mesh.h"
#include "core.h"

ClothMesh::ClothMesh(int num_particles) : m_num_particles(num_particles)
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(::VBO_SIZE, &m_vbo[0]);
	glGenBuffers(1, &m_ebo);

	glBindVertexArray(m_vao);	

	//------------Positions-------------------//
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//------------Normals--------------------//
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//------------Texture Coordinates--------//
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[2]);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//------------Indices--------------------//
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
}

void ClothMesh::SetPositionsVBO(float* buffer, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[::POSITIONS_VBO_INDEX]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void ClothMesh::SetNormalsVBO(float* buffer, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[::NORMALS_VBO_INDEX]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void ClothMesh::SetTextureCoordinatesVBO(float* buffer, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[::TEX_COORDS_VBO_INDEX]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void ClothMesh::SetIndicesEBO(unsigned int* buffer, size_t size)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void ClothMesh::UpdateNormalVectors()
{

}

void ClothMesh::BuildMesh()
{
	InitPositions();
	SetPositionsVBO(&m_positions[0][0], m_positions.size() * sizeof(float) * 3);

	InitNormals();
	SetNormalsVBO(&m_normals[0][0], m_positions.size() * sizeof(float) * 3);

	InitTexCoords();
	SetTextureCoordinatesVBO(&m_tex_coords[0][0], m_tex_coords.size() * sizeof(float) * 2);

	InitIndices();
	SetIndicesEBO(&m_indices[0][0], m_indices.size() * sizeof(unsigned int) * 3);

}

int ClothMesh::GetIndicesCount()
{
	return m_indices.size() * 3;
}

GLuint& ClothMesh::GetVAO()
{
	return m_vao;
}

void ClothMesh::InitPositions()
{
	for (int i = 0; i < m_num_particles; i++) {
		for (int j = 0; j < m_num_particles; j++) {
			m_positions.push_back(glm::vec3(i * 2.f, j * 2.f, 0.0f));
		}
	}
}

void ClothMesh::InitNormals()
{
	for (int i = 0; i < m_num_particles; i++) {
		for (int j = 0; j < m_num_particles; j++) {
			m_normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
		}
	}
}

void ClothMesh::InitTexCoords()
{
	//TODO
	//TODO
	// TODO UPDATE TO REAL TEXTURE COORDINATES
	//TODO
	//TODO 
	//Dummy Texture Coordinates for now

	for (int i = 0; i < m_num_particles; i++) {
		for (int j = 0; j < m_num_particles; j++) {
			m_tex_coords.push_back(glm::vec2(0.0f, 0.0f));
		}
	}
}

void ClothMesh::InitIndices()
{
	//LAYOUT 
	// 
	//P_i_j   P_i_j+1
	//P_i+1_j  P_i+1_j+1

	//For each lattice find the two triangles that make it up
	// 
	//First Triangle is P_i_j -> P_i+1_j -> P_i+1_j+1
	// 
	//Second Triangle is P_i_j -> P_i+1_j+1 -> P_i_j+1

	for (int i = 0; i < m_num_particles - 1; i++) {
		for (int j = 0; j < m_num_particles - 1; j++) {

			int p_top_left = (i * m_num_particles) + j;
			int p_bottom_left = ((i + 1) * m_num_particles) + j;
			int p_bottom_right = ((i + 1) * m_num_particles) + (j + 1);
			int p_top_right = (i * m_num_particles) + (j + 1);
			
			//First triangle
			m_indices.push_back(glm::ivec3(p_top_left,p_bottom_left, p_bottom_right));

			//Second Triangle
			m_indices.push_back(glm::ivec3(p_top_left, p_bottom_right, p_top_right));
		}
	}
}



