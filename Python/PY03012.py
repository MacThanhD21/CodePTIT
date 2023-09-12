

from functools import cmp_to_key

class SV :
    def __init__(self, name, ac, submit):
        self.name = name
        self.ac = ac
        self.submit = submit
        
    def __str__(self) :
        return f'{self.name} {self.ac} {self.submit}' 

def cmp(a, b) :
    if a.ac < b.ac :
        return 1
    elif a.ac == b.ac :
        if a.submit > b.submit :
            return 1
        elif a.submit == b.submit :
            if a.name > b.name :
                return 1
            else:
                return -1
        else:
            return -1
    else:
        return -1

if __name__ == "__main__":

    n = int(input())
    a = []
    for i in range(n) :
        name = input()
        ac, submit = [int(x) for x in input().split()]
        a.append(SV(name, ac, submit))
        
    a = sorted(a, key = cmp_to_key(cmp))
    for SV in a :
        print(SV)
