/****
 * Problem 2 - Even Fibonacci numbers
 */
int main()
{
    int f0 = 1, f1 = 1;
    int t;

    int sum = 0;
    while (f1 < 4000000)
    {
        t = f0 + f1;
        f0 = f1;
        f1 = t;

        if ((f1 & 1) == 0)
            sum += f1;
        printf("%d %d\n", f1, sum);

    }
    printf("%d\n", sum);

    return 0;
}
