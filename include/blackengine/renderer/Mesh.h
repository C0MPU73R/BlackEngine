/*
@filename: Renderer.h
@purpose:
*/

#ifndef BLACKENGINE_MESH_H
#define BLACKENGINE_MESH_H

#include <glad/glad.h>
#include <vector>
#include "../misc/Coords.h"

namespace blackengine::renderer {
    /**
     * Holds the data that describes a vertex: position, colour, and uv coordinate.
     */
    struct Vertex {
        misc::Point3f pos;
        misc::Color color;
        misc::UVCoord uv;
    };

    /**
     * Loads and stores mesh data.
     */
    class Mesh {
    public:
        Mesh(std::vector<GLfloat> modelData, std::vector<GLuint> indices);
        Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
        Mesh();
        void cleanup();
        void render();
        GLuint vao = 0;
        unsigned long numVerts, numIndices;
    private:
        GLuint ebo, vbo;
    };
}

#endif // !BLACKENGINE_MESH_H
