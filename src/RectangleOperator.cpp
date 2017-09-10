#include <fstream>
#include "RectangleOperator.h"

json RectangleOperator::readJsonFile(char* json_file_path) {
	std::ifstream ifs(json_file_path);
	/*
		std::string content((std::istreambuf_iterator<char>(ifs)),
		                    std::istreambuf_iterator<char>());
	
		auto cstr = content.c_str();
		json rects_json = json::parse(cstr);
	*/
	json rects_json;
	ifs >> rects_json;

	return rects_json;
}

Rect* RectangleOperator::getRectsFromJson(json rects_json) {
	auto rects_json_array = rects_json["rects"];
	rect_count = rects_json_array.size();
	Rect* rects = new Rect[rect_count];
	int index = 0;

	for (json::iterator it = rects_json_array.begin(); it != rects_json_array.end(); ++it) {
		rects[index++] = Rect(*it);
	}

	return rects;
}

void RectangleOperator::load(char* json_file_path) {
	const auto rect_json = readJsonFile(json_file_path);
	this->rects = getRectsFromJson(rect_json);
}

Rect* RectangleOperator::getRects() const {
	return rects;
}

int RectangleOperator::getRectCount() const {
	return rect_count;
}
