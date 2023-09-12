
from itertools import permutations

if __name__ == '__main__':
    s = input()
    
    # Mỗi x trả về 1 tuple
    for x in permutations(s):
        # print(x)
        # print(type(x)) # tuple

        print("".join(x))