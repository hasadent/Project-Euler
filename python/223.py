#
# Problem 223 - Almost right-angled triangles I
#
import time

d_list = [[]]
d_size = 5001

def init_dg():
    global d_list
    for i in range(1, d_size):
        d_list.append(divisor_generator(i))

def divisor_generator(n):
    divisor = set()
    divisor.add(1)
    divisor.add(n)

    s = int(n ** 0.5)
    for i in range(1, s+1):
        if n % i == 0:
            divisor.add(i)
            divisor.add(n//i)
    return divisor

def get_divisor(n):
    if n < d_size:
        return d_list[n]

    if n in p_set:
        return set([1, n])

    for i in range(2, d_size):
        if (n % i == 0):
            dv1 = get_divisor(i)
            dv2 = get_divisor(n//i)

            dv = set()
            for i in dv1:
                for j in dv2:
                    dv.add(i*j)
            return dv

    print("--- ?? %d" % (n))
    return [1, n]

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

        dv = set()
        for i in dv1:
            for j in dv3:
                dv.add(i*j)

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


max_prime = 25000000
p_list = prime_generator(max_prime)
p_set = set(p_list)
init_dg()

if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
