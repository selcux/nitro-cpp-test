#include "OutputFormatter.h"

std::string OutputFormatter::rectToString(Rect rect)
{
    std::ostringstream string_builder;

    string_builder << "Rectangle at (" << rect.x << ", "
                   << rect.y << "), w=" << rect.w << ", h="
                   << rect.h;

    return string_builder.str();
}

std::string OutputFormatter::rectsToString(std::list<Rect> rects)
{
    std::ostringstream string_builder;

    string_builder << "Input:" << std::endl;

    int i = 1;
    for (auto& rect : rects) {
        string_builder << "      " << i << ": " << rectToString(rect) << std::endl;
    }

    return string_builder.str();
}

std::string OutputFormatter::rectListToString(const std::list<Intersection> intersectList)
{
    std::ostringstream string_builder;

    string_builder << "Input:" << std::endl;

    for (auto& intersect : intersectList) {
        string_builder << rectToString(intersect.getRect()) << std::endl;
    }

    return string_builder.str();
}
