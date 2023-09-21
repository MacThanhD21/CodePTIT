# # Đọc nội dung từ tệp DATA.txt
# with open('DATA.txt', 'r') as file:
#     text = file.read()

# # Tách các từ trong văn bản
# words = text.split()

# se = set()

# ans = 0

# for x in words:
# 	ans = max(ans, len(x))
# for x in words:
# 	if len(x) == ans:
# 		if x.endswith(',') or x.endswith('.'):
# 			x = x[:-1]
# 		se.add(x)
# for x in se:
# 	print(x)

# def chuanHoa(s):
# 	se = set()
# 	for x in s:
# 		if x != ' ' and x.isalpha():
# 			se.add(x)

# 	if len(se) == 26:
# 		print("YES")
# 	else:
# 		print("NO")

# chuanHoa(input().lower())

def find_longest_valid_parentheses(s):
    stack = []
    max_length = 0
    start = -1

    st = 0
    en = 0

    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
            st = i
        else:
            if not stack:
                start = i
            else:
                stack.pop()
                if not stack:
                    max_length = max(max_length, i - start)
                else:
                    max_length = max(max_length, i - stack[-1])

    result = ""
    for i in range(st, max_length + 1):
        result += s[i]

    return result

# Test với chuỗi "()(()"
input_str = "((()))"
longest_valid_parentheses = find_longest_valid_parentheses(input_str)
print(longest_valid_parentheses)  # Output: (())


# def find_max_len(s):
# 	stack = []

# with open("DATA.txt") as obj:
# 	s = obj.readlines()

# 	for x in s:
# 		print(find_max_len(x))

# 	print(s)
