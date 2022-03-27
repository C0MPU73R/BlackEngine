/*
@filename: RenderableEntity.cpp
@purpose: To be rendered
*/

#include <glm/gtc/type_ptr.hpp>
#include "blackengine/entities/RenderableEntity.h"

namespace blackengine::entity {
    RenderableEntity::RenderableEntity(renderer::Model& model) : model(model) {}

    /**
     * Render this entity.
     * @param shader @ref Shader to use to render this entity.
     */
    void RenderableEntity::render(renderer::Shader& shader) {
        shader.setUniformMat4F("model", glm::value_ptr(transform));
        model.render();
    }
}
