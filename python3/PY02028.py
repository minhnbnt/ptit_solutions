from math import isqrt


def is_prime(n: int) -> bool:
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False

    return n > 1


size = int(input())
array = [int(token) for token in input().split()]

sorted_primes = sorted(
    (element for element in array if is_prime(element)),
    reverse=True,
)

prime_set = set(sorted_primes)

for element in array:
    if element in prime_set:
        element = sorted_primes.pop()

    print(element, end=" ")
