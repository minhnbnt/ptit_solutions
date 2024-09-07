from collections import Counter
from math import isqrt


def is_prime(n: int) -> bool:
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False

    return n > 1


size = int(input())

numbers = [int(token) for token in input().split()]
primes = Counter(number for number in numbers if is_prime(number))

visited = set()
for number in numbers:
    if number in visited:
        continue

    count = primes.get(number)
    if count is None:
        continue

    print(f"{number} {count}")
    visited.add(number)
