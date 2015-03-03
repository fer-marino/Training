using namespace std;

bool isPrime(unsigned long long n) {
    for(unsigned long long i = 2; i <= n/2; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    unsigned long long sum = 0;

    for(int i = 2; i < 2000000; i++)
        if(isPrime(i)) {
            sum += i;
        } else if(i % 100000 == 0)
            cout << i << " sum " << sum << '\n';

    cout << "Problem 10 solution is " << sum;

    return 0;
}