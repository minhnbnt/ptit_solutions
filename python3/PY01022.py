number = input()

counter = 0

while len(number) > 1:
    sum_of_digits = sum(ord(digit) - ord("0") for digit in number)
    number = str(sum_of_digits)

    counter += 1

print(counter)
