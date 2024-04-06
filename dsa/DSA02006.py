from typing import Iterator, List


def printArray(array: List[int]) -> None:
    elements = " ".join(map(str, array))
    print(f"[{elements}]", end=" ")


def generate(array: List[int], targetSum: int) -> Iterator[List[int]]:
    array = sorted(array)

    current = []

    def helper(index=0) -> Iterator[List[int]]:
        global currentSum

        if sum(current) == targetSum:
            yield current

        while index < len(array):
            currentNum = array[index]

            current.append(currentNum)
            index += 1

            yield from helper(index)

            current.pop()

    yield from helper()


cases = int(input())
for _ in range(cases):
    size, targetSum = map(int, input().split())

    array = [int(token) for token in input().split()]

    has = False
    for subArray in generate(array, targetSum):
        printArray(subArray)
        has = True

    print("-1" if not has else "")
