set1 = set(input().lower().split())
set2 = set(input().lower().split())

print(*sorted(set1.union(set2)))
print(*sorted(set1.intersection(set2)))
