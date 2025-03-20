#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

std::string encodeAscii85(const std::vector<uint8_t>& data) {
    std::string result;
    
    for (size_t i = 0; i < data.size(); i += 4) {
        uint32_t chunk = 0;
        
        // Читаем блок данных размером 4 байта
        for (int j = 0; j < 4 && i + j < data.size(); ++j) {
            chunk |= static_cast<uint32_t>(data[i + j]) << (24 - j * 8);
        }
        
        if (chunk == 0) {  // Специальный случай для нулевого блока
            result.push_back('z');
        } else {
            for (int j = 4; j >= 0; --j) {
                char c = '!' + (chunk % 85);  // Преобразуем значение в диапазон ASCII85
                result.push_back(c);
                chunk /= 85;
            }
        }
    }
    
    return result;
}
