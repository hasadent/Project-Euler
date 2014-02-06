/****
 * Problem 19 - Counting Sundays
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

inline bool is_leap_year(int yyyy)
{
    return yyyy % 4 == 0 && yyyy % 100 != 0 || yyyy % 400 == 0;
}

int m_days [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

enum WEEKDAYS {
    SUNDAY    = 0,
    MONDAY    = 1,
    TUESDAY   = 2,
    WEDNESDAY = 3,
    THURSDAY  = 4,
    FRIDAY    = 5,
    SATURDAY  = 6
};

int main()
{
    int day_w = MONDAY;
    int y = 1900;
    m_days[1] = is_leap_year(y) ? 29 : 28;

    /* Get the day of 1901-01-01 */
    for (int m = 0; m < 12; m++)
        day_w += m_days[m];
    day_w %= 7;
    y++;

    int c = 0;
    for (; y < 2001; y++)
    {
        m_days[1] = is_leap_year(y) ? 29 : 28;
        for (int m = 0; m < 12; m++)
        {
            if (day_w == SUNDAY)
            {
                c++;
                cout << y << "-" << setfill('0') << setw(2) << m << "-1 is SUNDAY\n";
            }

            day_w = (day_w + m_days[m]) % 7;
        }
    }

    cout << "There are " << c
        << " Sundays fell on the first of the month during the twentieth century."
        << endl;

    return 0;
}
