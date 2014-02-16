#
# Problem 73 - Counting fractions in a range

import time
import factorize
import prime

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def main():
    # 7295372
    limit = 12000

    i = 1
    r = set()
    while i <= (limit):
        d  = 6 * i
        lb = 2 * i + 1
        ub = 3 * i
        for j in range(lb, ub):
            g = gcd(d, j)
            b = d // g
            if  b <= limit:
                a = j // g
                s = (a, b)
                r.add(s)
        i += 1
    print(len(r))


if __name__ == "__main__":
    t_start = time.time()
    #import profile
    #profile.run("main()")
    main()
    t_stop = time.time()
    print(t_stop-t_start)
