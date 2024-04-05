#pragma once
#ifndef WORDCOUNT_H
#define WORDCOUNT_H
#include <fstream>
#include <string>
#include <iostream>

inline int count_occurrences(const std::string& word, const std::string& filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 0;
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos == line.find(word, pos)) != std::string::npos) {
            count++;
            pos += word.length();
        }
    }

    file.close();
    return count;
}

#endif