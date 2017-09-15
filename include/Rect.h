#ifndef ASSIGNMENT1_RECT_H
#define ASSIGNMENT1_RECT_H

#include "json.hpp"

using json = nlohmann::json;

struct Rect {
    int x, y, w, h;

    Rect()
    = default;

    Rect(int x, int y, int w, int h)
            :x(x), y(y), w(w), h(h) { }

    explicit Rect(json j)
            :x(j["x"]), y(j["y"]), w(j["w"]), h(j["h"])
    {
    }

    bool operator==(const Rect& rect)
    {
        return x==rect.x && y==rect.y && w==rect.w && h==rect.h;
    }
};

#endif //ASSIGNMENT1_RECT_H
