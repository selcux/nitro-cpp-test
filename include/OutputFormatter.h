#ifndef ASSIGNMENT1_OUTPUTFORMATTER_H
#define ASSIGNMENT1_OUTPUTFORMATTER_H

#include <string>
#include <list>
#include "Rect.h"
#include "Intersection.h"

class OutputFormatter {
public:
    static std::string rectToString(Rect rect);

    static std::string rectsToString(std::list<Rect> rects);

    static std::string rectListToString(std::list<Intersection> intersectList);
};

#endif //ASSIGNMENT1_OUTPUTFORMATTER_H
