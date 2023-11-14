

for _ in range(int(input())):
    s = input()
    stack = []
    stt = 1
    for i in s:
        if i == '(':
            stack.append(stt)
            print(stt, end=' ')
            stt += 1
        elif i == ')':
            print(stack.pop(), end=' ')
    print()