#include "catch.hpp"
#include "array.hpp"
#include <stdexcept>

TEST_CASE("Array access")
{
	SECTION("Acces within bounds")
	{
		Array<int> a = {1,2,3,4,5};

		for(int i = 0; i < a.size(); i++)
		{
			REQUIRE_NOTHROW(a[i]);
            REQUIRE(a[i] == i + 1);
		}
	}

	SECTION("Acces out of bounds")
	{
		Array<int> a = {1,2,3,4,5};
		
		REQUIRE_THROWS(a[-1]);
		REQUIRE_THROWS_AS(a[-1],std::out_of_range);

		REQUIRE_THROWS(a[5]);
		REQUIRE_THROWS_AS(a[5],std::out_of_range);
	}
}
