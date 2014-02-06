/****
 * Problem 17 - Number letter counts
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

enum letters {
    ONE       = 3, TWO       = 3, THREE     = 5, FOUR      = 4,
    FIVE      = 4, SIX       = 3, SEVEN     = 5, EIGHT     = 5,
    NINE      = 4, TEN       = 3, ELEVEN    = 6, TWELVE    = 6,
    THIRTEEN  = 8, FOURTEEN  = 8, FIFTEEN   = 7, SIXTEEN   = 7,
    SEVENTEEN = 9, EIGHTEEN  = 8, NINETEEN  = 8, TWENTY    = 6,
    THIRTY    = 6, FORTY     = 5, FIFTY     = 5, SIXTY     = 5,
    SEVENTY   = 7, EIGHTY    = 6, NINETY    = 6, HUNDRED   = 7,
    THOUSAND  = 8, AND       = 3, };

int count_letter(int num)
{
    int m;
    if (num == 1000)
        return ONE + THOUSAND;
    else if (num >= 100)
    {
        int c = count_letter(num/100) + HUNDRED;
        if ((m = num % 100) != 0)
            c += AND + count_letter(m);
        return c;
    }
    else if (num > 20 && (m = num % 10) != 0)
    {
        return count_letter(num - m) + count_letter(m);
    }
    else
    {
        switch (num)
        {
        case 1: return ONE;
        case 2: return TWO;
        case 3: return THREE;
        case 4: return FOUR;
        case 5: return FIVE;
        case 6: return SIX;
        case 7: return SEVEN;
        case 8: return EIGHT;
        case 9: return NINE;
        case 10: return TEN;
        case 11: return ELEVEN;
        case 12: return TWELVE;
        case 13: return THIRTEEN;
        case 14: return FOURTEEN;
        case 15: return FIFTEEN;
        case 16: return SIXTEEN;
        case 17: return SEVENTEEN;
        case 18: return EIGHTEEN;
        case 19: return NINETEEN;
        case 20: return TWENTY;
        case 30: return THIRTY;
        case 40: return FORTY;
        case 50: return FIFTY;
        case 60: return SIXTY;
        case 70: return SEVENTY;
        case 80: return EIGHTY;
        case 90: return NINETY;
        default:
            cout << "unknown num" << endl;
            break;
        }
    }
    return 0;
}

int main()
{
    int sum  = 0;
    for (int i = 1; i <= 1000; i++)
        sum += count_letter(i);

    cout << sum << " letters would be used." << endl;

    return 0;
}
