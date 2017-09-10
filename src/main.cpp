#include <iostream>
#include <OutputFormatter.h>
#include <RectangleOperator.h>
#include "helpers.h"

using json = nlohmann::json;


int main(int argc, char** argv) {
	/*
	    std::cout << argc << std::endl;
	
	    if (argc > 1) {
	        auto json_content = read_json(argv[1]);
	        std::ifstream json_file(argv[1]);
	        json j;
	        json_file >> j;
	        Rect r(j);
	
	        std::cout << OutputFormatter::rectToString(r) << std::endl;
	    } else {
	        std::cout << "Hello, World!" << std::endl;
	    }
	*/
	if (argc > 1) {
		RectangleOperator rectangle_operator;
		rectangle_operator.load(argv[1]);

		std::cout << OutputFormatter::rectsToString(rectangle_operator.getRects(),
		                                            rectangle_operator.getRectCount())
			<< std::endl;
	}

	return 0;
}
