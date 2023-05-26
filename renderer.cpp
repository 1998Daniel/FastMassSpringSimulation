#include "renderer.h"

Renderer::Renderer(ClothMesh* cloth) : m_cloth(cloth)
{
	m_shader = new Shader("./basic.vert", "./basic.frag");

    InitModelViewProjection();
}

void Renderer::Draw()
{
    m_shader->use();
    glBindVertexArray(m_cloth->GetVAO());
    glEnableVertexAttribArray(POSITIONS_VBO_INDEX);
    glEnableVertexAttribArray(NORMALS_VBO_INDEX);
    glEnableVertexAttribArray(TEX_COORDS_VBO_INDEX);
    glEnableVertexAttribArray(EBO_INDEX);
    glDrawElements(GL_TRIANGLES, m_cloth->GetIndicesCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(POSITIONS_VBO_INDEX);
    glDisableVertexAttribArray(NORMALS_VBO_INDEX);
    glDisableVertexAttribArray(TEX_COORDS_VBO_INDEX);
    glDisableVertexAttribArray(EBO_INDEX);
    glBindVertexArray(0);
    glUseProgram(0);
}

void Renderer::InitModelViewProjection()
{
    m_shader->use();
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -100.0f));
    m_shader->setMat4("projection", projection);
    m_shader->setMat4("view", view);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0));
    m_shader->setMat4("model", model);
}

