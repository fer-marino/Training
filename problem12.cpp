#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

struct threadParams{
    int param1;
    int param2;
};

static DWORD WINAPI compute(void* threadParams){
    struct threadParams* params = (struct threadParams*)threadParams;

    unsigned long long num = params->param1;

    for(unsigned long long i = num; i < num+500; i++) {

        // triangle of i
        unsigned int count = 0;
        unsigned long long num = 0;
        for (int j = 1; j <= i; j++)
            num += j;

        // count divisors of num
        count = 2;
        for (unsigned long long j = num / 2 + 1; j > 1; j--)
            if (num % j == 0) // factor
                count++;

        if (count >= 500)
            cout << "solution found " << i;
    }
}

int main() {


    unsigned int i = 10000;
    clock_t begin = clock();
    unsigned int maxSize = 0;
    while(i < 13000) {
        DWORD threadDescriptor;
        struct threadParams params1 = {1, 2};

        CreateThread(
                NULL,                   /* default security attributes.   */
                0,                      /* use default stack size.        */
                compute,          /* thread function name.          */
                (void*)&params1,        /* argument to thread function.   */
                0,                      /* use default creation flags.    */
                &threadDescriptor);     /* returns the thread identifier. */

        i+=500;

        if(i % 100 == 0) {
            clock_t end = clock();
            cout << i << ' ' << (100 / (double(end - begin) / CLOCKS_PER_SEC)) << " eval per sec | max size " << maxSize <<'\n';
            begin = clock();
        }
    }

    cout << "Problem 12 solution is " << (i) << " with " << maxSize;
    return 0;
}