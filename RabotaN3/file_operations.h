#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>
#include <vector>

void createFile(const std::string& fileName);
void printFile(const std::string& fileName);
void appendToFile(const std::string& fileName, const std::string& content);
std::vector<int> readNumbersFromFile(const std::string& fileName);
void replaceNegativeWithSquareOfMin(const std::string& fileName);

#endif