/*
@filename: Renderer.cpp
@purpose:
*/

#include "blackengine/renderer/Mesh.h"

namespace blackengine::renderer {
    Mesh::Mesh(std::vector<GLfloat> modelData, std::vector<GLuint> indices) : numVerts(
        modelData.size() / (3 /*xyz*/ + 3 /*rgb*/ + 2 /*uv*/)), numIndices(indices.size()) {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, modelData.size() * sizeof(GLfloat), modelData.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices) {
        std::vector<GLfloat> modelData = {};
        for (Vertex& vertex : vertices) {
            modelData.push_back(vertex.pos.x);
            modelData.push_back(vertex.pos.y);
            modelData.push_back(vertex.pos.z);
            modelData.push_back(vertex.color.r);
            modelData.push_back(vertex.color.g);
            modelData.push_back(vertex.color.b);
            modelData.push_back(vertex.uv.u);
            modelData.push_back(vertex.uv.v);
        }
        //new(this) Mesh(modelData, indices);
        //TODO: Create the mesh elsewhere
    }

    Mesh::Mesh(std::vector<GLfloat>{}, std::vector<GLuint>{}) {
    }

    //TODO: Destruction when no longer used.

    /**
     * Get rid of the mesh's OpenGL objects.
     */
    void Mesh::cleanup() {
        if (vao) {
            vao = 0;
            glDeleteVertexArrays(1, &vao);
        }
        if (vbo) {
            vbo = 0;
            glDeleteBuffers(1, &vbo);
        }
    }

    /**
     * Draw this mesh. Will not work on its own, you should probably bind this to a @ref Model and use Model::render
     * instead.
     */
    void Mesh::render() {
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(numIndices), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}
