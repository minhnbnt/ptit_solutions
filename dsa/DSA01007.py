def allBitsString(length):
    bits = []

    def generator():
        if len(bits) == length:
            yield bits
            return

        for bit in [False, True]:
            bits.append(bit)
            yield from generator()

            bits.pop()

    yield from generator()


cases = int(input())
for _ in range(cases):
    size = int(input())

    for bitsStr in allBitsString(size):
        result = ""

        for bits in bitsStr:
            result += "B" if bits else "A"

        print(result, end=" ")

    print()
