#include "file_operations.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void createFile(const std::string& fileName) {
    std::ofstream file(fileName);

    if (file.is_open()) {
        file << "Привет, это содержимое файла." << std::endl;
        file << "-5 10 -8 7 -3" << std::endl;  // Пример содержимого файла с отрицательными числами
        std::cout << "Файл " << fileName << " успешно создан." << std::endl;
        file.close();
    }
    else {
        std::cerr << "Ошибка при создании файла." << std::endl;
    }
}

void printFile(const std::string& fileName) {
    std::ifstream file(fileName);

    if (file.is_open()) {
        std::string line;
        std::cout << "Содержимое файла " << fileName << ":" << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла для чтения." << std::endl;
    }
}

void appendToFile(const std::string& fileName, const std::string& content) {
    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        file << content << std::endl;
        std::cout << "Данные успешно добавлены в конец файла " << fileName << "." << std::endl;
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла для добавления данных." << std::endl;
    }
}

std::vector<int> readNumbersFromFile(const std::string& fileName) {
    std::vector<int> numbers;
    std::ifstream file(fileName);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int value;
            while (iss >> value) {
                numbers.push_back(value);
            }
        }
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла для чтения чисел." << std::endl;
    }

    return numbers;
}

void replaceNegativeWithSquareOfMin(const std::string& fileName) {
    std::vector<int> numbers = readNumbersFromFile(fileName);

    if (numbers.empty()) {
        std::cerr << "Файл не содержит чисел." << std::endl;
        return;
    }

    int minNumber = *std::min_element(numbers.begin(), numbers.end());

    std::ofstream file(fileName);

    if (file.is_open()) {
        for (int& number : numbers) {
            if (number < 0) {
                number = minNumber * minNumber;
            }
            file << number << " ";
        }
        std::cout << "Отрицательные числа успешно заменены в файле " << fileName << "." << std::endl;
        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла для замены отрицательных чисел." << std::endl;
    }
}