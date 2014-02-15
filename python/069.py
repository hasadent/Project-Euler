#
# Problem 69 - Totient maximum
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
    max = 1000000
    global p_list
    p_list = prime_generator.prime_generator(int(max**0.5)+1)

    max_n = 0
    max_np = 0.0
    for i in range(2, max+1):
        p = totient(i)
        np = i / p
        if np >= max_np:
            max_n = i
            max_np = np
    print(max_n)

if __name__ == "__main__":
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
