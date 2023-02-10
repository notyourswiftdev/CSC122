#ifndef LIST_H
#define LIST_H

#include <vector>
#include <algorithm>
#include <numeric>

class List {
    private:
        std::vector<double> numbers;
    
    public:
        void addNumber(double num);
        void displayList();
        double calculateAverage();
        double calculateMedian();
        void sortData();
        void resizeList(int newSize);
};

#endif