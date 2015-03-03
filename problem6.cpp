#include <iostream>

using namespace std;

int main() {
    unsigned long long sqsum = 0;
    unsigned long long sumsq = 0;

    for(int i = 1; i <= 100; i++) {
        sqsum += i * i;
        sumsq += i;
    }

    sumsq = sumsq * sumsq;

    cout << "Problem 6 solution " << (sumsq - sqsum);


    return 0;
}