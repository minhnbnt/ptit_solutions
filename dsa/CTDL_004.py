from typing import Iterator, List


def generate(array: List[int], rank: int) -> Iterator[List[int]]:
    subArray = []

    def helper(index=0) -> Iterator[List[int]]:
        if len(subArray) == rank:
            yield subArray

        while index < len(array):
            current = array[index]
            index += 1

            if len(subArray) > 0 and current < subArray[-1]:
                continue

            subArray.append(current)

            yield from helper(index)

            subArray.pop()

    yield from helper()


size, rank = map(int, input().split())
array = [int(token) for token in input().split()]

result = 0
for _ in generate(array, rank):
    result += 1

print(result)
