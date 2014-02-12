#
# Problem 223 - Almost right-angled triangles I
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
            factors.append((p, i));

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
    #limit =       25 # 14
    #limit =      100 # 72
    #limit =      250 # 212
    #limit =    10000 # 13656
    #limit =    50000 # 79633
    limit =  2500000 # 5352755
    #limit = 25000000 # 61614848  (989s)
    result = (limit - 1) // 2
    upper  = int((limit + 1) / (2 + 2 ** 0.5))

    dv2 = {1}   # a = 1
    dv3 = {1, 2} # a = 2
    for a in range(2, upper+1):
        dv1 = dv2 # a - 1
        dv2 = dv3 # a
        dv3 = get_divisor(a+1)

        dv = {d1*d2 for d1 in dv1 for d2 in dv3}
        dv = [x for x in dv if x <= a]

        aa = a ** 2 - 1
        for x in dv:    # x = c - b
            y = aa // x # y = c + b

            if (x + y) % 2 != 0:
                continue

            c = (x + y) // 2
            b = y - c

            if a <= b and b <= c and (a+b+c) <= limit:
                result += 1

        if a % 10000 == 1:
            print("--- %d" % (a-1))

    print(result)


max_prime = int(25000000**0.5+1)
p_list = prime_generator(max_prime)

if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
