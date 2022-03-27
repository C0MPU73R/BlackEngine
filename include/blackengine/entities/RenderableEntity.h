/*
@filename: RenderableEntity.h
@purpose:
*/

#ifndef BLACKENGINE_RENDERABLEENTITY_H
#define BLACKENGINE_RENDERABLEENTITY_H

#include "BaseEntity.h"
#include "../renderer/Model.h"

namespace blackengine::entity {
    /*
     An entity that has a model and can thus be rendered.
     */
    class RenderableEntity : public BaseEntity {
    public:
        RenderableEntity(renderer::Model &model);
        void render(renderer::Shader& shader);
    private:
        renderer::Model model;
    };
}

#endif //BLACKENGINE_RENDERABLEENTITY_H
