#
# Problem 72 - Counting fractions
#
import time
import factorize
import prime

def totient(n):
    t = n
    f = factorize.factorize(n, p_list)
    for (p, r) in f:
        t = t // p * (p - 1)
    return t


def main():
    # 10^4:     30397485
    # 10^5:   3039650753
    # 10^6: 303963552391
    limit = 1000000
    global p_list
    p_list = prime.prime_generator(limit)
    p_set = set(p_list)

    s = 0
    for i in range(2,limit+1):
        if i in p_set:
            s += (i - 1)
            continue
        t = totient(i)
        s += t
    print(s)


if __name__ == "__main__":
    t_start = time.time()
    #import profile
    #profile.run("main()")
    main()
    t_stop = time.time()
    print(t_stop-t_start)
