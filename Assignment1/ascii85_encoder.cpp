#include "ascii85_encoder.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

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

std::vector<uint8_t> decodeAscii85(const std::string& encoded) {
    std::vector<uint8_t> result;

    size_t i = 0;
    while (i < encoded.length()) {
        if (encoded[i] == 'z') {  // Обрабатываем специальный случай
            result.insert(result.end(), {0, 0, 0, 0});
            ++i;
        } else {
            uint32_t chunk = 0;

            // Читаем блок из пяти символов
            for (int j = 0; j < 5 && i + j < encoded.length(); ++j) {
                int value = encoded[i + j] - '!';  // Преобразуем символ обратно в числовое представление
                chunk += value * pow(85, 4 - j);
            }

            // Заполняем результат соответствующими байтами
            for (int j = 3; j >= 0; --j) {
                result.push_back(static_cast<uint8_t>(chunk >> (8 * j)));
            }

            i += 5;
        }
    }

    return result;
}
