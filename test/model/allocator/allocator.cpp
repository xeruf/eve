#include "../../../src/model/allocator/allocator.h"

#include <catch2/catch.hpp>

TEST_CASE ("I can allocate objects always located close to each other") {
    SECTION ("I can easily allocate and deallocate a primitive data type") {
        auto allocator = new Allocator<int>();
        auto & alloc = * allocator;
        int * first;

        REQUIRE_NOTHROW (first = alloc.allocate());

        WHEN ("I allocate a few objects") {
            for (int i = 1; i < 25; i++) {
                int * tmp;
                CHECK_NOTHROW (tmp = alloc.allocate());

                THEN ("They align next to each other") {
                    CHECK (first + i == tmp);
                }
            }
        }

        WHEN ("I allocate too many objects") {
            CHECK_THROWS_AS (alloc.allocate(AMOUNT_ALLOCATED_OBJECTS), std::bad_alloc);
            alloc.allocate(AMOUNT_ALLOCATED_OBJECTS - 1);

            THEN ("I get an exception on all allocate calls") {
                CHECK_THROWS_AS (alloc.allocate(1), std::bad_alloc);
            }
        }

        CHECK_NOTHROW (alloc.deallocate (first));
        CHECK_NOTHROW (delete allocator);
    }

    // TODO: implement missing test
    SECTION ("I can allocate and deallocate space for several objects at a time") {
        auto allocator = new Allocator<float>();
        auto & alloc = * allocator;


    }

    // TODO: fix problem of reusability
    SECTION ("I can reuse deallocated space to postpone a heap overflow") {

        std::cout << "\nStart new test:" << std::endl;

        auto allocator = new Allocator<std::string>();
        auto & alloc = * allocator;

        for (int i = 0; i < 10; i++) {
            std::string * ptr;
            std::cout << "=========================\nIteration: \t" << i << std::endl;

            alloc.print_hdr();
            alloc.print();
            CHECK_NOTHROW (ptr = alloc.allocate (0.2 * AMOUNT_ALLOCATED_OBJECTS));
            alloc.print();
            CHECK_NOTHROW (alloc.deallocate(ptr, 0.2 * AMOUNT_ALLOCATED_OBJECTS));
            alloc.print();
            std::cout << std::endl;
        }
    }
}
