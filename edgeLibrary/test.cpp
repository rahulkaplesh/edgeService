/*************************************************************************************
 * Starting the gtest for QT , we need a QEventLoop to terminate the application
 * correctly.
 ************************************************************************************/ 
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int res = RUN_ALL_TESTS();
}