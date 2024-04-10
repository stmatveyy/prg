#pragma once

#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>ы
#include <iomanip>
struct Book {
    std::string id, author, title;
    int pages;
};

void writeBooksToFile(const std::string& filename, const std::vector<Book>& books);
void readBooksFromFile(const std::string& filename, std::vector<Book>& books);
void addBook(std::vector<Book>& books);
void viewBooks(const std::vector<Book>& books);
void deleteBook(std::vector<Book>& books, const std::string& id);
void searchBook(const std::vector<Book>& books, const std::string& title);
void editBook(std::vector<Book>& books, const std::string& id);

#endif
