from itertools import combinations

_, name_length = (int(token) for token in input().split())

tokens = sorted(set(input().split()))

for name in combinations(tokens, r=name_length):
    print(*name)
