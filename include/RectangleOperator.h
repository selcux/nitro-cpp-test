//
// Created by selcu on 10.09.2017.
//

#ifndef ASSIGNMENT1_RECTANGLEOPERATOR_H
#define ASSIGNMENT1_RECTANGLEOPERATOR_H

#include "Rect.h"
#include "json.hpp"

using json = nlohmann::json;

class RectangleOperator {
public:
	void load(char* json_file_path);

	Rect* getRects() const;

	int getRectCount() const;

private:
	Rect* rects;
	int rect_count;

	json readJsonFile(char* json_file_path);

	Rect* getRectsFromJson(json rects_json);
};


#endif //ASSIGNMENT1_RECTANGLEOPERATOR_H
