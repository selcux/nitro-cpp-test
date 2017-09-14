#include "catch.hpp"

#include "Rect.h"

/*
TEST_CASE("Rectangle is created by parameters", "[rect]")
{
    Rect rect(1, 2, 3, 4);

    REQUIRE(rect.x==1);
    REQUIRE(rect.y==2);
    REQUIRE(rect.w==3);
    REQUIRE(rect.h==4);
}
*/

SCENARIO("Rectangles can be created with different parameters", "[rectangle]")
{
    GIVEN("A rectangle with x, y, width and height") {
        Rect rect(1, 2, 3, 4);

        REQUIRE(rect.x==1);
        REQUIRE(rect.y==2);
        REQUIRE(rect.w==3);
        REQUIRE(rect.h==4);
    }

    GIVEN("A rectangle with JSON parameter") {
        json json_data = R"({ "x": 100, "y": 100, "w": 250, "h": 80 })"_json;
        Rect rect(json_data);

        REQUIRE(rect.x==100);
        REQUIRE(rect.y==100);
        REQUIRE(rect.w==250);
        REQUIRE(rect.h==80);
    }
}