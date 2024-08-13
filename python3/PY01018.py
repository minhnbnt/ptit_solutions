import string

ALPHABET = string.ascii_uppercase + "_."

while True:
    tokens = input().split()
    shiftTimes = int(tokens[0])
    if shiftTimes == 0:
        break

    result = ""
    for char in tokens[1]:
        charIndex = ALPHABET.index(char)
        newCharIndex = (charIndex + shiftTimes) % len(ALPHABET)

        result = ALPHABET[newCharIndex] + result

    print(result)
