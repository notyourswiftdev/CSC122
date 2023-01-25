#include <iostream>

using namespace std;

int main() {
    /*
        Define a native string in char array.
        Max size is 200 (199) characters.
        The reason 199 instead of 200 is cause
        the null character at the end of the string.
    */
    char message[200];
    
    // Prompting user to enter a string.
    cout << "Enter a string: ";

    // User enters there string.
    cin >> message;
    
    /// @brief The string that is passed in.
    /// @return Returns the message that user inputs.
    cout << "You entered: " << message << endl;

    return 0;
}

