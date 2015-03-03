#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isPalindrome(int n) {

    string t;
    stringstream convert;
    convert << n;
    t = convert.str();
    for (unsigned i=0; i<t.length(); i++)
        if(t.at(i) != t.at(t.length() - i -1))
            return false;

    return true;
}

int main() {
    unsigned int max = 0;
    for(int i = 1; i < 1000; i++)
        for(int j = 1; j < 1000; j++) {
            int t = i * j;
            if(isPalindrome(t) && t > max)
                max = t;
        }

    cout << "Problem 4  solution " << max ;

    return 0;
}