#include "file_operations.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

    while (true)
    {



        cout << "Меню:" << endl;
        cout << "1. Создать файл" << endl;
        cout << "2. Вывести содержимое файла" << endl;
        cout << "3. Добавить данные в конец файла" << endl;
        cout << "4. Заменить отрицательные числа на квадрат самого маленького числа" << endl;
        cout << "5. Выход" << endl;

        cout << "Выберите пункт меню: ";
        int choice;
        cin >> choice;
        cout << endl;

		system("cls");

        switch (choice)
        {
            case 1:
            {
                cout << "Введите название файла: ";
                string fileName;
                cin >> fileName;
                cout << endl;
                createFile(fileName);
                break;

            }
            case 2:
            {
                cout << "Введите название файла: ";
                string fileName;
                cin >> fileName;
                cout << endl;
                printFile(fileName);
                break;
            }
            case 3:
            {
                cout << "Введите название файла: ";
                string fileName;
                cin >> fileName;
                cout << endl;

                cout << "Введите данные для добавления в конец файла:";
                cin.ignore();
                string additionalContent;
                getline(cin, additionalContent);
                appendToFile(fileName, additionalContent);
				break;
            }
            case 4:
            {
                cout << "Введите название файла: ";
                string fileName;
                cin >> fileName;
                cout << endl;
                replaceNegativeWithSquareOfMin(fileName);
                cout << "Результат замены отрицательных чисел на квадрат самого маленького числа" << endl;
                printFile(fileName);
                break;
            }
            case 5:
            {
                return 0;
            }
        }
    }
    

    
}
