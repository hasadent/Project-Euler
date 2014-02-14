#
# Problem 221 - Alexandrian Integers
#
#
#  In this problem, upper bound is set as 5*10^6 to guarantee the 150000th
#    Alexandrian integer will be generated, but it is not good enough. To
#    figure out how to set the upper bound is required.
#
import time

def factorize(n):
    factors = []

    ss = n ** 0.5
    for p in p_list:
        if p > ss: break

        i = 0
        while n % p == 0:
            n //= p
            i += 1

        if i > 0:
            factors.append((p, i))

    if n > 1: factors.append((n, 1))

    return factors

def get_divisor(n):
    f = factorize(n)
    div = [1]
    for (p, r) in f:
        div = [d * p**e for d in div for e in range(r + 1)]
    return div

def prime_generator(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

def main():
    limit = 10 ** 5 * 5
    # 150000th is 1884161251122450
    #   1000th is 772168278

    p = 1
    n = 0
    r = set()
    while len(r) < limit:
        pp = p**2

        if (p > max_prime):
            print("need more prime")
            break

        d = get_divisor(pp+1)
        for k in d[len(d)//2:]:
            A = (pp + p*k) * ((pp+1)//k+p)
            r.add(A)
        p += 1
    r = sorted(list(r))
    print(r[1000-1])
    print(r[150000-1])
    pass

max_prime = int(100000000)
p_list = prime_generator(max_prime)
if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
