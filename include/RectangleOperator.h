//
// Created by selcu on 10.09.2017.
//

#ifndef ASSIGNMENT1_RECTANGLEOPERATOR_H
#define ASSIGNMENT1_RECTANGLEOPERATOR_H

#include <list>
#include "Rect.h"
#include "Intersection.h"

class RectangleOperator {
public:
    RectangleOperator();

    void load(char* json_file_path);

    std::list<Intersection> getIntersections();

    const std::list<Rect>& getRects() const;

private:
    std::list<Rect> rects;

    json readJsonFile(char* json_file_path);

    const std::list<Rect> getRectsFromJson(json rects_json);
};

#endif //ASSIGNMENT1_RECTANGLEOPERATOR_H
