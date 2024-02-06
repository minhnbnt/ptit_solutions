from itertools import permutations

cases = int(input())

for _ in range(cases):
    size = int(input())
    array = [x + 1 for x in range(size)]

    target = tuple(map(int, input().split()))

    for i, permutation in enumerate(permutations(array)):
        if permutation == target:
            print(i + 1)
            break
