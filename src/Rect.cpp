#include "Rect.h"

bool Rect::isInRange(int value, int min, int max)
{
    return (value>=min) && (value<=max);
}

bool Rect::overlaps(Rect rect)
{
    bool xRange = isInRange(x, rect.x, rect.x+rect.w)
            || isInRange(rect.x, x, x+w);

    bool yRange = isInRange(y, rect.y, rect.y+rect.h)
            || isInRange(rect.y, y, y+h);

    return xRange && yRange;
}

bool Rect::intersectsWith(Rect rect, Rect& intersectionRect)
{
    int x1 = std::max(x, rect.x);
    int y1 = std::max(y, rect.y);
    int x2 = std::min(x+w, rect.x+rect.w);
    int y2 = std::min(y+h, rect.y+rect.h);

    bool intersects = (x1<x2) || (y1<y2);

    if (intersects) {
        intersectionRect = Rect(x1, y1, (x2-x1), (y2-y1));
    }

    return intersects;
}
