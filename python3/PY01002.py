formula = input()

isTrue = eval(formula.replace("=", "=="))
print("YES" if isTrue else "NO")
