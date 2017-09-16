#include <iostream>
#include <OutputFormatter.h>
#include <RectangleOperator.h>

int main(int argc, char** argv)
{
    if (argc>1) {
        try {
            RectangleOperator rectangleOperator;
            rectangleOperator.load(argv[1]);

            std::cout << OutputFormatter::rectsToString(rectangleOperator.getRects())
                      << std::endl;

            auto rectList = rectangleOperator.getIntersections();

            std::cout << OutputFormatter::rectListToString(rectList) << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "The program must have a json file path as parameter." << std::endl;
    }

    return 0;
}
