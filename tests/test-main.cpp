#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "test.h"

int main(int argc, const char* argv[])
{
    if (argc>1) {
        testDataDir = std::string(argv[1]);

        int result = Catch::Session().run(argc, argv);

        return (result<0xff ? result : 0xff);
    }

    std::cerr << "Test data directory path is required!" << std::endl;

    return 1;
}