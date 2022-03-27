#ifndef blackengine_UTILS_H
#define blackengine_UTILS_H

#include <unordered_map>

/**
 * Various useful utilities.
 */
namespace blackengine::misc::blackengineUtils {
    template <typename Key, typename Value> Value getValOrDefault(std::unordered_map<Key, Value>& map, Key& key, Value defaultVal = nullptr);
};

#endif //blackengine_UTILS_H
