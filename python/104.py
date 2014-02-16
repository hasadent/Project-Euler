#
# Problem 104 - Pandigital Fibonacci ends
#
import time
import factorize
import prime

def is_pandigital(n):
    s = set()
    while (n > 0):
        m = n % 10
        n //= 10
        if m == 0: return False
        s.add(m)

    for i in range(1,10):
        if not i in s: return False
    return True

def main():

    k = 3
    f1 = 1
    f2 = 1
    f3 = f1 + f2
    while f3 < 10**8:
        f1, f2 = f2, f3
        f3 = f1 + f2
        k += 1

    found = False
    while not found:
        f1, f2 = f2, f3
        f3 = f1 + f2
        k += 1

        n = f3 % 1000000000
        if not is_pandigital(n):
            continue

        n = f3
        while n > 999999999:
            n //= 10
        if not is_pandigital(n):
            continue

        found = True
        print(k)

if __name__ == "__main__":
    t_start = time.time()
    #import profile
    #profile.run("main()")
    main()
    t_stop = time.time()
    print(t_stop-t_start)
