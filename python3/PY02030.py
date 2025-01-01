from math import isqrt
from typing import Iterable, List


def is_prime(n: int) -> bool:
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            return False

    return n > 1


def distinct(seq: Iterable) -> List:
    visited, result = set(), list()

    for element in seq:
        if element not in visited:
            result.append(element)
            visited.add(element)

    return result


size = int(input())
array = [int(token) for token in input().split()]

array: List[int] = distinct(array)

left, right, result = 0, sum(array), None
for i, element in enumerate(array):
    left, right = left + element, right - element

    if is_prime(left) and is_prime(right):
        result = i
        break

if result is None:
    print("NOT FOUND")

else:
    print(result)
