//
// Created by Selçuk Öztürk on 11/09/2017.
//

#ifndef ASSIGNMENT1_INTERSECTION_H
#define ASSIGNMENT1_INTERSECTION_H

#include <set>
#include "Rect.h"

class Intersection {
public:
    Intersection();

    //explicit Intersection(const Rect& rect);

    explicit Intersection(const Rect& rect, bool isIntersectRectangle = false);

    const Rect& getRect() const;

    void setRect(const Rect& rect);

    bool intersectsWith(Rect otherRect, Rect& intersectionRect);

    bool overlaps(Rect otherRect);

    //const std::vector<int>& getIndicies() const;
    const std::set<int>& getIndicies() const;

    void addIndex(int index);

    //void addIndex(const std::vector<int>& indexVector);
    void addIndex(const std::set<int>& indexSet);

private:
    //std::vector<int> rectIndicies;
    std::set<int> rectIndicies;
    Rect rect;
    bool isIntersectRectangle = false;

    bool isInRange(int value, int min, int max);
};

#endif //ASSIGNMENT1_INTERSECTION_H
