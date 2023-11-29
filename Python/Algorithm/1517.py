
def pre(x):
    if x == '+' or x == '-':
        return 1
    elif x == '*' or x == '/':
        return 2
    elif x == '^':
        return 3
    else:
        return 0

for _ in range(int(input())):
    s = input()
    st_Operator = []
    st_String = []
    for i in range(len(s)):
        if s[i].isalpha():
            st_String.append(s[i])
        elif s[i] == '(':
            st_Operator.append(s[i])
        elif s[i] == ')':
            while st_Operator != [] and st_Operator[-1] != '(':
                st_String.append(st_Operator.pop())
            st_Operator.pop()
        else:
            while st_Operator != [] and pre(st_Operator[-1]) >= pre(s[i]):
                st_String.append(st_Operator.pop())
            st_Operator.append(s[i])
    while st_Operator != []:
        st_String.append(st_Operator.pop())
    print("".join(st_String))
            
  