from typing import List


def canGreedySorting(array: List[int]) -> bool:

    sortedArray = sorted(array)
    left, right = 0, len(array) - 1

    while left < right:
        arrayPair = {array[left], array[right]}
        sortedPair = {sortedArray[left], sortedArray[right]}

        if arrayPair != sortedPair:
            return False

        left, right = left + 1, right - 1

    return True


cases = int(input())

for _ in range(cases):
    size__ = int(input())
    array = list(map(int, input().split()))

    print("Yes" if canGreedySorting(array) else "No")
