#include <string>
#include "catch.hpp"

#include "Rect.h"
#include "Intersection.h"
#include "OutputFormatter.h"

SCENARIO("Output formatter can format of different struct types to string", "[output-formatter]")
{
    GIVEN("a rectangle") {
        Rect rect(100, 200, 150, 80);

        std::string formattedOutput = OutputFormatter::rectToString(rect);

        std::string expectedOutput = "(100, 200), w=150, h=80";

        REQUIRE(formattedOutput==expectedOutput);
    }

    GIVEN("a list of rectangles") {
        Rect rect1(100, 200, 150, 80);
        Rect rect2(120, 210, 170, 100);
        std::list<Rect> rectList = {rect1, rect2};

        std::string formattedOutput = OutputFormatter::rectsToString(rectList);

        std::string expectedOutput = "Input:\n"
                "      Rectangle at 1: (100, 200), w=150, h=80\n"
                "      Rectangle at 2: (120, 210), w=170, h=100\n";

        REQUIRE(formattedOutput==expectedOutput);
    }

    GIVEN("a list of intersections") {
        Rect rect1(100, 200, 150, 80);
        Rect rect2(120, 210, 170, 100);

        Intersection intersection1(rect1);
        intersection1.addIndex(0);
        intersection1.addIndex(2);

        Intersection intersection2(rect2);
        intersection2.addIndex(1);
        intersection2.addIndex(2);

        std::list<Intersection> intersectionList = {intersection1, intersection2};

        std::string formattedOutput = OutputFormatter::rectListToString(intersectionList);

        std::string expectedOutput = "Intersections:\n"
                "      Between rectangle 1 and 3 at (100, 200), w=150, h=80\n"
                "      Between rectangle 2 and 3 at (120, 210), w=170, h=100\n";

        REQUIRE(formattedOutput==expectedOutput);
    }
}