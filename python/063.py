#
# Problem 63 - Powerful digit counts
#
import time
import factorize
import prime

def num_len(n):
    l = 0
    while n > 0:
        n //= 10
        l += 1
    return l

def main():
    # For all postive p of 10^p, L(10^p) is always greater than p.
    #  so the result in number 1 ~ 9
    c = 0
    for n in range(1, 10):
        p = 1
        has_result = False
        while True:
            pp = n ** p
            l = num_len(pp)

            if l == p:
                c += 1
                has_result = True
                print("%d^%d" %(n, p))

            if l < p:
                break
            p += 1

    print(c)


if __name__ == "__main__":
    t_start = time.time()
    #import profile
    #profile.run("main()")
    main()
    t_stop = time.time()
    print(t_stop-t_start)
