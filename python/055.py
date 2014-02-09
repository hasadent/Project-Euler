#
# Problem 55 - Lychrel numbers
#

def reverse(n):
    m = 0
    while n > 0:
        m = m * 10 + n % 10
        n = n // 10
    return m

def is_palindrome(n):
    return n == reverse(n)

def is_lychrel(n):
    for i in range(50):
        n += reverse(n)
        if is_palindrome(n):
            return 0
    return 1


def main():
    r = 0
    for i in range(10, 10000):
        if is_lychrel(i):
            r += 1
    print(r)


if __name__ == '__main__':
    main()
