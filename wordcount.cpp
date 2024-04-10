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
    while (getline(file, line)) {
        size_t pos = 0;

        pos = line.find(word, pos);
        while (pos != std::string::npos) {
            pos = line.find(word, pos + word.length());
            count++;

        }
    }
    file.close();
    return count;
}
