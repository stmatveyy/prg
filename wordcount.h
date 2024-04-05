#pragma once
#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <fstream>
#include <string>
#include <iostream>
int count_occurrences(const std::string& word, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 0;
    }

    std::string line;
    int count = 0;
    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != std::string::npos) {
            count++;
            pos += word.length();
        }
    }

    file.close();
    return count;
}

#endif