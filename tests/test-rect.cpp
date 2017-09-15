#include "catch.hpp"

#include "Rect.h"

SCENARIO("Rectangles can be created with different parameters", "[rectangle]")
{
    GIVEN("A rectangle with x, y, width and height") {
        Rect rect(1, 2, 3, 4);

        REQUIRE(rect.x==1);
        REQUIRE(rect.y==2);
        REQUIRE(rect.w==3);
        REQUIRE(rect.h==4);
    }

    GIVEN("two rectangles to compare") {
        Rect rect1(100, 100, 50, 80);

        WHEN("rectangles are equal") {
            Rect rect2(100, 100, 50, 80);

            REQUIRE(rect1==rect2);
        }

        WHEN("rectangles are different") {
            Rect rect2(120, 120, 50, 80);

            REQUIRE_FALSE(rect1==rect2);
        }
    }

    GIVEN("A rectangle with JSON parameter") {
        Rect expectedRect(100, 100, 250, 80);
        json json_data = R"({ "x": 100, "y": 100, "w": 250, "h": 80 })"_json;
        Rect rect(json_data);

        REQUIRE(rect==expectedRect);
    }
}