#include "catch.hpp"

#include "Intersection.h"

SCENARIO("Intersection can use rectangles to check if they overlap or not", "[intersection]")
{
    GIVEN("An intersection with a rectangle parameter") {
        Rect rect(100, 100, 100, 100);
        Intersection intersection(rect);

        WHEN("gets the given rectangle") {
            REQUIRE(rect.x==intersection.getRect().x);
            REQUIRE(rect.y==intersection.getRect().y);
            REQUIRE(rect.w==intersection.getRect().w);
            REQUIRE(rect.h==intersection.getRect().h);
        }

        WHEN("the default index set is empty") {
            REQUIRE(intersection.getIndices().empty());
        }

        WHEN("a single rectangle index is added") {
            intersection.addIndex(17);

            const auto& indexSet = intersection.getIndices();

            REQUIRE(1==indexSet.size());

            const auto is_in = indexSet.find(17)!=indexSet.end();
            REQUIRE(is_in);
        }

        WHEN("a set of indicies are added") {
            std::set<int> indices = {1, 2, 3, 4, 5};
            intersection.addIndex(indices);

            const auto& indexSet = intersection.getIndices();

            for (const auto& index : indices) {
                auto is_in = indexSet.find(index)!=indexSet.end();
                REQUIRE(is_in);
            }
        }

        GIVEN("a rectangle to intersect") {
            Rect otherRect(150, 150, 100, 100);

            WHEN("overlaps with the rectangle") {
                REQUIRE(intersection.overlaps(otherRect));
            }

            WHEN("intersects with the rectangle") {
                Rect intersectionRect{};
                bool intersects = intersection.intersectsWith(otherRect, intersectionRect);

                REQUIRE(intersects);

                REQUIRE(intersectionRect.x==150);
                REQUIRE(intersectionRect.y==150);
                REQUIRE(intersectionRect.w==50);
                REQUIRE(intersectionRect.h==50);
            }
        }

        GIVEN("a rectangle does NOT to intersect") {
            Rect otherRect(0, 0, 80, 50);

            WHEN("does not overlap with the rectangle") {
                REQUIRE_FALSE(intersection.overlaps(otherRect));
            }

            WHEN("does not intersect with the rectangle") {
                Rect intersectionRect{};
                bool intersects = intersection.intersectsWith(otherRect, intersectionRect);

                REQUIRE_FALSE(intersects);
            }
        }

    }
}