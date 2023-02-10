#include <iostream>
#include "list.h"

int main() {
    List list;

    int numCount;
    
    std::cout << "Enter the number of values you want to add to the list: ";
    std::cin >> numCount;

    double num;
    for (int i = 0; i < numCount; i++) {
        std::cout << "Enter a number: ";
        std::cin >> num;
        list.addNumber(num);
    }

    std::cout << "Original ";
    list.displayList();

    std::cout << "Sorted ";
    list.sortData();
    list.displayList();

    std::cout << "Average: " << list.calculateAverage() << std::endl;
    std::cout << "Median: " << list.calculateMedian() << std::endl;

    int newSize;
    std::cout << "Enter the new size for the list: ";
    std::cin >> newSize;
    list.resizeList(newSize);

    std::cout << "Resized list: " << std::endl;
    list.displayList();

    return 0;
}