#ifndef ASSIGNMENT1_RECT_H
#define ASSIGNMENT1_RECT_H

#include "json.hpp"

using json = nlohmann::json;

struct Rect {
	int x, y, w, h;

	Rect() {
	}

	Rect(json j) : x(j["x"]), y(j["y"]), w(j["w"]), h(j["h"]) {
	}
};

#endif //ASSIGNMENT1_RECT_H
