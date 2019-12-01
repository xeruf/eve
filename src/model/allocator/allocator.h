#ifndef EVE_ALLOCATOR_H
#define EVE_ALLOCATOR_H

#include "../../config.h"

#include <memory>
#include <unordered_map>

#include <stdlib.h>

template <class T>
class Allocator {
public:
    T * objects = (T *) malloc (AMOUNT_ALLOCATED_OBJECTS);
    T * iterator = objects;
    std::unordered_map<T *, int> allocs;
    std::unordered_map<T *, int> deallocs;

    bool increment (size_t n) {
        iterator += n;
        return (iterator - objects <=  AMOUNT_ALLOCATED_OBJECTS);
    }

    T * reallocate (size_t n = 1, bool exact = true) {
        for (auto iter = deallocs.begin(); iter != deallocs.end(); iter++) {
            if (iter->first && iter->second >= n) {
                if (iter->second == n || not exact) {
                    T * ptr = iter->first;
                    allocs.insert ({ptr, n});
                    deallocs.erase (iter);
                    return ptr;
                }
            }
        }
        if (not exact) return nullptr;
        return reallocate (n, false);
    }

public:
    Allocator () = default;
    ~Allocator () {
        for (auto iter = allocs.begin(); iter != allocs.end(); iter++) {
            ~(* iter->first);
        }
        free (objects);
    }

    T * allocate (size_t n = 1) {
        if (n <= 0) throw std::range_error("Allocator::allocate: Can't allocate non-zero amounts of objects");
        if (n >= AMOUNT_ALLOCATED_OBJECTS) throw std::bad_alloc();

        T * ptr = reallocate(n);
        if (ptr) {
            return ptr;
        }

        if (increment (n)) {
            ptr = iterator;
            allocs.insert({ptr, n});
            return ptr;
        }
        throw std::bad_alloc();
    }

    void deallocate (T * ptr, size_t n = 1) {
        auto item = allocs.find(ptr);
        if (item != allocs.end()) {
            if (item->second == n) {
                allocs.erase(item);
                deallocs.insert ({ptr, n});
                return;
            }
        }
        throw std::bad_weak_ptr();
    }
};

#endif //EVE_ALLOCATOR_H
