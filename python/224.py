#
# Problem 224 - Almost right-angled triangles II
#
import time

def solve(start, limit):
    q = [start]

    T0 = [[-2, 1, 2], [-1, 2, 2], [-2, 2, 3]]
    T1 = [[ 2, 1, 2], [ 1, 2, 2], [ 2, 2, 3]]
    T2 = [[ 1,-2, 2], [ 2,-1, 2], [ 2,-2, 3]]

    c = 0
    while len(q) != 0:
        r = []
        c += len(q)
        for n in q:
            if n[0] != n[1]: # T0 == T2 if n[0] == n[1]
                x = [sum(T0[i][j] * n[j] for j in range(3)) for i in range(3)]
                if sum(x) <= limit: r.append(x)

            x = [sum(T1[i][j] * n[j] for j in range(3)) for i in range(3)]
            if sum(x) <= limit: r.append(x)

            x = [sum(T2[i][j] * n[j] for j in range(3)) for i in range(3)]
            if sum(x) <= limit: r.append(x)

        q = r
    return c

def brute_force(limit):
    result = 0
    # c is odd, b is even by observation
    #  =>  c-b is odd and c+b is odd
    #  =>  (c-b)*(c+b) is odd
    #  =>  a^2 = (c-b)*(c+b)-1 is even
    #  =>  a is even
    t_start = time.time()
    for c in range(3, limit // 2 + 1, 2):
        for b in range(c-1, 0, -2):
            x = c - b
            y = c + b
            n = x * y - 1
            a = int(n ** 0.5)
            if a > b or a + y > limit: break
            if (a**2 == n and
                a > x):
                print("a = %d b = %d c = %d" %(a, b,c))
                result += 1


        if c % 100000 == 1:
            t_stop = time.time()
            print("--- %d : %ds" % (750//3 - c // 100000, int(t_stop-t_start)))
            t_start = t_stop

    return result


def main():
    limit  = 75 * (10 ** 6) # 4137330 / 185.5
    #limit  = 50000  # 2777
    print(solve([2,2,3], limit))


if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
