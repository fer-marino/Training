#include <iostream>

using namespace std;

int main() {
    for(int a = 1; a < 1000; a++)
        for(int b = a+1; b < 1000; b++) {
            int c = 1000 - a - b;
            if(a*a + b*b == c*c) {
                cout << "Problem 9 solution is " << (a*b*c);
                return 0;
            }
        }

    cout << "no solution found";
    return 0;
}