#include "books.h"

void writeBooksToFile(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Невозможно открыть файл " << filename <<  std::endl;
        return;
    }
    for (const auto& book : books) {
        outFile << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
    }
    outFile.close();
}

void readBooksFromFile(const std::string& filename, std::vector<Book>& books) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Невозможно открыть файл " << filename << std::endl;
        return;
    }
    Book book;
    while (inFile >> book.id >> book.author >> book.title >> book.pages) {
        books.push_back(book);
    }
    inFile.close();
}

void addBook(std::vector<Book>& books) {
    Book newBook;
    std::cout << "Введите ID, Автора, название и кол-во страниц: ";
    try {
        std::cin >> newBook.id >> newBook.author >> newBook.title >> newBook.pages;
        if (!std::cin) {
            throw std::runtime_error("bruh");
        }
        std::cin.clear();
    }
    catch (...) {
        std::cout << "Ошибка! Проверь правильность данных. " << std::endl;
        exit(1);
    }
    books.push_back(newBook);
}

void viewBooks(const std::vector<Book>& books) {
    for (const auto& book : books) {
        std::cout << "ID " << std::setw(20) << "АВТОР " << std::setw(20)
            << "НАЗВАНИЕ " << std::setw(20)
            << "СТРАНИЦ" << std::endl;
        std::cout << book.id << " " << std::setiosflags(std::ios::left) << std::setw(20)
            << book.author << " " << std::setiosflags(std::ios::left) << std::setw(20)
            << book.title << " " << std::setiosflags(std::ios::left) << std::setw(20)
            << book.pages << " " << std::endl;
    }
}

void deleteBook(std::vector<Book>& books, const std::string& id) {
    books.erase(std::remove_if(books.begin(), books.end(), [&id](const Book& book) { return book.id == id; }), books.end());
}

void searchBook(const std::vector<Book>& books, const std::string& title) {
    auto it = std::find_if(books.begin(), books.end(), [&title](const Book& book) { return book.title == title; });
    if (it != books.end()) {
        std::cout << it->id << " " << it->author << " " << it->title << " " << it->pages << std::endl;
    }
    else {
        std::cout << "Книга не найдена." << std::endl;
    }
}

void editBook(std::vector<Book>& books, const std::string& id) {
    auto it = std::find_if(books.begin(), books.end(), [&id](const Book& book) { return book.id == id; });
    if (it != books.end()) {
        Book updatedBook;
        std::cout << "Введите новые данные: ";
        std::cin >> updatedBook.id >> updatedBook.author >> updatedBook.title >> updatedBook.pages;
        *it = updatedBook;
    }
    else {
        std::cout << "Книга с таким ID:  " << id << " не найдена." << std::endl;
    }
}