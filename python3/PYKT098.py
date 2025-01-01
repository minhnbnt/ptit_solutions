MAX_INT = 1 << 32 - 1

results = []

with open("DATA.in") as fp:
    tokens = (
        token  #
        for line in fp
        for token in line.split()
    )

    for token in tokens:
        try:
            number = int(token)
        except ValueError:
            results.append(token)
            continue

        if number > MAX_INT:
            results.append(token)

results.sort()

for token in results:
    print(token, end=" ")
