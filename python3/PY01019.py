def is_valid(s: str) -> bool:
    reversed = string[::-1]

    for i in range(1, len(string)):
        diff1 = ord(s[i]) - ord(s[i - 1])
        diff2 = ord(reversed[i]) - ord(reversed[i - 1])

        if abs(diff1) != abs(diff2):
            return False

    return True


cases = int(input())

for _ in range(cases):
    string = input()
    print("YES" if is_valid(string) else "NO")
