#include "Intersection.h"

Intersection::Intersection() = default;

/*
Intersection::Intersection(const Rect& rect)
        :rect(rect) { }
*/

Intersection::Intersection(const Rect& rect, bool isIntersectRectangle)
        :rect(rect), isIntersectRectangle(isIntersectRectangle) { }

const Rect& Intersection::getRect() const
{
    return rect;
}

void Intersection::setRect(const Rect& rect)
{
    Intersection::rect = rect;
}

bool Intersection::intersectsWith(Rect otherRect, Rect& intersectionRect)
{
    //bool intersects = (x1<x2) || (y1<y2);
    bool intersects = overlaps(otherRect);

    if (intersects) {
        int x1 = std::max(rect.x, otherRect.x);
        int y1 = std::max(rect.y, otherRect.y);
        int x2 = std::min(rect.x+rect.w, otherRect.x+otherRect.w);
        int y2 = std::min(rect.y+rect.h, otherRect.y+otherRect.h);

        intersectionRect = Rect(x1, y1, (x2-x1), (y2-y1));
    }

    return intersects;
}

bool Intersection::isInRange(int value, int min, int max)
{
    return (value>=min) && (value<=max);
}

bool Intersection::overlaps(Rect otherRect)
{
    bool xRange = isInRange(rect.x, otherRect.x, otherRect.x+otherRect.w)
            || isInRange(otherRect.x, rect.x, rect.x+rect.w);

    bool yRange = isInRange(rect.y, otherRect.y, otherRect.y+otherRect.h)
            || isInRange(otherRect.y, rect.y, rect.y+rect.h);

    return xRange && yRange;
}

/*
const std::vector<int>& Intersection::getIndicies() const
{
    return rectIndicies;
}
*/

void Intersection::addIndex(int index)
{
    //rectIndicies.emplace_back(index);
    rectIndicies.emplace(index);
}

/*
void Intersection::addIndex(const std::vector<int>& indexVector)
{
    rectIndicies.insert(rectIndicies.end(), indexVector.begin(), indexVector.end());
}
*/

void Intersection::addIndex(const std::set<int>& indexSet)
{
    rectIndicies.insert(indexSet.begin(), indexSet.end());
}

const std::set<int>& Intersection::getIndicies() const
{
    return rectIndicies;
}
