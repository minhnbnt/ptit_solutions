cases = int(input())

for _ in range(cases):
    string = input()
    buf = []
    sum = 0

    for char in string:
        if char.isdigit():
            sum += ord(char) - ord("0")

        else:
            buf.append(char)

    print(*sorted(buf), sum, sep="")

