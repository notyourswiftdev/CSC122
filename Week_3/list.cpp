#include "list.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void List::addNumber(double num) {
    numbers.push_back(num);
}

void List::displayList() {
    std::cout << "list is: [ ";
    for (double num: numbers) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
}

double List::calculateAverage() {
    return std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
}

double List::calculateMedian() {
    std::sort(numbers.begin(), numbers.end());
    int n = numbers.size();
    return (n % 2 == 0) ? (numbers[n / 2 - 1] + numbers[n / 2]) / 2 : numbers[n / 2];  
}

void List::sortData() {
    std::sort(numbers.begin(), numbers.end());
}

void List::resizeList(int newSize) {
    std::vector<double> newNumbers(newSize);
    int numToCopy = std::min(newSize, (int)numbers.size());
    std::copy(numbers.begin(), numbers.begin() + numToCopy, newNumbers.begin());
    numbers = newNumbers;
}
