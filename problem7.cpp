#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    for(long long i = 2; i < n /2; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    int count = 0;
    unsigned long long n = 2;
    unsigned long long last = 1;
    while(count <= 10001) {
        if(isPrime(n)) {
            count++;
            last = n;
        }
        n++;
    }


    cout << "Problem 7 solution is " << last;

    return 0;
}