from itertools import permutations

cases = int(input())
for _ in range(cases):
    length = int(input())

    array = list(range(1, length + 1))
    results = list(permutations(array))

    for result in reversed(results):
        print(*result, sep="", end=" ")

    print()
