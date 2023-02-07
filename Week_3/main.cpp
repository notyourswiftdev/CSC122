#include <iostream>
#include "list.h"

using namespace std;

int main() {
    try {
        List* l = nullptr;
        l = new List;
        l -> Input();
        l -> Display();
    } catch (const char* s) {
        cerr << s << endl;
    }

    return 0;
}