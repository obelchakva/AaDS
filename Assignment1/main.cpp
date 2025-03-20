#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include "ascii85_encoder.cpp"

int main(int argc, char* argv[]) {
    bool isDecoding = false;
    
    if (argc > 1 && strcmp(argv[1], "-d") == 0) {
        isDecoding = true;
    }
    
    try {
        if (isDecoding) {
            std::string input;
            std::getline(std::cin, input);
            auto decodedData = decodeAscii85(input);
            
            for (auto byte : decodedData) {
                std::cout.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
            }
        } else {
            std::vector<uint8_t> buffer(1024);
            size_t bytesRead;
            
            do {
                bytesRead = std::cin.readsome(reinterpret_cast<char*>(buffer.data()), buffer.size());
                
                if (bytesRead > 0) {
                    auto encodedString = encodeAscii85({buffer.begin(), buffer.begin() + bytesRead});
                    std::cout << encodedString;
                }
            } while (!std::cin.eof());
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
