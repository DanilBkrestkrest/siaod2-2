#include "file_operations.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void createFile(const std::string& fileName) {
    std::ofstream file(fileName);

    if (file.is_open()) {
        file << "������, ��� ���������� �����." << std::endl;
        file << "-5 10 -8 7 -3" << std::endl;  // ������ ����������� ����� � �������������� �������
        std::cout << "���� " << fileName << " ������� ������." << std::endl;
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� �����." << std::endl;
    }
}

void printFile(const std::string& fileName) {
    std::ifstream file(fileName);

    if (file.is_open()) {
        std::string line;
        std::cout << "���������� ����� " << fileName << ":" << std::endl;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� ����� ��� ������." << std::endl;
    }
}

void appendToFile(const std::string& fileName, const std::string& content) {
    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        file << content << std::endl;
        std::cout << "������ ������� ��������� � ����� ����� " << fileName << "." << std::endl;
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� ����� ��� ���������� ������." << std::endl;
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
        std::cerr << "������ ��� �������� ����� ��� ������ �����." << std::endl;
    }

    return numbers;
}

void replaceNegativeWithSquareOfMin(const std::string& fileName) {
    std::vector<int> numbers = readNumbersFromFile(fileName);

    if (numbers.empty()) {
        std::cerr << "���� �� �������� �����." << std::endl;
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
        std::cout << "������������� ����� ������� �������� � ����� " << fileName << "." << std::endl;
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� ����� ��� ������ ������������� �����." << std::endl;
    }
}