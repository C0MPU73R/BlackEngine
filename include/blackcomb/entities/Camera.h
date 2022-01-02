#ifndef BLACKCOMB_CAMERA_H
#define BLACKCOMB_CAMERA_H

#include "BaseEntity.h"
#include "../renderer/Shader.h"
#include "blackcomb/base/Window.h"

namespace blackcomb::entity {
    /**
     * An entity that can be used as a camera.
     * Contains functions that allow you to get the view and projection matrices.
     */
    class Camera : public BaseEntity {
    public:
        virtual void loadViewMatrix(renderer::Shader& shader);
        void loadProjectionMatrix(renderer::Shader& shader, base::Window& window);
        float fov = 90.0f; //< Default field of view of the camera.
    };
}

#endif //BLACKCOMB_CAMERA_H
