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


size = int(input())

lengthRequired, mod = divmod(size, 2)

for bitsStr in allBitsString(lengthRequired + mod):
    result = ""
    for bits in bitsStr:
        result += "1" if bits else "0"

    for bits in reversed(bitsStr):
        if len(result) == size:
            break

        result += "1" if bits else "0"

    print(*result)
