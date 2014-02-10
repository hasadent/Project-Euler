#
# Problem 50 - Consecutive prime sum
#

def prime_generator(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]


def main():
    global p_list
    p_sum = [0]

    for i in range(0, len(p_list)):
        p_sum.append(p_sum[i] + p_list[i])

    n = 0
    for i in range(0, len(p_sum)):
        for j in range(i-n+1, -1, -1):

            # x = sum from i-th prime to j-th prime
            x = p_sum[i] - p_sum[j]

            # if x out of range
            if x > 1000000:
                break

            # if x is a prime number
            if x in p_list:
                n = i - j
                result = x

    print(result)



max_prime = 1000000
p_list = prime_generator(max_prime)
if __name__ == '__main__':
    main()
