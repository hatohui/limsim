#include <limsim/limsim.h>

#include <doctest/doctest.h>

TEST_CASE("C API header compiles as C++") {
    limsim_world* world = nullptr;
    CHECK(world == nullptr);
}
