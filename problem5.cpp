#include <iostream>

using namespace std;

int main() {
    for(int i = 10; true; i++) {
        int j;
        for(j = 1; j <= 20; j++)
            if(i % j != 0)
                break;
        if(j > 20) {
            cout << "Problem 5 solution " << i;
            break;
        }
    }

    return 0;
}