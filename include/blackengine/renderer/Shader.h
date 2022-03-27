/*
@filename: Shader.h
@purpose:
*/

#ifndef BLACKENGINE_SHADER_H
#define BLACKENGINE_SHADER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <glad/glad.h>

/** \file Shader.h
 *  Contains the [Shader](@ref Shader) class and some helpful shader-related utilities.
 */

namespace blackengine::renderer {
    /**
     * A mapping of OpenGL shader type constants to human-readable names.
     * Key 0 is used for a default name in case the actual shader name is unknown.
     */
    const std::unordered_map<GLuint, std::string> ShaderNames = {
        {GL_VERTEX_SHADER, "vertex shader"},
        {GL_FRAGMENT_SHADER, "fragment shader"},
        {GL_GEOMETRY_SHADER, "geometry shader"},
        {GL_COMPUTE_SHADER, "compute shader"},
        {GL_TESS_CONTROL_SHADER, "tesselation control shader"},
        {GL_TESS_EVALUATION_SHADER, "tesselation evaluation shader"},
        {0, "shader"}
    };

    /**
     * Helper function to get a shader name from ShaderNames, or to give a default name if the shader type is unknown.
     */
    static std::string getShaderName(GLuint shaderType) {
        auto res = ShaderNames.find(shaderType);
        if (res != ShaderNames.end()) {
            return res->second;
        }
        return ShaderNames.at(0);
    }

    /**
     * Loads and stores shaders. Currently only supports GLSL shaders.
     */
    class Shader {
    public:
        Shader(const std::string& vertexFilename, const std::string& fragmentFilename);
        void bind();
        static void unbind();
        void setUniformInt(const char* name, int val);
        void setUniformFloat(const char* name, float val);
        void setUniformDouble(const char* name, double val);
        void setUniformVecF(const char* name, std::vector<GLfloat>& val);
        void setUniformVecF(const char* name, float val[], size_t size);
        void setUniformMat4F(const char* name, GLfloat* value, GLboolean transpose = GL_FALSE);
        GLuint program;
    private:
        GLuint loadAndCompileShader(unsigned int shaderType, const std::string& filename);
        void reportCompileStatus(GLuint shaderType, GLuint shader);
        void reportLinkStatus(GLuint program);
    };
}

#endif // !BLACKENGINE_SHADER_H
