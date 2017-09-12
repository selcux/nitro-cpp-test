#ifndef ASSIGNMENT1_OUTPUTFORMATTER_H
#define ASSIGNMENT1_OUTPUTFORMATTER_H

#include <string>
#include "Rect.h"

class OutputFormatter {
public:
    static std::string rectToString(Rect rect);

    static std::string rectsToString(Rect* rects, int count);

    static std::string rectListToString(std::forward_list<Rect> rectList);
};

#endif //ASSIGNMENT1_OUTPUTFORMATTER_H
