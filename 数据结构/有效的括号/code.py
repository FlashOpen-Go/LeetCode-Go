def isValid(s):
    stack = []
    for c in s:
        if c == '{' or c == '[' or c == '(':
            stack.append(c)
        elif c == '}':
            if len(stack) != 0 and stack[-1] == '{':
                stack.pop()
            else:
                return False
        elif c == ']':
            if len(stack) != 0 and stack[-1] == '[':
                stack.pop()
            else:
                return False
        elif c == ')':
            if len(stack) != 0 and stack[-1] == '(':
                stack.pop()
            else:
                return False

    return stack == []


print(isValid("[]"))