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

void ClothMesh::SetPositions(void* buffer, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[::POSITIONS_VBO_INDEX]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

}

void ClothMesh::SetNormals(void* buffer, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[::NORMALS_VBO_INDEX]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void ClothMesh::SetTextureCoordinates(void* buffer, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[::TEX_COORDS_VBO_INDEX]);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}

void ClothMesh::SetIndices(void* buffer, size_t size)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
}



