
# import itertools

# # characters = ['A', 'B', 'C']

# # all_strings = itertools.product(characters, repeat=2)

# # for str in all_strings:
# #     print(''.join(str))


# dic = {1: 2, 2: 1, 3: 1, 4: 5, 5: 6}

# # Convert dictionary items to a list of tuples and sort by keys
# sorted_items = sorted(dic.items(), key=lambda x: x[-1], reverse=True)

# # Convert the sorted list back to a dictionary
# sorted_dic = dict(sorted_items)

# for key, value in sorted_dic.items():
#     print('{} ==> {}'.format(key, value))
    

# s = "Mac Van Thanh"
# substring = "Mac"

# # Find the index of the first occurrence of 'Mac' in the string
# index = s.find(substring)

# # Check if the substring was found
# if index != -1:
#     print(f"'{substring}' found at index {index}")
# else:
#     print(f"'{substring}' not found in the string")


# with open('file_a.txt') as file_obj1:
#     with open('file_b.txt') as file_obj2:
#         lineA, lineB = file_obj1.readline(), file_obj2.readline()
#         for x, y in zip(lineA, lineB):
#             try:
#                 print(int(x)**int(y))
#             except:
#                 print("Lỗi định dạng")


            
    