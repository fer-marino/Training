using namespace std;

unsigned int collatz(unsigned int n) {
    if(n%2 == 0)
        return n/2;
    else
        return 3*n +1;
}

unsigned int countCollatz(unsigned int start) {
    unsigned int count = 1;
    while(start != 1) {
        //cout << start << ' ';
        start = collatz(start);
        count++;
    }
    return count;
}

int main() {
    unsigned int maxCount = 0;
    unsigned int maxNum = 0;
    for(unsigned int start = 999999; start > 1; start--) {
        unsigned int count = countCollatz(start);
        if(count > maxCount) {
            maxCount = count;
            maxNum = start;
        }
    }
    cout << "Problem 14 solution is " << maxNum;
    return 0;
}