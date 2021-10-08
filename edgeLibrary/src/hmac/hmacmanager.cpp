#include <hmacmanager.hpp>

#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/base64.h>

using namespace EDGE_CONNECTOR_LIBRARY;

HMACManager::HMACManager(std::string &aHMAC_KEY) {
    mHMAC_KEY = std::make_shared<std::string>(aHMAC_KEY);
}

std::string HMACManager::get_HMAC_disgest(std::string &aPayload) {
    std::string digest;
    CryptoPP::SHA256 hash;

    CryptoPP::StringSource foo(aPayload, true,
    new CryptoPP::HashFilter(hash,
        new CryptoPP::Base64Encoder (
            new CryptoPP::StringSink(digest))));

    return digest;
}