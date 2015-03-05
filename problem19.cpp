#include <iostream>

using namespace std;

void increaseDate(int &day, int &month, int &year, int &dayOfWeek) {
    dayOfWeek = (dayOfWeek+1) % 7;
    int dayInMonth = 31;
    if(month == 1) {
        dayInMonth = 28;
        if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            dayInMonth = 29;
    } else if(month == 3 || month == 5 || month == 8 || month == 10)
        dayInMonth = 30;

    if((day + 1) / dayInMonth > 0) {
        if((month + 1) / 12 > 0)
            year++;
        month = (month + 1) % 12;
    }
    day = (day +1) % dayInMonth;
}



int main() {
    int day = 0, month = 0, year = 1900, dayOfWeek=0; // monday
    int res = 0;

    while(!(day == 30 && month == 11 && year == 2000)) {
        // walk
        increaseDate(day, month, year, dayOfWeek);
        if(dayOfWeek == 6 && day == 0 && year >= 1901)
            res++;
    }

    cout << "Problem 19 solution is "<< res;

    return 0;
}