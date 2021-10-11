#include "gtest/gtest.h"
#include "hmacmanager.hpp"

using namespace EDGE_CONNECTOR_LIBRARY;

TEST(CODE_GENERATION, INITIALISATION) {
    std::string key = "samplekeyfortest";
    std::string messageToComputeHashFor = "samplemessagefortest";
    std::string SHA256HASH_base64 = "ghmjdE4j+gORLNBXDFPZFbaEfMysc2RvddW/xu9v51o=";
   
    HMACManager testManager(key);
    EXPECT_EQ (testManager.get_HMAC_disgest(messageToComputeHashFor), SHA256HASH_base64);
}