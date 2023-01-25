#include <iostream>

using namespace std;

// /// @brief A pointer is a variable whose value is the address of another variable. 
// int main() {

//     int value = 100; // declaring this value of 100
//     int *valuePtr = nullptr; // declaring a pointer
    
//     /// @brief Initial value of "value"
//     /// @return 100 because it is set to 100 above
//     cout << "   value:" << value << endl;

//     /// @brief Initial value of the declaration of valuePtr
//     /// @return 0 because it is set to nullptr above
//     cout << "valuePtr:" << valuePtr << endl;

//     valuePtr = &value; // updating valuePtr to now equal the memory address of value.
//     *valuePtr = 200; // I am getting the memory address of value and updating its value to 200.

//     /// @brief this prints out 100 because the value never changes above
//     /// @return 200
//     cout << "   value:" << value << endl;
    
//     /// @brief This returns the address value of the valuePtr
//     /// @return valuePtr:0x61ff08
//     cout << "valuePtr:" << valuePtr << endl;

//     /// @brief This returns the value of valuePtr
//     /// @return 200
//     cout << "*valuePtr:" << *valuePtr << endl;
// }


// void Swap(int& x, int& y);

// void Swap(int& x, int& y) {
//     int tmp = x;
//     x = y;
//     y = tmp;
// }

// int main() {
//     int a = 5;
//     int b = 3;

//     cout << "Before: " << a << " , " << b << endl;

//     Swap(a,b);

//     cout << "After: " << a << " , " << b << endl;
// }

// void Swap(int* x, int* y);

// void Swap(int* x, int* y) {
//     int tmp = *x;
//     *x = *y;
//     *y = tmp;
// }

// int main() {
//     int a = 5;
//     int b = 3;

//     cout << "Before: " << a << " , " << b << endl;

//     Swap(&a,&b);

//     cout << "After: " << a << " , " << b << endl;

//     return 0;
// }
    