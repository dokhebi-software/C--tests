#include <iostream>
using namespace std;

namespace org::tektutor::application::internals {
        int x;
}

int main ( ) {
        org::tektutor::application::internals::x = 100;
            cout << "\nValue of x is " << org::tektutor::application::internals::x << endl;

                return 0;
}
