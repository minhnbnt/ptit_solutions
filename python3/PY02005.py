from itertools import combinations

size = int(input())
array = [int(token) for token in input().split()]

result = sum(
    1 if i1 < i2 and e1 > e2 else 0
    for (i1, e1), (i2, e2) in combinations(enumerate(array), r=2)
)

print(result)
