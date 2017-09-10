#ifndef ASSIGNMENT1_OUTPUTFORMATTER_H
#define ASSIGNMENT1_OUTPUTFORMATTER_H

#include <string>
#include "Rect.h"

class OutputFormatter {
public:
	static std::string rectToString(Rect rect);

	static std::string rectsToString(Rect* rects, int count);
};


#endif //ASSIGNMENT1_OUTPUTFORMATTER_H
