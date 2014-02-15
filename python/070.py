#
# Problem 70 - Totient maximum
#
import time
import prime

def get_semi_prime(n):
    factors = []

    ss = n ** 0.5
    l = 0
    for p in p_list:
        if p > ss: break

        if  n % p == 0:
            p2 = n // p
            if p2 in p_set:
                return [p, p2]
            break

    return []

def is_permutation(n, m):
    list = [0] * 10

    i = 0
    while n > 0:
        list[n % 10] += 1
        n //= 10
        i += 1
    while m > 0 and i > 0:
        list[m % 10] -= 1
        m //= 10
        i -= 1

    if i != 0 or m != 0: return False

    for x in list:
        if x != 0: return False
    return True


def main():
    max = 10**7 # 10^6 :: 783169
    global p_list, p_set
    p_list = prime.prime_generator(int(max//2)+1)
    p_set = set(p_list)

    min_n = 0
    min_np = 1000000.0

    for i in range(1, max+1, 2):
        f = get_semi_prime(i)
        if len(f) == 0: continue

        p = i // f[0] * (f[0] - 1) // f[1] * (f[1] - 1)
        if  is_permutation(i, p):
            np = float(i) / p
            if np <= min_np:
                min_n = i
                min_np = np
    print(min_n)

if __name__ == "__main__":
    t_start = time.time()
    #import profile
    #profile.run("main()")
    main()
    t_stop = time.time()
    print(t_stop-t_start)
