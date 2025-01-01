from math import isqrt
from itertools import count


def is_prime(n: int) -> bool:
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False

    return n > 1


primes = (n for n in count() if is_prime(n))

n, x = (int(token) for token in input().split())

print(x, end=" ")

for _ in range(n):
    x += next(primes)
    print(x, end=" ")
