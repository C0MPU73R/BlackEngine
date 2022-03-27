/*
@filename: Camera.cpp
@purpose: Main camera with basic traversals and rotations
*/

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "blackengine/entities/Camera.h"

namespace blackengine::entity {
    /**
     * Generate a view matrix and load it into a shader.
     *
     * @param shader The @ref Shader to load the view matrix into.
     */
    void Camera::loadViewMatrix(renderer::Shader& shader) {
        glm::mat4 view(1.0f);
        view = glm::translate(transform, pos);
        view = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        view = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        view = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::scale(transform, scale);
        shader.setUniformMat4F("view", glm::value_ptr(view));
    }

    /**
     * Generate a projection matrix and load it into a shader.
     *
     * @param shader The @ref Shader to load the projection matrix into.
     * @param window The @ref Window that you want the projection matrix for.
     */
    void Camera::loadProjectionMatrix(renderer::Shader& shader, base::Window& window) {
        misc::Point2i winDims = window.getDims();
        glm::mat4 projection = glm::perspective(glm::radians(fov), (float) winDims.x / winDims.y, 0.1f, 100.0f);
        shader.setUniformMat4F("projection", glm::value_ptr(projection));
    }
}
