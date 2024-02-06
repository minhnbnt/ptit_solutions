from itertools import combinations

cases = int(input())

for _ in range(cases):
    n, k = map(int, input().split())
    array = [x + 1 for x in range(n)]

    target = tuple(map(int, input().split()))

    for i, permutation in enumerate(combinations(array, k)):
        if permutation == target:
            print(i + 1)
            break
