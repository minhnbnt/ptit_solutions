string = input()

numberOfLowerCase = sum(1 for char in string if char.islower())
numberOfUpperCase = len(string) - numberOfLowerCase

needUpperCaseString = numberOfUpperCase > numberOfLowerCase
print(string.upper() if needUpperCaseString else string.lower())
