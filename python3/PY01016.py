cases = int(input())

for _ in range(cases):
    encodedString = input()

    temp = decodedString = ""
    for char in encodedString:
        if not char.isdigit():
            temp += char
            continue

        duplicateTimes = int(char)

        decodedString += temp * duplicateTimes
        temp = ""

    print(decodedString)
