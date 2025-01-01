size_a, size_b = (int(token) for token in input().split())

a_set = {int(token) for token in input().split()}
b_set = {int(token) for token in input().split()}

print(*sorted(a_set & b_set))
print(*sorted(a_set - b_set))
print(*sorted(b_set - a_set))
