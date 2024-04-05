#include "wordcount.h"
#include "matrix.h"

int main() {

    std::string word = "бим";
    std::string filename = "файл1.txt";
    //int occurrences = count_occurrences(word, filename);
    //std::cout << occurrences << std::endl;
    Matrix mat(3, 3);
    mat.fillZeros();
    mat.write_to_binary(mat, filename);
    return 0;
}
