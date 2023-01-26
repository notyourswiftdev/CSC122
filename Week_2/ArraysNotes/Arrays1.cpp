#include <iostream>

using namespace std;

int main() {

    // Different way's to delcare arrays.
    int list1[50];
    int list2[] = {10,20,30,40,50};
    int list3[5] = {60,70,80,90,100};

    // For loop to iterate over list2 array and print each one out up to index 5.
    for (int i = 0; i < 5; i++) {
        cout << list2[i] << " ";
    }

    cout << endl;

    return 0;
}