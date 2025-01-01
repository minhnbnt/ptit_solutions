size = int(input())
bits = [int(token) for token in input().split()]

result = sum(
    1  #
    for i in range(1, len(bits))
    if bits[i] != bits[i - 1]
)

print(result)
