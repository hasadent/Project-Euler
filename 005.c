/****
 * Problem 5 - Smallest multiple
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, j, k;
    int max = 0;

    int value[19], *p = value;
    
    /* set value from 2 to 19 */
    for (i = 2; i <= 20;  i++ )
        *p++ = i;

    /* remove common divisor */
    for (i = 1; i < 19; i++)
        for (j = 0; j < i; j++)
            if (value[j] != 1 && value[i] % value[j] == 0)
                value[i] /= value[j];

    /* get answer */
    k = 1;
    for (i = 0; i < 19; i++)
        k *= value[i];

    printf("%d\n", k);

    return 0;
}
