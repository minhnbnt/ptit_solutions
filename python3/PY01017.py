def encode_string(s: str) -> str:
    result = ""
    prevChar, dupTimes = "", 0

    for char in s:
        if char == prevChar:
            dupTimes += 1
            continue

        if dupTimes > 0:
            result += f"{dupTimes}{prevChar}"

        prevChar, dupTimes = char, 1

    if dupTimes > 0:
        result += f"{dupTimes}{prevChar}"

    return result


cases = int(input())

for _ in range(cases):
    string = input()
    print(encode_string(string))
