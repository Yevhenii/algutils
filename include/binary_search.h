// MIT License
//
// Copyright (c) 2019 Yevhenii Chernykh
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#ifndef BINARY_SEARCH_H_65906487_0DE6_4CA1_9A12_279EA5B37E4D
#define BINARY_SEARCH_H_65906487_0DE6_4CA1_9A12_279EA5B37E4D

#include <functional>
#include <iterator>

namespace alg
{

/// Simple binary search on range [begin, end)
/// T - type of searching value
/// RandomIterator - type of random access iterator
/// Cmp - type of comarator functor
/// @param value - value to search
/// @param begin - begin of the range
/// @param end - end of the range
/// @param compare compararor, std::less<T> by default
/// @return end if value does not found, some iterator in range of [begin, end) if value has been found.
template< typename T,
          typename RandomIterator,
          typename Cmp = std::less<> >
RandomIterator
binary_search(const T& value,
              RandomIterator begin,
              RandomIterator end,
              Cmp compare = Cmp())
{
    const auto interval_end = end;
    auto it = end;
    while (begin < end)
    {
        it = begin + std::distance(begin, end) / 2;
        if (*it == value)
        {
            return it;
        }
        else if (compare(*it, value))
        {
            begin = it + 1;
        }
        else
        {
            end = it;
        }
    }

    return interval_end;
}

} // namespace alg

#endif // BINARY_SEARCH_H_65906487_0DE6_4CA1_9A12_279EA5B37E4D
