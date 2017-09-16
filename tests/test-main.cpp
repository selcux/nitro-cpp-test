#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "test.h"

std::string testDataDir;

char** excludeFirstArgAsDataDir(int argc, char** argv)
{
    auto** newArgv = new char* [argc-1];

    for (int i = 0, j = 0; i<argc; ++i) {
        if (i!=1) {
            newArgv[j++] = argv[i];
        }
    }

    return newArgv;
}

int main(int argc, char* argv[])
{
    if (argc>1) {
        auto newArgv = excludeFirstArgAsDataDir(argc, argv);

        testDataDir = std::string(argv[1]);

        int result = Catch::Session().run(argc-1, newArgv);

        return (result<0xff ? result : 0xff);
    }

    std::cerr << "Test data directory path is required!" << std::endl;

    return 1;
}