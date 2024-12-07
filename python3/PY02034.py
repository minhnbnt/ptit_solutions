string = input()
if len(string) % 2 == 1:
    string = string[:-1]

numbers = (  #
    string[i] + string[i + 1]  #
    for i in range(0, len(string), 2)
)

counter = {}
order = []

for number in numbers:
    if number not in counter:
        order.append(number)
        counter[number] = 0

    counter[number] += 1

for number in order:
    print(number, counter[number])
