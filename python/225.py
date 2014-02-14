#
# Problem 225 - Tribonacci non-divisors
#
import time

def solve(size):
    n = 0
    y = 23
    while n < 124:
        y += 2
        t1 = t2 = t3 = 1
        can_div = False
        for i in range(size):
            t = (t1 + t2 + t3) % y

            if t == 0:
                can_div = True
                break

            t1 = t2
            t2 = t3
            t3 = t

        if not can_div:
            n += 1
    return y

def main():
    print(solve(22711))
    return

if __name__ == "__main__":
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
