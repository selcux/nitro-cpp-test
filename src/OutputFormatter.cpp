#include "OutputFormatter.h"

std::string OutputFormatter::rectToString(Rect rect)
{
    std::ostringstream string_builder;

    string_builder << "(" << rect.x << ", "
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
        string_builder << "      Rectangle at " << i++ << ": " << rectToString(rect) << std::endl;
    }

    return string_builder.str();
}

std::string OutputFormatter::rectListToString(const std::list<Intersection> intersectList)
{
    std::ostringstream string_builder;

    string_builder << "Intersections:" << std::endl;

    for (auto& intersect : intersectList) {
        std::ostringstream rectangles_sb;
/*
        unsigned long indexCount = intersect.getIndicies().size();

        for (int i = 0; i<indexCount-1; ++i) {
            rectangles_sb << intersect.getIndicies()[i];

            if (i-1<indexCount-1) {
                rectangles_sb << " and ";
            }
            else {
                rectangles_sb << ", ";
            }
        }

        rectangles_sb << intersect.getIndicies()[indexCount-1];
*/
        for (int index : intersect.getIndicies()) {
            rectangles_sb << index+1 << ", ";
        }

        string_builder << "      Between rectangle " << rectangles_sb.str()
                       << " at " << rectToString(intersect.getRect()) << std::endl;
    }

    return string_builder.str();
}
