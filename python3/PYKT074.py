cases = int(input())

for _ in range(cases):
    string = input()
    if len(string) < 100:
        print(string)
        continue

    right = 98

    while string[right] != " ":
        right -= 1

    print(string[:right])
