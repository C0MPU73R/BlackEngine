/*
@filename: TextureAtlas.cpp
@purpose:
*/
#include "blackengine/renderer/TextureAtlas.h"

namespace blackengine::renderer {
    TextureAtlas::TextureAtlas(const std::string& textureFilename, int textureWidth, int textureHeight) :
        textureWidth(textureWidth), textureHeight(textureHeight), atlas(Texture(textureFilename.c_str())) {
        numColumns = atlas.getWidth() / textureWidth;
        numRows = atlas.getHeight() / textureHeight;
        centerOffsetX = 1.0f / (numColumns);
        centerOffsetY = 1.0f / (numRows);
    }

    /**
     * Get the @ref Texture for the texture atlas
     */
    Texture TextureAtlas::getTexture() {
        return atlas;
    }

    /**
     * Get the coordinates for a texture in the atlas
     * @param texture The index of the texture, left to right, top to bottom, zero indexed
     */
    misc::UVRect TextureAtlas::getCoordsForTexture(int texture) {
        float leftX = texture % numColumns;
        float botY = (numRows - 1) - (texture / numColumns);
        leftX /= (float) numColumns;
        botY /= (float) numRows;
        misc::UVCoord botLeft = {leftX, botY};
        misc::UVCoord topRight = {leftX + centerOffsetX, botY + centerOffsetY};
        return {botLeft, topRight};
    }
}
