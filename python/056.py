#
# Problem 56 - Powerful digit sum
#
import time

def sum_digits(n):
    sum = 0
    while n > 0:
        sum += n % 10
        n //= 10
    return sum;

def main():

    result = 0
    for a in range(1, 100):
        for b in range(1, 100):
            s = sum_digits(a**b)
            if s > result:
                result = s
    print(result)


if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
