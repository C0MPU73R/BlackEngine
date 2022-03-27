./*
@filename: BlackEngineUtils.cpp
@purpose:
*/

#include "blackengine/misc/blackengineUtils.h"

namespace blackengine::misc::blackengineUtils {
    /**
     * Get a value from an unordered map. If that value does not exist, return a default value.
     * @tparam Key The type of the map keys.
     * @tparam Value The type of the map values.
     * @param map The map to use.
     * @param key The key to look for.
     * @param defaultVal The value to return if the key is not in the map.
     * @return Either map.at(key) or defaultVal
     */
    template<typename Key, typename Value>
    Value getValOrDefault(std::unordered_map<Key, Value>& map, Key& key, Value defaultVal) {
        auto res = map.find(key);
        if (res != map.end()) {
            return res->second;
        }
        return defaultVal;
    }
}
