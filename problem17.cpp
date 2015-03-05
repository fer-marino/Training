using namespace std;

string toWords(int num) {
    if (num > 1000 || num < 1) {
        throw "unsupported";
    }
    if (num == 100) {
        return "one hundred";
    }
    if(num == 1000)
        return "one thousand";

    const string kSpecialCases[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    if (10 <= num && num <= 19) {
        return kSpecialCases[num - 10];
    }

    const string kOnesPlaces[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const string kTensPlaces[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    if (num < 10) {
        return kOnesPlaces[num - 1];
    } else if (num < 100) {
        if(num % 10 == 0) {
            return kTensPlaces[num / 10 - 2];
        } else {
            return kTensPlaces[num / 10 - 2] + " " + kOnesPlaces[num % 10 - 1];
        }
    } else {
        if(num % 100 == 0) {
            return kOnesPlaces[num / 100 -1] + " hundred";
        } else if(num % 10 == 0) {
            return kOnesPlaces[num / 100 -1] + " hundred and " + toWords(num % 100);
        } else {
            return kOnesPlaces[num / 100 -1] + " hundred and " + toWords(num % 100);
        }
    }
}

unsigned int letterCount(string s) {
    unsigned int out = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] != ' ')
            out++;
    return out;
}

int main() {
    int count = 0;
    for(int i = 1; i <=1000; i++)
        count += letterCount( toWords(i) );
    cout << "Problem 17 solution is "<< count;
    return 0;
}