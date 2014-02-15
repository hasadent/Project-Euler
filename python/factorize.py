def factorize(n, prime_list):
    factors = []

    ss = n ** 0.5
    for p in prime_list:
        if p > ss: break

        i = 0
        while n % p == 0:
            n //= p
            i += 1

        if i > 0:
            factors.append((p, i))

    if n > 1: factors.append((n, 1))

    return factors
