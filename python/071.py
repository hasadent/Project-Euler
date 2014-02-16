#
# Problem 71 - Ordered fractions

import time
import factorize
import prime

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def faction_cmp(a, b):
    an = a[0] * b[1]
    bn = a[1] * b[0]
    return an - bn


def main():
    limit = 1000000
    global p_list

    x = [3, 7]
    y = [1, 8]

    i = 2

    while i < limit:
        a = x[0] * i - 1
        b = x[1] * i
        g = gcd(a,b)
        a //= g
        b //= g
        n = [a, b]

        if b < limit and faction_cmp(n, y) > 0: # n > y
            y = n
        i += 1

    print(y)



if __name__ == "__main__":
    t_start = time.time()
    #import profile
    #profile.run("main()")
    main()
    t_stop = time.time()
    print(t_stop-t_start)
