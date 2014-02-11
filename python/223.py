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
            divisor.add(n/i)
    return divisor

def get_divisor(n):
    global p_list

    if n < d_size:
        return d_list[int(n)]

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
    #limit =  2500000 # 5352755 (245s)
    limit = 25000000 # 61614848 (3324s)
    result = 0

    dv1 = get_divisor(1) # k = 1
    for L in range(3, limit+1, 2):
        n = (L ** 2 - 1) // 2
        k = (L - 1) / 2

        dv2 = dv1
        dv1 = get_divisor(k+1)
        print

        dv = set()
        for i in dv1:
            for j in dv2:
                dv.add(i*j)
                dv.add(i*j*2)
        dv = [x for x in dv if x <= n ** 0.5]
        #
        #print("-- %d -- k = %d" % (L, k))
        #print(dv)

        L2 = L * 2
        L3 = L * 3
        for i in dv:
            d1 = i
            d2 = n // i
            if L3 > (d1 + d2) * 2 and d1 * 2 + d2 >= L2:
                result += 1
               # print("%d %d " % (d1, d2))
        if L % 10000 == 1:
            print("--- %d" % (L-1))

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
