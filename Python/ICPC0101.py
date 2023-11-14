
# Author : Mac Van Thanh

def shrink_array(n, A):
    stack = []
    for num in A:
        if len(stack) == 0 or (stack[-1] + num) % 2 != 0:
            stack.append(num)
        else:
            stack.pop()
    return len(stack)

def solve():
    # Đọc input
    n = int(input())
    A = list(map(int, input().split()))

    result = shrink_array(n, A)

    print(result)
    
if __name__ == '__main__':
    solve()
    
