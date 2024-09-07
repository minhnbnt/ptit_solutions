from math import isqrt


def is_prime(n: int) -> bool:
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False

    return n > 1


row, col = map(int, input().split())

result = []

for _ in range(row):
    numbers = map(int, input().split())
    result.append(map(is_prime, numbers))


for iter in result:
    display = map(int, iter)
    print(*display)
