cases = int(input())

for _ in range(cases):
    string = input()
    reversed = string[::-1]

    result = all(
        abs(ord(string[i - 1]) - ord(string[i]))
        == abs(ord(reversed[i - 1]) - ord(reversed[i]))
        for i in range(1, len(string))
    )

    print("YES" if result else "NO")
