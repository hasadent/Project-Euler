#
# Problem 53 - Combinatoric selections
#
import time

def main():
    f = [1]
    for i in range(1, 101):
        f.append(f[i-1]*i)

    result = 0
    for n in range(1, 101):
        for r in range(0, n+1):
            x = f[n] // (f[r] * f[n-r])
            if x >= 1000000:
                result+= 1
    print(result)


if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
