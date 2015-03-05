#define ll_uint long long unsigned int

// http://codereview.stackexchange.com/questions/70125/sum-of-digits-in-ab
// Sum digits for a power a^b, works for even much bigger numbers than 2^1000
int powerDigitSum(int a, int b) {
    ll_uint BASE = 1000000000000000000; //  10^18
    ll_uint digits[4000] = { 1 } ;
    int len = 1;

    // compute a ^ b
    while (b-- > 0) {
        ll_uint carry = 0;
        for (int i = 0; i < len; i++) {
            ll_uint temp = digits[i] * a + carry;
            digits[i] = temp % BASE;
            carry = temp / BASE;
        }
        if (carry != 0) {
            digits[len++] = carry;
        }
    }

    // run sum
    int sum = 0;
    for (int i = 0; i < len; i++) {
        ll_uint d = digits[i];
        while (d > 0) {
            sum += d % 10;
            d /= 10;
        }
    }
    return sum;
}

// Power digit sum: What is the sum of the digits of the number 2^1000?
void projectEuler16()
{
    int a = 2, b = 1000;
    int sumOfDigits = powerDigitSum(a, b) ;

    printf("Sum of digits for %d^%d: %d\n", a, b, sumOfDigits);
}

int main()
{
    projectEuler16();

    return 0;
}