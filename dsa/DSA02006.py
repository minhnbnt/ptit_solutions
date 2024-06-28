from typing import Iterator, List


def allSubArray(array: List[int]) -> Iterator[List[int]]:
    current = []

    def helper(index=0) -> Iterator[List[int]]:
        yield current

        while index < len(array):
            currentNum = array[index]

            current.append(currentNum)
            index += 1

            yield from helper(index)

            current.pop()

    return helper()


cases = int(input())
for _ in range(cases):
    size, targetSum = map(int, input().split())

    array = sorted(int(token) for token in input().split())

    has = False
    results = (
        subArray
        for subArray in allSubArray(array)
        if sum(subArray) == targetSum
    )

    for subArray in results:
        elements = " ".join(map(str, subArray))
        print(f"[{elements}]", end=" ")

        has = True

    print("-1" if not has else "")
