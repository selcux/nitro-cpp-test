#include "Intersection.h"

Intersection::Intersection(const Rect& rect)
        :rect(rect) { }

Intersection::Intersection(const Rect& rect, const std::set<int>& indices)
        :rectIndices(indices), rect(rect) { }

const Rect& Intersection::getRect() const
{
    return rect;
}

bool Intersection::intersectsWith(Rect otherRect, Rect& intersectionRect)
{
    bool intersects = overlaps(otherRect);

    if (intersects) {
        int left = std::max(rect.x, otherRect.x);
        int top = std::max(rect.y, otherRect.y);
        int right = std::min(rect.x+rect.w, otherRect.x+otherRect.w);
        int bottom = std::min(rect.y+rect.h, otherRect.y+otherRect.h);

        intersectionRect = Rect(left, top, (right-left), (bottom-top));
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

void Intersection::addIndex(int index)
{
    rectIndices.emplace(index);
}

void Intersection::addIndex(const std::set<int>& indexSet)
{
    rectIndices.insert(indexSet.begin(), indexSet.end());
}

const std::set<int>& Intersection::getIndices() const
{
    return rectIndices;
}

