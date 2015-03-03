#include <iostream>
#include <list>
#include <cmath>

using namespace std;

list<unsigned long long> factorize(unsigned long long value) {
    list<unsigned long long> out;
    if(value <= 3) {
        return out;
    }

    for(unsigned long long i = sqrt(value); i > 1; i--)
        if(value % i == 0) // fattore
            out.push_back(i);

    bool modified = true;
    while(modified) {
        modified = false;
        for(list<unsigned long long>::iterator it=out.begin(); it != out.end(); ++it) {
            list<unsigned long long> t = factorize(*it);
            if (!t.empty()) {
                out.remove(*it);
                out.merge(t);
                out.sort();
                out.unique();
                modified = true;
                break;
            }
        }
    }

    return out;
}

int main() {
    list<unsigned long long> fact = factorize(600851475143);

    unsigned long long max = 0;
    for(list<unsigned long long>::iterator it=fact.begin(); it != fact.end(); ++it)
        if(*it > max)
            max = *it;

    cout << "Problem 3 solution " << max << '\n';
    return 0;
}