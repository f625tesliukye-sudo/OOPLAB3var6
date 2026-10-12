#include <iostream>
#include <limits>
#include <string>
#include "RealNumber.h"
#include "ArrayOfReals.h"

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ArrayOfReals userArray;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n================ MENU ================" << std::endl;
        std::cout << "1. Add a new real number to array" << std::endl;
        std::cout << "2. Display all numbers in array" << std::endl;
        std::cout << "3. Perform arithmetic operations (+, -, *, /) on two numbers" << std::endl;
        std::cout << "4. Search min/max in array (Overloaded method search)" << std::endl;
        std::cout << "5. Test Exception Handling (Division by zero / Invalid input)" << std::endl;
        std::cout << "6. Clear array" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Error: Invalid option. Please enter an integer." << std::endl;
            clearInputBuffer();
            continue;
        }

        switch (choice) {
        case 1: {
            std::cout << "Enter a real number: ";
            try {
                RealNumber num;
                std::cin >> num;
                userArray.addElement(num);
                std::cout << "Successfully added " << num << " to array." << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error caught: " << e.what() << std::endl;
                clearInputBuffer();
            }
            break;
        }
        case 2: {
            std::cout << "\nCurrent Array Content:" << std::endl;
            userArray.printAll();
            break;
        }
        case 3: {
            try {
                RealNumber n1, n2;
                std::cout << "Enter First Number: ";
                std::cin >> n1;
                std::cout << "Enter Second Number: ";
                std::cin >> n2;

                std::cout << "\n--- Results ---" << std::endl;
                std::cout << n1 << " + " << n2 << " = " << (n1 + n2) << std::endl;
                std::cout << n1 << " - " << n2 << " = " << (n1 - n2) << std::endl;
                std::cout << n1 << " * " << n2 << " = " << (n1 * n2) << std::endl;

                try {
                    std::cout << n1 << " / " << n2 << " = " << (n1 / n2) << std::endl;
                }
                catch (const std::exception& e) {
                    std::cout << "Division Error: " << e.what() << std::endl;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Input Error: " << e.what() << std::endl;
                clearInputBuffer();
            }
            break;
        }
        case 4: {
            if (userArray.getSize() == 0) {
                std::cout << "Array is empty! Add some numbers first." << std::endl;
                break;
            }
            std::cout << "\nChoose search criterion method:" << std::endl;
            std::cout << "a) String search ('min' or 'max')" << std::endl;
            std::cout << "b) Boolean search (1 for max, 0 for min)" << std::endl;
            std::cout << "c) Search relative to threshold value" << std::endl;
            std::cout << "Option (a/b/c): ";

            char subChoice;
            std::cin >> subChoice;

            try {
                if (subChoice == 'a' || subChoice == 'A') {
                    std::string crit;
                    std::cout << "Enter 'min' or 'max': ";
                    std::cin >> crit;
                    RealNumber result = userArray.find(crit);
                    std::cout << "Result: " << result << std::endl;
                }
                else if (subChoice == 'b' || subChoice == 'B') {
                    bool mode;
                    std::cout << "Enter 1 (Max) or 0 (Min): ";
                    std::cin >> mode;
                    RealNumber result = userArray.find(mode);
                    std::cout << "Result: " << result << std::endl;
                }
                else if (subChoice == 'c' || subChoice == 'C') {
                    double thresh;
                    bool findGreater;
                    std::cout << "Enter threshold double value: ";
                    std::cin >> thresh;
                    std::cout << "Find first number (1 for Greater, 0 for Smaller): ";
                    std::cin >> findGreater;
                    RealNumber result = userArray.find(thresh, findGreater);
                    std::cout << "Result: " << result << std::endl;
                }
                else {
                    std::cout << "Invalid choice." << std::endl;
                }
            }
            catch (const std::exception& e) {
                std::cout << "Search Exception: " << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "\n--- Testing Forced Exceptions ---" << std::endl;
            try {
                std::cout << "1. Attempting 5.0 / 0.0..." << std::endl;
                RealNumber num1(5.0), num2(0.0);
                RealNumber res = num1 / num2;
            }
            catch (const std::exception& e) {
                std::cout << "Caught expected exception: " << e.what() << std::endl;
            }

            try {
                std::cout << "2. Attempting to search min in empty array..." << std::endl;
                ArrayOfReals emptyArr;
                emptyArr.findMin();
            }
            catch (const std::exception& e) {
                std::cout << "Caught expected exception: " << e.what() << std::endl;
            }
            break;
        }
        case 6: {
            userArray.clear();
            std::cout << "Array cleared." << std::endl;
            break;
        }
        case 0:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Unknown option." << std::endl;
            break;
        }
    }

    return 0;
}