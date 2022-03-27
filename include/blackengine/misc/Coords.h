#ifndef blackengine_COORDS_H
#define blackengine_COORDS_H

#include <functional>

namespace blackengine::misc {
    struct Point2i;
    struct Point3i;

    /**
     * Represents a set of UV coordinates.
     */
    struct UVCoord {
        bool operator==(const UVCoord& other) const;
        float u;
        float v;
    };

    /**
     * Represents a rectangle in UV space. Composed of two UV points, one for the bottom left corner and one for the top right.
     */
    struct UVRect {
        bool operator==(const UVRect& other) const;
        UVCoord botLeft; ///< Bottom left corner of the UV rectangle.
        UVCoord topRight; ///< Top right corner of the UV rectangle.
    };

    /**
     * Represents a 2D point with floats.
     * \todo Could this be replaced with a template?
     */
    struct Point2f {
        bool operator==(const Point2f& other) const;
        bool operator==(const Point2i& other) const;
        float x;
        float y;
    };

    /**
     * Represents a 2D point with integers.
     * \todo Could this be replaced with a template?
     */
    struct Point2i {
        bool operator==(const Point2f& other) const;
        bool operator==(const Point2i& other) const;
        int x;
        int y;
    };

    /**
     * Represents a 3D point with floats.
     * \todo Could this be replaced with a template?
     */
    struct Point3f {
        bool operator==(const Point3f& other) const;
        bool operator==(const Point3i& other) const;
        float x;
        float y;
        float z;
    };

    /**
     * Represents a 3D point with integers.
     * \todo Could this be replaced with a template?
     */
    struct Point3i {
        bool operator==(const Point3f& other) const;
        bool operator==(const Point3i& other) const;
        int x;
        int y;
        int z;
    };

    /**
     * Represents a colour in the RGBA colour space.
     */
    struct Color {
        bool operator==(const Color& other) const;
        int r;
        int g;
        int b;
        int a = 255;
    };
}

namespace std {
    /**
     * Implementation of std::hash for [Point3f](@ref Point3f)
     */
    template <>
    struct hash<blackengine::misc::Point3f> {
        std::size_t operator()(const blackengine::misc::Point3f& k) const {
            return ((hash<float>()(k.x) ^ (hash<float>()(k.y) << 1)) >> 1) ^ (hash<float>()(k.z) << 1);
        }
    };

    /**
     * Implementation of std::hash for [Point3i](@ref Point3i)
     */
    template <>
    struct hash<blackengine::misc::Point3i> {
        std::size_t operator()(const blackengine::misc::Point3i& k) const {
            return ((hash<int>()(k.x) ^ (hash<int>()(k.y) << 1)) >> 1) ^ (hash<int>()(k.z) << 1);
        }
    };
}

#endif //blackengine_COORDS_H
