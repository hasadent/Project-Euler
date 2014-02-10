#
# Problem 49 - Prime permutations
#

def prime_generator(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

def is_permutation(n, m):
    list = [0] * 10

    while n > 0:
        list[n % 10] += 1
        n //= 10
    while m > 0:
        list[m % 10] -= 1
        m //= 10

    return not [x for x in list if x != 0]

def main():
    global p_list
    p_list = [x for x in p_list if x > 1000]

    for i in range(0, len(p_list)):
        for j in range(i+1, len(p_list)):
            k = p_list[j] * 2 - p_list[i]

            if k > 10000:
                break

            if k in p_list and is_permutation(p_list[i], p_list[j]) and is_permutation(p_list[i], k):
                print("%d%d%d" % (p_list[i], p_list[j], k))
                break

    print("done")



max_prime = 10000
p_list = prime_generator(max_prime)
if __name__ == '__main__':
    main()
