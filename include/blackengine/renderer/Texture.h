/*
@filename: Texture.h
@purpose:
*/

#ifndef BLACKENGINE_TEXTURE_H
#define BLACKENGINE_TEXTURE_H

#include <glad/glad.h>

namespace blackengine::renderer {
    constexpr char MissingTextureFilename[] = "res/maps/unknown.png";

    /**
     * Loads and stores a texture.
     */
    class Texture {
    public:
        Texture(const char* &filename);
        int getWidth();
        int getHeight();
        void bind();
        static void unbind();
        GLuint textureId;
    private:
        int width, height;
    };
}

#endif // !BLACKENGINE_TEXTURE_H
