#include "catch.hpp"

#include "RectangleOperator.h"

SCENARIO("Rectangle operator can get and process input of rectangles", "[rectangle-operator]")
{
    GIVEN("JSON file") {
        WHEN("input is valid") {
            char filePath[] = "test_sample1.json";
            RectangleOperator rectangleOperator;

            REQUIRE_NOTHROW(rectangleOperator.load(filePath));
        }

        WHEN("input is NULL") {
            RectangleOperator rectangleOperator;

            REQUIRE_THROWS(rectangleOperator.load(nullptr));
        }

        WHEN("input is empty") {
            char filePath[] = "test_sample2.json";
            RectangleOperator rectangleOperator;

            REQUIRE_THROWS(rectangleOperator.load(filePath));
        }

        WHEN("input is invalid") {
            char filePath[] = "test_sample3.json";
            RectangleOperator rectangleOperator;

            REQUIRE_THROWS(rectangleOperator.load(filePath));
        }
    }

    GIVEN("a valid input") {
        char filePath[] = "test_sample1.json";
        RectangleOperator rectangleOperator;

        rectangleOperator.load(filePath);

        WHEN("JSON is loaded") {
            Rect r1(100, 100, 250, 80);
            Rect r2(120, 200, 250, 150);
            Rect r3(140, 160, 250, 100);
            Rect r4(160, 140, 350, 190);

            std::list<Rect> expectedRects = {r1, r2, r3, r4};

            const auto& rects = rectangleOperator.getRects();

            for (auto& r : rects) {
                REQUIRE(std::any_of(expectedRects.begin(),
                        expectedRects.end(),
                        [&](Rect er) {
                            return er==r;
                        }));
            }
        }

        WHEN("rectangles intersect") {
            std::list<Intersection> intersections = rectangleOperator.getIntersections();


        }
    }
}