#
# Problem 47 - Distinct primes factors
#
import itertools

def test(n):
    global p_list

    c = 0
    s = n ** 0.5 + 1
    for p in p_list:
        if n < s:
            break
        if n % p == 0:
            c += 1

    return c == 4

def prime_generator(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

def main():
    global p_list, max_prime

    i = 10
    c = 0
    done = False
    while i < max_prime**2:
        c = 0
        while test(i):
            i += 1
            c += 1

        if c == 4:
            done = True
            break
        elif c == 0:
            i += 1

    if done:
        print("result is %d" % (i - c))




max_prime = 1000
p_list = prime_generator(max_prime)
if __name__ == '__main__':
    main()
