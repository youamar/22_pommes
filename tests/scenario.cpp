#include "catch.hpp"
#include "array.hpp"
#include <stdexcept>

SCENARIO("You cannot access an array out of its bounds")
{
	GIVEN("An array with 5 items")
	{
        Array<int> a = {1,2,3,4,5};
		REQUIRE(a.size() == 5);

		WHEN("The array is accessed within bounds")
		{
			THEN("The element is accessed")
			{
				for(int i = 0; i < a.size(); i++)
				{
					REQUIRE_NOTHROW(a[i]);
		            REQUIRE(a[i] == i + 1);
				}	
			}
		}
		WHEN("The array is accessed out of its bounds")
		{
			THEN("A std::out_of_bound exception is thrown")
			{
				REQUIRE_THROWS(a[-1]);
				REQUIRE_THROWS_AS(a[-1],std::out_of_range);

				REQUIRE_THROWS(a[5]);
				REQUIRE_THROWS_AS(a[5],std::out_of_range);
			}
		}
	}
}
