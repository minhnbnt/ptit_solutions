import sys

stack = list()

for line in sys.stdin:
    command = line.split()

    if command[0] == "push":
        stack.append(command[1])
    elif command[0] == "pop":
        stack.pop()
    elif command[0] == "show":
        if len(stack) == 0:
            print("empty")
        else:
            print(*stack)
