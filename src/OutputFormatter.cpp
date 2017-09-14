#include <queue>
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
        string_builder << "      Between rectangle " << rectIndexToString(intersect.getIndices())
                       << " at " << rectToString(intersect.getRect()) << std::endl;
    }

    return string_builder.str();
}

std::string OutputFormatter::rectIndexToString(const std::set<int>& indexSet)
{
    std::list<int> indexList;
    std::ostringstream rectangles_sb;

    indexList.insert(indexList.end(), indexSet.begin(), indexSet.end());

    while (!indexList.empty()) {
        int index = indexList.front();
        indexList.pop_front();

        rectangles_sb << (index+1);

        if (indexList.size()>1) {
            rectangles_sb << ", ";
        }
        else if (indexList.size()==1) {
            rectangles_sb << " and ";
        }
    }

    return rectangles_sb.str();
}
