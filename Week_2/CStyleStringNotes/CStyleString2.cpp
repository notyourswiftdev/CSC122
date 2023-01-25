#include <iostream>
#include <cstring>

using namespace std;

// char pointer called fullName, and the maxLength pass to method.
bool Input(char* fullName, long maxLength);

bool Input(char* fullName, long maxLength) {

  bool returnValue = false; // return true if success passes full name or false if can not.
  char fname[100]; // firstName
  char lname[100]; // lastName

  cout << "First Name: "; // Output first name prompt
  cin >> fname;           // reading first name
  cout << "Last Name: ";  // Output last name prompt
  cin >> lname;           // reading last name

  // getting length of first and last name string and adding them together
  // if it is greater than maxLength it will return returnValue = false.
  if (strlen(fname)+strlen(lname) < maxLength) {
    returnValue = true;
    strcpy(fullName, fname); // strcpy => string copy it will copy the firstname string to fullname
    strcat(fullName, " "); // strcat => string concatenation
    strcat(fullName, lname); // string concatenation on the last name to fullname.
  }
  return returnValue;
}

int main() {

  // declaring a fullName with max size of 200
  char fullName[200];

  // Use the Input method to set fullName.
  if (Input(fullName, sizeof(fullName))) {
    cout << "Full name is: " << fullName << endl;
  }

}