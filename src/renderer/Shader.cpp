/*
@filename: Shader.cpp
@purpose: 
*/

#include <fstream>
#include <sstream>
#include <assert.h>
#include "blackengine/renderer/Shader.h"
#include "blackengine/misc/blackengineException.h"

namespace blackengine::renderer {
    Shader::Shader(const std::string& vertexFilename, const std::string& fragmentFilename) {
        GLuint vertexShader = loadAndCompileShader(GL_VERTEX_SHADER, vertexFilename);
        reportCompileStatus(GL_VERTEX_SHADER, vertexShader);
        GLuint fragmentShader = loadAndCompileShader(GL_FRAGMENT_SHADER, fragmentFilename);
        reportCompileStatus(GL_FRAGMENT_SHADER, fragmentShader);

        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
        reportLinkStatus(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    /**
     * Bind the shader for usage
     */
    void Shader::bind() {
        glUseProgram(program);
    }

    /**
     * Unbind the shader.
     */
    void Shader::unbind() {
        glUseProgram(0);
    }

    /**
     * Loads and compiles a shader.
     *
     * @param shaderType The OpenGL constant for what kind of shader this is.
     * @param filename The filename of the shader.
     * @return The id of the OpenGL shader object.
     */
    GLuint Shader::loadAndCompileShader(unsigned int shaderType, const std::string& filename) {
        std::ifstream shaderFile(filename);
        std::string shaderSource(std::istreambuf_iterator<char>(shaderFile), {});
        const char* shaderSourceCStr = shaderSource.c_str();
        GLuint shaderId = glCreateShader(shaderType);
        glShaderSource(shaderId, 1, &shaderSourceCStr, nullptr);
        glCompileShader(shaderId);
        return shaderId;
    }

    /**
     * Checks the compile status for a shader. If there is an error, it is reported to stderr.
     *
     * @param shaderType The type of the shader to check
     * @param shader The OpenGL id of the shader
     */
    void Shader::reportCompileStatus(GLuint shaderType, GLuint shader) {
        GLint success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Error compiling " << getShaderName(shaderType) << ": " << infoLog << std::endl;
        }
    }

    /**
     * Checks the link status of a shader program. If there is an error, it is reported to stderr.
     *
     * @param program The program id to check for linking errors.
     */
    void Shader::reportLinkStatus(GLuint program) {
        GLint success;
        GLchar infoLog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            std::cerr << "Error linking program: " << infoLog << std::endl;
        }
    }

    /**
     * Set an integer shader uniform.
     * @param name The name of the uniform variable.
     * @param val The value to pass to the shader.
     */
    void Shader::setUniformInt(const char* name, int val) {
        GLint loc = glGetUniformLocation(program, name);
        glUniform1i(loc, val);
    }

    /**
     * Set a float shader uniform.
     * @param name The name of the uniform variable.
     * @param val The value to pass to the shader.
     */
    void Shader::setUniformFloat(const char* name, float val) {
        GLint loc = glGetUniformLocation(program, name);
        glUniform1f(loc, val);
    }

    /**
     * Set a double-precision float shader uniform.
     * @param name The name of the uniform variable.
     * @param val The value to pass to the shader.
     */
    void Shader::setUniformDouble(const char* name, double val) {
        GLint loc = glGetUniformLocation(program, name);
        glUniform1d(loc, val);
    }

    /**
     * Set a float vector shader uniform of varied length.
     * @param name The name of the uniform variable.
     * @param val The values to pass to the shader.
     */
    void Shader::setUniformVecF(const char* name, std::vector<float>& val) {
        setUniformVecF(name, val.data(), val.size());
    }

    /**
     * Set a float vector shader uniform.
     * @param name The name of the uniform variable.
     * @param val An array of floats to pass to the shader.
     * @param size The size of the vector.
     */
    void Shader::setUniformVecF(const char &name, float* val, size_t size) {
        GLint loc = glGetUniformLocation(program, name);
        switch (size) {
            case 1:
                glUniform1f(loc, val[0]);
            case 2:
                glUniform2f(loc, val[0], val[1]);
            case 3:
                glUniform3f(loc, val[0], val[1], val[2]);
            case 4:
                glUniform4f(loc, val[0], val[1], val[2], val[3]);
            default:
                char msg[64];
                snprintf(msg, 64, "Can't create a uniform Vec%i", (int) size);
                throw misc::blackengineException(msg);
        }
    }

    /**
     * Set a 4x4 float matrix shader uniform.
     * @param name The name of the uniform variable.
     * @param val An array of floats to pass to the shader.
     * @param transpose Whether or not to transpose the matrix.-
     */
    void Shader::setUniformMat4F(const char* name, GLfloat* value, GLboolean transpose) {
        GLint loc = glGetUniformLocation(program, name);
        glUniformMatrix4fv(loc, 1, transpose, value);
    }
}
