#
# Problem 43 - Sub-string divisibility
#
import itertools

def main():

    prime = [2,3,5,7,11,13,17]
    result = 0
    for i in itertools.permutations([0,1,2,3,4,5,6,7,8,9]):
        if i[0] != 0:
            found = 1
            for j in range(0,7):
                if (i[j+1] * 100 + i[j+2] * 10 + i[j+3]) % prime[j] != 0:
                    found = 0
                    break

            if found == 1:
                for j in range(0,10):
                    result += i[j] * (10**(9-j))

    print(result)


if __name__ == '__main__':
    main()
