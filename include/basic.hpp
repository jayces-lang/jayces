/**
 * Copyright 2023 the JayCeS authors. All rights reserved.
 *
 * MIT license.
 */
#pragma once

#include <unordered_map>

namespace jayces {
template <class T, class K>
std::unordered_map<T, K> reverse_map(std::unordered_map<K, T> map)
{
    std::unordered_map<T, K> result;
    for (const auto &p : map)
        result[p.second] = p.first;
    return result;
}
} // namespace jayces
