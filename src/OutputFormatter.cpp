#include "OutputFormatter.h"

std::string OutputFormatter::rectToString(Rect rect)
{
    std::ostringstream string_builder;

    string_builder << "Rectangle at (" << rect.x << ", "
                   << rect.y << "), w=" << rect.w << ", h="
                   << rect.h;

    return string_builder.str();
}

std::string OutputFormatter::rectsToString(Rect* rects, int count)
{
    std::ostringstream string_builder;

    string_builder << "Input:" << std::endl;

    for (int i = 0; i<count; ++i) {
        string_builder << "      " << (i+1) << ": " << rectToString(rects[i]) << std::endl;
    }

    return string_builder.str();
}

std::string OutputFormatter::rectListToString(const std::forward_list<Rect> rectList)
{
    std::ostringstream string_builder;

    string_builder << "Input:" << std::endl;

    for (auto& rect : rectList) {
        string_builder << rectToString(rect) << std::endl;
    }

    return string_builder.str();
}
