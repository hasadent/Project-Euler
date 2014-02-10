#
# Problem 52 - Permuted multiples
#

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

    n = 1
    found = False
    while not found:

        found = True
        for i in range(1, 7):
            if not is_permutation(n, n*i):
                found = False
                break
        n+=1

    print(n-1)


if __name__ == '__main__':
    main()
