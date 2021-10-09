#include "gtest/gtest.h"
#include "hmacmanager.hpp"

using namespace EDGE_CONNECTOR_LIBRARY;

TEST(CODE_GENERATION, INITIALISATION) {

    std::string key = "samplekeyfortest";
    std::string messageToComputeHashFor = "samplemessagefortest";
    std::string SHA256HASH = "8219a3744e23fa03912cd0570c53d915b6847cccac73646f75d5bfc6ef6fe75a";
   
    HMACManager testManager(key);
    EXPECT_EQ (testManager.get_HMAC_disgest(messageToComputeHashFor), SHA256HASH);
}