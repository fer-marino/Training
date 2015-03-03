#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    for(long long i = 2; i <= n/2; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    unsigned long long sum = 0;

    for(int i = 2; i < 2000000; i++)
        if(isPrime(i))
            sum += i;

    cout << "Problem 10 solution is " << sum;

    return 0;
}