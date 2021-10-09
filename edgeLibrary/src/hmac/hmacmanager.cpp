#include <hmacmanager.hpp>
#include <string_view>

using namespace EDGE_CONNECTOR_LIBRARY;

HMACManager::HMACManager(std::string &aHMAC_KEY) {
    mHMAC_KEY = std::make_shared<std::string>(aHMAC_KEY);
    mhmacFilter = CryptoPP::HMAC<CryptoPP::SHA256>(reinterpret_cast<byte const*>(mHMAC_KEY.get()->c_str()), mHMAC_KEY.get()->size());
}

std::string HMACManager::get_HMAC_disgest(std::string &aPayload) {
    std::string digest;

    CryptoPP::StringSource foo(aPayload, true,
        new CryptoPP::HashFilter(mhmacFilter,
            new CryptoPP::Base64Encoder (
                new CryptoPP::StringSink(digest), false)));

    return digest;
}