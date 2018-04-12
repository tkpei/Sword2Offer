#include <iostream>

#include "gtest/gtest.h"
#include "common/log.h"

int main(int argc, char **argv)
{
    armnetLog.init(armnet::LOG_DEBUG);

    printf("Running main() from main\n");
    testing::InitGoogleTest(&argc, argv);
    //testing::GTEST_FLAG(filter) = "ArrayFindTest.*";
    //testing::GTEST_FLAG(filter) = "FrogJumpTest.*";
    //testing::GTEST_FLAG(filter) = "PrintMatrixTest.*";
    testing::GTEST_FLAG(filter) = "ReplaceSpaceTest.*";

    RUN_ALL_TESTS();
    return 0;
}