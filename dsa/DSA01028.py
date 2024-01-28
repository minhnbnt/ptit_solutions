from itertools import combinations

_, size = (int(token) for token in input().split())

array = set(int(token) for token in input().split())
for combination in combinations(sorted(array), size):
    print(*combination)
