number = input()

only_6_and_8 = all(digit in ["6", "8"] for digit in number)
result = only_6_and_8 and "888" not in number

print("YES" if result else "NO")
