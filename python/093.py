#
# Problem 93 - Arithmetic expressions
#
import time
import itertools

def do(a, op, b):
    if op == 0:   return a + b
    elif op == 1: return a - b
    elif op == 2: return a * b
    elif op == 3: return -1 if b == 0 else a / b

def combination():
    n = 1234
    while n <= 6789:
        a = n // 1000
        b = (n // 100) % 10
        c = (n // 10) %10
        d = n % 10
        if a < b and b < c and c < d:
            yield [a, b, c, d]
        n += 1

def main():
    max_c = 0
    max_x = 0
    for x in combination():
        result = set()
        for y in itertools.permutations(x):
            for OP0 in range(4):
                for OP1 in range(4):
                    for OP2 in range(4):
                        ab = do(y[0], OP0, y[1])
                        bc = do(y[1], OP1, y[2])
                        cd = do(y[2], OP2, y[3])

                        # a + b + c + d
                        n = do(do(ab, OP1, y[2]), OP2, y[3])
                        if n > 0 and int(n) == n: result.add(int(n))

                        # a + (b + c) + d
                        n = do(do(y[0], OP0,  bc), OP2, y[3])
                        if n > 0 and int(n) == n: result.add(int(n))

                        # a + ((b + c) + d)
                        n = do(y[0], OP0, do(bc, OP2, y[3]))
                        if n > 0 and int(n) == n: result.add(int(n))

                        # a + (b + (c + d))
                        n = do(y[0], OP0, do(y[1], OP1, cd))
                        if n > 0 and int(n) == n: result.add(int(n))

                        # (a + b) + (c + d)
                        n = do(ab, OP1, cd)
                        if n > 0 and int(n) == n: result.add(int(n))


        j = 1
        while j in result: j += 1
        if j >= max_c:
            max_c = j
            max_x = x

    print(max_c)
    print(max_x)

if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
