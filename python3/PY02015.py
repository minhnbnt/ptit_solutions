while True:
    array = [int(token) for token in input().split()]

    if all(elem == 0 for elem in array):
        break

    counter = 0
    while len(set(array)) > 1:
        new_array = array.copy()

        for i in range(len(array) - 1):
            new_array[i] = abs(array[i] - array[i + 1])

        new_array[-1] = abs(array[-1] - array[0])

        array = new_array

        counter += 1

    print(counter)
