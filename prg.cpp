#include "wordcount.h"
#include "matrix.h"

int main() {

    //std::string word = "заданное_слово";
    std::string filename = "текстовый_файл.txt";
    //int occurrences = countOccurrences(word, filename);
    
    Matrix mat(3, 3);
    mat.fillZeros();
    write_to_file(mat, filename);
    return 0;
}
