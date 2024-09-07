def is_valid(s: str) -> bool:
    if len(s) % 2 == 0:
        return False

    if s[0] == s[1]:
        return False

    for char in s[::2]:
        if char != s[0]:
            return False

    return True


cases = int(input())

for _ in range(cases):
    s = input()

    if is_valid(s):
        print("YES")
    else:
        print("NO")
