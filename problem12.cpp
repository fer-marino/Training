#include <iostream>
#include <list>
#include <ctime>
#include <thread>

using namespace std;

unsigned long long triangleSequence(unsigned int n) {
    unsigned long long out = 0;
    for(int i = 1; i <= n; i++)
        out += i;
    return out;
}

list<unsigned long long> factorize(unsigned long long value) {
    list<unsigned long long> out;

    for(unsigned long long i = value; i >= 1; i--)
        if(value % i == 0) // fattore
            out.push_back(i);

    //out.sort();
    return out;
}

int main() {
    unsigned int i = 9000;
    const int num_threads = 5;
    list<unsigned long long> fact;
    clock_t begin = clock();
    int maxSize = 0;
    while(fact.size() < 5000) {
        i++;
        unsigned long long num = triangleSequence(i);
        //cout << num << ' ';
        fact = factorize(num);
        if(fact.size() > maxSize)
            maxSize = fact.size();
        //for(list<unsigned long long>::const_iterator it = fact.begin(); it != fact.end(); ++it)
          //  cout << *it << ' ';
        //cout << '\n';
        if(i % 500 == 0) {
            clock_t end = clock();
            cout << i << ' ' << (500 / (double(end - begin) / CLOCKS_PER_SEC)) << " eval per sec | max size " << maxSize <<'\n';
            begin = clock();
        }
    }

    cout << "Problem 12 solution is " << (i);
    return 0;
}