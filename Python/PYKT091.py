
# file = open('DATA.txt')
# # print(*file)

# b = {}
# s = 0

# for x in file:
#     a = x.split()
#     # print(*a)
#     for i in a :  
#         if i == i[::-1] :
#             if len(i) > s :
#                 s = len(i)
#                 b.clear()
#                 b[i] = 1
#             elif len(i) == s :
#                 if i not in b : 
#                     b[i] = 1
#                 else : 
#                     b[i] += 1
                    
# for i in b :
#     print(i, b[i])


with open("DATA.txt") as obj:
    s = obj.read().split()

dic = {}
res = ""
max_Len = 0

for x in s:
    if x == x[::-1]:
        if len(x) > max_Len:
            max_Len = len(x)
            dic.clear()
            dic[x] = 1
        elif len(x) == max_Len:
            if x not in dic:
                dic[x] = 1
            else:
                dic[x] += 1

# print(res, dic[res])

for s, fre in dic.items():
    print(s, fre)    
