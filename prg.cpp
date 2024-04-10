#include "wordcount.cpp"
#include "books.h"
#include "matrix.h"

int main() {

	std::string word_to_find = "слов";
	std::string file_text = "файл.txt";
    std::string file_matrix = "файл1.txt";
	std::cout << "В файле" << "'"<< file_text <<"' Найдено " << count_occurrences(word_to_find, file_text) << " Вхождения/ий слова '" << word_to_find <<"'" << std::endl;

	Matrix ma1(3, 3);
	ma1.fillZeros();
	write_to_file(ma1, file_matrix);
	std::cout << "Матрица из файла: " << std::endl;
	read_from_file(file_matrix);

    std::vector<Book> books;
    std::string booksFilename = "books.txt";

    int choice;
    std::string input;
    readBooksFromFile(booksFilename, books);
    do {
        std::cout << "Меню:\n"
            << "1. Добавить книгу\n"
            << "2. Все книги\n"
            << "3. Удалить книгу\n"
            << "4. Поиск\n"
            << "5. Редактировать\n"
            << "6. ВЫХОД\n"
            << "Выбор: ";
        std::cin >> input;
        std::istringstream iss(input);
        if (!(iss >> choice)) {
            std::cout << "Ошибка. Введите номер. " << std::endl;
            continue;
        }

        switch (choice) {
        case 1:
            addBook(books);
            writeBooksToFile(booksFilename, books);
            break;
        case 2:
            
            viewBooks(books);
            break;
        case 3: {
            std::string id;
            std::cout << "ID книги для удаления: ";
            std::cin >> id;
            deleteBook(books, id);
            writeBooksToFile(booksFilename, books);
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Название книги для поиска: ";
            std::cin >> title;
            searchBook(books, title);
            break;
        }
        case 5: {
            std::string id;
            std::cout << "ID книги для изменения: ";
            std::cin >> id;
            editBook(books, id);
            writeBooksToFile(booksFilename, books);
            break;
        }
        case 6:
            std::cout << "Выход." << std::endl;
            break;
        default:
            std::cout << "Нет такого варианта. Попробуй снова. " << std::endl;
            break;
        }
    } while (choice != 6);

    return 0;
}

