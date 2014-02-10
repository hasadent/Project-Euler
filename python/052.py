#
# Problem 52 - Permuted multiples
#
import time

def is_permutation(n, m):
    list = [0] * 10

    while n > 0:
        list[n % 10] += 1
        n //= 10
    while m > 0:
        list[m % 10] -= 1
        m //= 10

    return not [x for x in list if x != 0]

def main():

    found = False
    start = 1
    result = -1
    while not found:
        start *= 10

        for n in range(start//10, start//6+1):
            found = True
            for i in range(1, 7):
                if not is_permutation(n, n*i):
                    found = False
                    result = n
                    break

            if found:
                break

    print(result)


if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_stop)
