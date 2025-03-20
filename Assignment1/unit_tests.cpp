#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "ascii85_encoder.h"

TEST(Ascii85Tests, BasicEncoding) {
    std::vector<uint8_t> data = {0x01, 0x02, 0x03, 0x04};
    std::string expectedOutput = "<9jqo^Blb";

    std::string actualOutput = encodeAscii85(data);

    EXPECT_EQ(expectedOutput, actualOutput);
}

TEST(Ascii85Tests, BasicDecoding) {
    std::string encodedInput = "<9jqo^Blb";
    std::vector<uint8_t> expectedOutput = {0x01, 0x02, 0x03, 0x04};

    std::vector<uint8_t> actualOutput = decodeAscii85(encodedInput);

    EXPECT_EQ(expectedOutput, actualOutput);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
