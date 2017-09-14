#include <fstream>
#include "RectangleOperator.h"

RectangleOperator::RectangleOperator() = default;

const std::list<Rect>& RectangleOperator::getRects() const
{
    return rects;
}

json RectangleOperator::readJsonFile(char* json_file_path)
{
    std::ifstream ifs(json_file_path);
    /*
        std::string content((std::istreambuf_iterator<char>(ifs)),
                            std::istreambuf_iterator<char>());

        auto cstr = content.c_str();
        json rects_json = json::parse(cstr);
    */
    json rects_json;
    ifs >> rects_json;

    return rects_json;
}

const std::list<Rect> RectangleOperator::getRectsFromJson(json rects_json)
{
    auto rects_json_array = rects_json["rects"];

    for (auto& it : rects_json_array) {
        rects.emplace_back(Rect(it));
    }

    return rects;
}

void RectangleOperator::load(char* json_file_path)
{
    const auto rect_json = readJsonFile(json_file_path);
    getRectsFromJson(rect_json);
}

std::list<Intersection> RectangleOperator::getIntersections()
{
    std::list<Intersection> rectanglesList;
    std::list<Intersection> intersetcionList;
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

        for (auto& rect : rectanglesList) {
            Rect intercetionRect{};
            if (pivot.intersectsWith(rect.getRect(), intercetionRect)) {
                Intersection intersection(intercetionRect, true);
                intersection.addIndex(pivot.getIndicies());
                intersection.addIndex(rect.getIndicies());

                intersetcionList.emplace_back(intersection);
            }
        }
    }

    return intersetcionList;
}


