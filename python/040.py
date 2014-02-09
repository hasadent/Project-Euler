#
# Problem 40 - Champernowne's constant
#

b = [0, 9,  99,  999,  9999,  99999,  999999]
s = [0, 9, 189, 2889, 38889, 488889, 5888889]

def get_d(n):

    for x in range(1, 7):
        if n < s[x]:
            break

    # covert n to actual number
    n -= s[x-1]
    o = n // x + b[x-1]

    # get index
    m = n % x

    if m > 0: # m != 0 : the mth digit in the next number
        o += 1
    else :    # m == 0 : the last digit in the current number
        m = x

    # get the digit
    str = "%d" % o

    r = ord(str[m-1]) - ord('0')
    return r


def main():
    r = [1, 10, 100, 1000, 10000, 100000, 1000000]
    result = 1
    for i in r:
        result *= get_d(i)

    print(result)


if __name__ == '__main__':
    main()
