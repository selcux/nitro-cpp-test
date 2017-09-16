#include "catch.hpp"

#include "test.h"
#include "RectangleOperator.h"

SCENARIO("Rectangle operator can get and process input of rectangles", "[rectangle-operator]")
{
    GIVEN("JSON file") {
        WHEN("input is valid") {
            auto filePath = testDataDir+"/test_sample1.json";
            RectangleOperator rectangleOperator;

            REQUIRE_NOTHROW(rectangleOperator.load(filePath));
        }

        WHEN("input is empty") {
            RectangleOperator rectangleOperator;

            REQUIRE_THROWS(rectangleOperator.load(""));
        }

        WHEN("input content is empty") {
            auto filePath = testDataDir+"/test_sample2.json";
            RectangleOperator rectangleOperator;

            REQUIRE_THROWS(rectangleOperator.load(filePath));
        }

        WHEN("input is invalid") {
            auto filePath = testDataDir+"/test_sample3.json";
            RectangleOperator rectangleOperator;

            REQUIRE_THROWS(rectangleOperator.load(filePath));
        }
    }

    GIVEN("a valid input") {
        auto filePath = testDataDir+"/test_sample1.json";
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

            Intersection i1(Rect(140, 160, 210, 20), {0, 2});
            Intersection i2(Rect(160, 140, 190, 40), {0, 3});
            Intersection i3(Rect(140, 200, 230, 60), {1, 2});
            Intersection i4(Rect(160, 200, 210, 130), {1, 3});
            Intersection i5(Rect(160, 160, 230, 100), {2, 3});
            Intersection i6(Rect(160, 160, 190, 20), {0, 2, 3});
            Intersection i7(Rect(160, 200, 210, 60), {1, 2, 3});

            std::list<Intersection> expectedIntersections = {i1, i2, i3, i4, i5, i6, i7};

            for (auto& intersect : intersections) {
                REQUIRE(std::any_of(expectedIntersections.begin(),
                        expectedIntersections.end(),
                        [&](Intersection expected) {
                            Rect expRect = expected.getRect();
                            Rect intersectRect = intersect.getRect();

                            return (expected.getIndices()==intersect.getIndices()) &&
                                    (expRect==intersectRect);
                        }));
            }
        }
    }
}