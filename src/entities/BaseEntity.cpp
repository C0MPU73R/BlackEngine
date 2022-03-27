/*
@filename: BaseEntity.cpp
@purpose: 
*/

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "blackengine/entities/BaseEntity.h"

namespace blackengine::entity {
    BaseEntity::BaseEntity() {
        updateTransMat();
    }

    BaseEntity::~BaseEntity()
    {
    }

    /**
     * Set the position of the entity.
     */
    void BaseEntity::setPos(glm::vec3 position) {
        pos = position;
        updateTransMat();
    }

    void BaseEntity::setPos(float x, float y, float z) {
        setPos(glm::vec3(x, y, z));
    }

    glm::vec3 BaseEntity::getPos() {
        return pos;
    }

    /**
     * Set the X position of the entity.
     */
    void BaseEntity::setX(float x) {
        setPos(glm::vec3(x, pos.y, pos.z));
    }

    /**
     * Set the Y position of the entity.
     */
    void BaseEntity::setY(float y) {
        setPos(glm::vec3(pos.x, y, pos.z));
    }

    /**
     * Set the Z position of the entity.
     */
    void BaseEntity::setZ(float z) {
        setPos(glm::vec3(pos.x, pos.y, z));
    }

    /**
     * Set the rotation of the entity.
     * @param rotation The rotation vector on the XYZ axes.
     */
    void BaseEntity::setRotation(glm::vec3 rotation) {
        this->rotation = rotation;
        updateTransMat();
    }

    /**
     * Set the rotation of the entity on the XYZ axes.
     */
    void BaseEntity::setRotation(float x, float y, float z) {
        setRotation(glm::vec3(x, y, z));
    }

    /**
     * Set the rotation of the entity on the HPR axes (which map to YXZ).
     * @param rotation The rotation vector on the HPR axes.
     */
    void BaseEntity::setHpr(glm::vec3 rotation) {
        setRotation(glm::vec3(rotation.y, rotation.x, rotation.z));
    }

    /**
     * Set the rotation of the entity on the HPR axes.
     */
    void BaseEntity::setHpr(float h, float p, float r) {
        setRotation(glm::vec3(p, h, r));
    }

    /**
     * Sets the H/Y axis rotation of the entity.
     */
    void BaseEntity::setH(float h) {
        setRotation(glm::vec3(rotation.x, h, rotation.z));
    }

    /**
     * Sets the P/X axis rotation of the entity.
     */
    void BaseEntity::setP(float p) {
        setRotation(glm::vec3(p, rotation.y, rotation.z));
    }

    /**
     * Sets the R/Z axis rotation of the entity.
     */
    void BaseEntity::setR(float r) {
        setRotation(glm::vec3(rotation.x, rotation.y, r));
    }

    /**
     * Sets the scale of the entity.
     */
    void BaseEntity::setScale(glm::vec3 scale) {
        this->scale = scale;
        updateTransMat();
    }

    void BaseEntity::setScale(float sx, float sy, float sz) {
        setScale(glm::vec3(sx, sy, sz));
    }

    /**
     * Scales the entity by a uniform value.
     */
    void BaseEntity::setScale(float scale) {
        setScale(glm::vec3(scale, scale, scale));
    }

    /**
     * Set the scaling of the entity in the X direction.
     */
    void BaseEntity::setSx(float sx) {
        setScale(glm::vec3(sx, scale.y, scale.z));
    }

    /**
     * Set the scaling of the entity in the Y direction.
     */
    void BaseEntity::setSy(float sy) {
        setScale(glm::vec3(scale.x, sy, scale.z));
    }

    /**
     * Set the scaling of the entity in the Z direction.
     */
    void BaseEntity::setSz(float sz) {
        setScale(glm::vec3(scale.x, scale.y, sz));
    }

    /**
     * Updates the translation matrix for the entity.
     */
    void BaseEntity::updateTransMat() {
        transform = glm::mat4(1.0f);
        transform = glm::translate(transform, pos);
        transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        transform = glm::scale(transform, scale);
    }

    /**
     * Function that allows code to be run every game tick.
     * @todo Make this get called every game tick.
     */
    void BaseEntity::update() {}
}
