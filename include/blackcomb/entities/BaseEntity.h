#ifndef BLACKCOMB_ENTITY_H
#define BLACKCOMB_ENTITY_H


#include <glm/glm.hpp>

namespace blackcomb::entity {
/**
 * A generic entity class.
 * Contains functions for setting position, rotation, and scale, as well as supporting a function that is called every tick.
 */
    class BaseEntity {
    public:
        BaseEntity();
        virtual ~BaseEntity(); // TODO
        void setPos(glm::vec3 position);
        void setPos(float x, float y, float z);
        glm::vec3 getPos();
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setRotation(glm::vec3 rotation);
        void setRotation(float x, float y, float z);
        void setHpr(glm::vec3 hpr);
        void setHpr(float h, float p, float r);
        void setH(float h);
        void setP(float p);
        void setR(float r);
        void setScale(glm::vec3 scale);
        void setScale(float sx, float sy, float sz);
        void setScale(float scale);
        void setSx(float sx);
        void setSy(float sy);
        void setSz(float sz);
        virtual void update();
    protected:
        void updateTransMat();
        glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f); ///< The position of the entity in 3D space.
        glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f); ///< The rotation of the entity on the XYZ axes, in degrees.
        glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f); ///< The scale of the entity.
        glm::mat4 transform = glm::mat4(1.0f); ///< The transformation matrix for the entity.
    };
}

#endif //BLACKCOMB_ENTITY_H
