#ifndef ASSIGNMENT1_RECT_H
#define ASSIGNMENT1_RECT_H

#include "json.hpp"

using json = nlohmann::json;

struct Rect {
public:
    int x, y, w, h;

    Rect()
    = default;

    Rect(int x, int y, int w, int h)
            :x(x), y(y), w(w), h(h) { }

    explicit Rect(json j)
            :x(j["x"]), y(j["y"]), w(j["w"]), h(j["h"])
    {
    }

    bool overlaps(Rect rect);

    bool intersectsWith(Rect rect, Rect& intersectionRect);

private:
    bool isInRange(int value, int min, int max);
};

#endif //ASSIGNMENT1_RECT_H
