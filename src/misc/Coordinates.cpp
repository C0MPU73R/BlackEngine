./*
@filename: Coordinates.cpp
@purpose:
*/

#include "blackengine/misc/Coords.h"

namespace blackengine::misc {
    bool UVCoord::operator==(const UVCoord& other) const {
        return u == other.u && v == other.v;
    }

    bool UVRect::operator==(const UVRect& other) const {
        return botLeft == other.botLeft && topRight == other.topRight;
    }

    bool Point2f::operator==(const Point2f& other) const {
        return x == other.x && y == other.y;
    }

    bool Point2f::operator==(const Point2i& other) const {
        return x == other.x && y == other.y;
    }

    bool Point2i::operator==(const Point2f& other) const {
        return x == other.x && y == other.y;
    }

    bool Point2i::operator==(const Point2i& other) const {
        return x == other.x && y == other.y;
    }

    bool Point3f::operator==(const Point3f& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Point3f::operator==(const Point3i& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Point3i::operator==(const Point3i& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Point3i::operator==(const Point3f& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Color::operator==(const Color& other) const {
        return r == other.r && g == other.g && b == other.b;
    }
}
