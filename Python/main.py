import json, math, csv
with open('data.json', 'r') as file:
    data = json.load(file)
print(data)
for key, value in data.items():
    print(key, value)
    if value == 30:
        print(sum(data['grades']) / 3)

# import csv

# with open('data.csv', 'r') as file:
#     data = list(csv.reader(file))
# print(data)

# print(len(data) - 1, len(data[0]) if data else 0)

# import csv

# with open('iris.csv', 'r') as file:
#     data = list(csv.reader(file))
# for _ in range(int(input())):
#     inp = input().split()
#     tong = []
#     for x in data[1:]:
#         if x[2] == inp[1] and x[4] == inp[0]:
#             tong += [float(x[0])]
#     if len(tong) == 0:
#         kq = "Invalid"
#     else:
#         kq = format(sum(tong) / len(tong), ".4f")
#     print(kq)



# with open('iris.csv', 'r') as file:
#     data = list(csv.reader(file))

# for _ in range(int(input())):
#     s = input().split()
    
#     res = []
#     for x in data[1:]:
#         if s[0] == x[4]:
#             if s[1] == 'sepal_length':
#                 res.append(float(x[0]))
#             elif s[1] == 'sepal_width':
#                 res.append(float(x[1]))
#             elif s[1] == 'petal_length':
#                 res.append(float(x[2]))
#             elif s[1] == 'petal_width':
#                 res.append(float(x[3]))
#     if len(res) == 0:
#         print('Invalid')
#     else:
#         if s[2] == 'sum':
#             print(sum(res))
#         elif s[2] == 'min':
#             print(min(res))
#         elif s[2] == 'max':
#             print(max(res))
#         elif s[2] == 'avg':
#             print(sum(res) / len(res))
    

# iris 3

with open('iris.csv', 'r') as file:
    data = list(csv.reader(file))

for _ in range(int(input())):
    species = input()
    s = input().split()
    
    v1, v2 = [], []
    
    for x in data[1:]:
        if species == x[4]:
            if s[0] == data[0][0] and s[1] == data[0][1]:
                v1.append(x[0])
                v2.append(x[1])
            elif s[0] == data[0][0] and s[1] == data[0][2]:
                v1.append(x[0])
                v2.append(x[2])
            elif s[0] == data[0][0] and s[1] == data[0][3]:
                v1.append(x[0])
                v2.append(x[3])
            elif s[0] == data[0][1] and s[1] == data[0][2]:
                v1.append(x[1])
                v2.append(x[2])
            elif s[0] == data[0][1] and s[1] == data[0][3]:
                v1.append(x[1])
                v2.append(x[3])
            elif s[0] == data[0][2] and s[1] == data[0][3]:
                v1.append(x[2])
                v2.append(x[3])
    if len(v1) == 0 or len(v2) == 0:
        print('Invalid')
    else:
        ans = 0
        for x in range(len(v1)):
            ans += float(v1[x]) * float(v2[x])
        print("{:.4f}".format(ans))