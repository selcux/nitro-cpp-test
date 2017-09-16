#include <fstream>
#include <utility>
#include <iostream>
#include "RectangleOperator.h"

RectangleOperator::RectangleOperator() = default;

const std::list<Rect>& RectangleOperator::getRects() const
{
    return rects;
}

json RectangleOperator::readJsonFile(const std::string& jsonFilePath)
{
    std::ifstream ifs(jsonFilePath);

    json rectsJson;
    ifs >> rectsJson;

    return rectsJson;
}

const std::list<Rect> RectangleOperator::getRectsFromJson(json rectsJson)
{
    auto rectsJsonArray = rectsJson["rects"];

    for (auto& it : rectsJsonArray) {
        rects.emplace_back(Rect(it));
    }

    return rects;
}

void RectangleOperator::load(const std::string& jsonFilePath)
{
    const auto rectJson = readJsonFile(jsonFilePath);
    getRectsFromJson(rectJson);
}

std::list<Intersection> RectangleOperator::getIntersections()
{
    std::list<Intersection> rectanglesList;
    std::list<Intersection> intersetcionList;
    std::list<Intersection> intersectionBuffer;

    int index = 0;
    for (auto r : rects) {
        Intersection intersect(r);
        intersect.addIndex(index);
        rectanglesList.emplace_back(intersect);
        ++index;
    }

    while (!rectanglesList.empty()) {
        auto pivot = rectanglesList.front();
        rectanglesList.pop_front();

        for (const auto& rect : rectanglesList) {
            Rect intercetionRect{};
            if (pivot.intersectsWith(rect.getRect(), intercetionRect)) {
                Intersection intersection(intercetionRect);
                intersection.addIndex(pivot.getIndices());
                intersection.addIndex(rect.getIndices());

                if (std::none_of(intersetcionList.begin(), intersetcionList.end(),
                        [&](Intersection intrsct) {
                            return intersection.getIndices()==intrsct.getIndices();
                        })) {
                    intersetcionList.emplace_back(intersection);
                    intersectionBuffer.emplace_back(intersection);
                }
            }
        }

        if (!intersectionBuffer.empty()) {
            rectanglesList.insert(rectanglesList.end(),
                    intersectionBuffer.begin(), intersectionBuffer.end());
            intersectionBuffer.clear();
        }
    }

    return intersetcionList;
}


