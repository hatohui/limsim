#include <hatogin/hatogin.h>

#include <doctest/doctest.h>

TEST_CASE("C API header compiles as C++") {
    world* w = nullptr;
    CHECK(w == nullptr);
}
