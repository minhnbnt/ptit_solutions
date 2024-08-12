import re

isNumber = re.compile("[0-9]+")

cases = int(input())
for _ in range(cases):
    inputString = input()
    numbersExtracted = (int(subStr) for subStr in isNumber.findall(inputString))

    print(min(numbersExtracted))
