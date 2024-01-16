size = int(input())

array = [int(token) for token in input().split()]

for i in range(size - 1):
    for j in range(i + 1, size):
        if not array[i] > array[j]:
            continue

        array[i], array[j] = array[j], array[i]

    print(f"Buoc {i + 1}:", *array)
