#include <hmacmanager.hpp>
#include <string_view>

using namespace EDGE_CONNECTOR_LIBRARY;

/**
 * @brief Construct a new HMACManager::HMACManager object required for hashing a payload
 * to generate a HMAC code 
 * @param aHMAC_KEY key to be used for generating the HMAC id
 */
HMACManager::HMACManager(std::string &aHMAC_KEY) {
    mHMAC_KEY = std::make_shared<std::string>(aHMAC_KEY);
    mhmacFilter = CryptoPP::HMAC<CryptoPP::SHA256>(reinterpret_cast<byte const*>(mHMAC_KEY.get()->c_str()), mHMAC_KEY.get()->size());
}

/**
 * @brief Function to actualy generating a base64 encoded HMAC id * 
 * @param aPayload payload for which the HMAC code has to be generated
 * @return std::string HMAC code with base 64 encoding
 */
std::string HMACManager::get_HMAC_disgest(std::string &aPayload) {
    std::string digest;

    CryptoPP::StringSource foo(aPayload, true,
        new CryptoPP::HashFilter(mhmacFilter,
            new CryptoPP::Base64Encoder (
                new CryptoPP::StringSink(digest), false)));

    return digest;
}