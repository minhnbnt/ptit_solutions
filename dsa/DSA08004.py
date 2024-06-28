from collections import Counter
from heapq import heapify, heappop, heappush


def minimumValue(string: str, removeAttempt: int) -> int:
    charsCounter = Counter(string)

    # default is min-heap, so we use negative
    queue = [-value for value in charsCounter.values()]
    heapify(queue)

    for _ in range(removeAttempt):
        value = heappop(queue)
        heappush(queue, value + 1)

    return sum(value**2 for value in queue)


cases = int(input())
for _ in range(cases):
    removeAttempt = int(input())
    string = input()

    print(minimumValue(string, removeAttempt))
