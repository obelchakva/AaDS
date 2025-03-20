#ifndef ASCII85_ENCODER_H
#define ASCII85_ENCODER_H

#include <string>
#include <vector>
#include <cstdint>

std::string encodeAscii85(const std::vector<uint8_t>& data);
std::vector<uint8_t> decodeAscii85(const std::string& encoded);

#endif // ASCII85_ENCODER_H
