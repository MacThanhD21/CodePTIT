

import math

if __name__ == '__main__':
    t = 1
    # t = int(input())
    for _ in range(t):
        s = input()
        
        result_list = []
        
        fre = {}
        
        for i in range(0, len(s), 2):
            two_digit_number = s[i:i+2]
            if len(two_digit_number) < 2:
                break
            result_list.append(int(two_digit_number))

        result_list.sort()
        
        for x in result_list:
            if x in fre:
                fre[x] += 1
            else:
                fre[x] = 1
        ok = False
        for key, val in fre.items():
            print(key, end = " ")

