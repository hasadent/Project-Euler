#
# Problem 223 - Almost right-angled triangles I
#
import time

def divisor_generator(n):
    divisor = set()
    divisor.add(1)
    #divisor.add(n)

    s = int(n ** 0.5)
    for i in range(1, s+1):
        if n % i == 0:
            divisor.add(i)
    return divisor

def main():
    #limit =       25 # 14
    #limit =      100 # 72
    #limit =      250 # 124+??
    #limit =    10000 # 13656
    limit =  2500000 # 5352755
    #limit = 25000000 # ??
    result = 0

    for L in range(3, limit+1, 2):
        n = (L ** 2 - 1) // 2
        dv = divisor_generator(n)
        dv = sorted(list(dv), reverse=True)

        #dv = [x for x in dv if x <= n ** 0.5]

        #print("-- %d -- k = %d" % (L, k))
        #print(dv)
        L2 = L * 2
        L3 = L * 3
        for i in dv:
            d1 = i
            d2 = n // i
            if L3 <= (d1 + d2) * 2:
                break
            if d1 * 2 + d2 >= L2:
                result += 1
                #print("%d %d " % (d1, d2))

    print(result)


if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
