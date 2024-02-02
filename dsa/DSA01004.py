from itertools import combinations

cases = int(input())
for _ in range(cases):
    n, k = map(int, input().split())

    for combination in combinations(range(1, n + 1), k):
        print(*combination, sep="", end=" ")

    print()
