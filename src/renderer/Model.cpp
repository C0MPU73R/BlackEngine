/*
@filename: Model.cpp
@purpose: Model processing
*/

#include <iostream>
#include "blackengine/renderer/Model.h"

namespace blackengine::renderer {

    Model::Model() {
        //ctor default
    }

    Model::Model(Mesh mesh, Texture texture) : mesh(mesh), texture(texture) {
    }

    Model::mesh(Mesh(std::vector<float>{}, {})), texture(Texture(MissingTextureFilename)) {
    }

    void Model::cleanup() {
        mesh.cleanup();
    }

    /**
     * Draw the model.
     */
    void Model::render() {
        texture.bind();
        mesh.render();
        texture.unbind();
    }
}
