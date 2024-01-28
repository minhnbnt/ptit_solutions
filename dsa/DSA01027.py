from itertools import permutations

size__ = int(input())

array = sorted(int(token) for token in input().split())

for permutation in permutations(array):
    print(*permutation)
