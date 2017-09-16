#include <queue>
#include "OutputFormatter.h"

std::string OutputFormatter::rectToString(Rect rect)
{
    std::ostringstream stringBuilder;

    stringBuilder << "(" << rect.x << ", "
                  << rect.y << "), w=" << rect.w << ", h="
                  << rect.h;

    return stringBuilder.str();
}

std::string OutputFormatter::rectsToString(std::list<Rect> rects)
{
    std::ostringstream stringBuilder;

    stringBuilder << "Input:" << std::endl;

    int i = 1;
    for (auto& rect : rects) {
        stringBuilder << "      Rectangle at " << i++ << ": " << rectToString(rect) << std::endl;
    }

    return stringBuilder.str();
}

std::string OutputFormatter::rectListToString(const std::list<Intersection> intersectList)
{
    std::ostringstream stringBuilder;

    stringBuilder << "Intersections:" << std::endl;

    for (auto& intersect : intersectList) {
        stringBuilder << "      Between rectangle " << rectIndexToString(intersect.getIndices())
                      << " at " << rectToString(intersect.getRect()) << std::endl;
    }

    return stringBuilder.str();
}

std::string OutputFormatter::rectIndexToString(const std::set<int>& indexSet)
{
    std::list<int> indexList;
    std::ostringstream rectanglesSb;

    indexList.insert(indexList.end(), indexSet.begin(), indexSet.end());

    while (!indexList.empty()) {
        int index = indexList.front();
        indexList.pop_front();

        rectanglesSb << (index+1);

        if (indexList.size()>1) {
            rectanglesSb << ", ";
        }
        else if (indexList.size()==1) {
            rectanglesSb << " and ";
        }
    }

    return rectanglesSb.str();
}
