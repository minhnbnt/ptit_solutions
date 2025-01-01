set1 = set(input().lower().split())
set2 = set(input().lower().split())

print(*sorted(set1 | set2))
print(*sorted(set1 & set2))
