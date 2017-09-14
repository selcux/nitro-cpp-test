#include <iostream>
#include <OutputFormatter.h>
#include <RectangleOperator.h>

int main(int argc, char** argv)
{
    if (argc>1) {
        RectangleOperator rectangle_operator;
        rectangle_operator.load(argv[1]);

        std::cout << OutputFormatter::rectsToString(rectangle_operator.getRects())
                  << std::endl;

        auto rectList = rectangle_operator.getIntersections();

        std::cout << OutputFormatter::rectListToString(rectList) << std::endl;
    }
    else {
        std::cout << "The program must have a json file path as parameter." << std::endl;
    }

    return 0;
}
