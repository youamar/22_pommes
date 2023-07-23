#include "catch.hpp"
#include "array.hpp"

TEST_CASE("Testing array instanciation")
{
    SECTION("Testing int cstr")
    {
        Array<int> a(5);
        REQUIRE(a.size() == 5);
    }

    SECTION("Testing C-array copy")
    {
        int ca[] = {1,2,3,4,5};
        Array<int> a(5, ca);

        REQUIRE(a.size() == 5);

        for(int i = 0; i < a.size(); i++)
            REQUIRE(a[i] == i + 1);
    }

    SECTION("Testing list instanciation")
    {
        Array<int> a = {1,2,3,4,5};
        REQUIRE(a.size() == 5);

        for(int i = 0; i < a.size(); i++)
            REQUIRE(a[i] == i + 1);
    }

    SECTION("Testing copy cstr")
    {
        Array<int> a = {1,2,3,4,5};
        Array<int> b(a);
        REQUIRE(a.size() == b.size());

        for(int i = 0; i < a.size(); i++)
            REQUIRE(a[i] == b[i]);
    }
}
