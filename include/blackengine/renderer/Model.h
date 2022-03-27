/*
@filename: Model.h
@purpose:
*/

#ifndef BLACKENGINE_MODEL_H
#define BLACKENGINE_MODEL_H

#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"

namespace blackengine::renderer {
    /**
     * Contains both a [Mesh](@ref Mesh) and a [Model](@ref Model) so that they may be rendered in tandem.
     */
    class Model {
    public:
        Model();
        Model(Mesh mesh, Texture texture);
        void cleanup();
        void render();
        Mesh mesh; //TODO: A lot of imports not found
        Texture texture;
    };
}

#endif // !BLACKENGINE_MODEL_H
