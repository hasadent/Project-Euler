/****
 * Problem 4 - Largest palindrome product
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

int is_palindrome(int x)
{
    char buf[12];
    int l;
    int i, j;
    sprintf(buf, "%d", x);
    l = strlen(buf);

    for (i = 0, j = l - 1; i < j; i++, j--)
        if (buf[i] != buf[j])
            return 0;
    return 1;
}

int main()
{
    int i, j, k;
    int max = 0;

    for (i = 999; i >=100; i--)
        for (j = 999; j >=100; j--)
        {
            k = i * j;
            if (is_palindrome(k) && k > max)
            {
                max = k;
            }
        }
        printf("%d\n", max);

    return 0;
}
