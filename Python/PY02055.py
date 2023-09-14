
import math

def is_prime(n):
    if n < 2: return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0: return False
    return True

def is_Palindrome(n):
    if(len(str(n)) < 2): 
        return False
    n = str(n)
    rev_n = n[::-1]
    return rev_n == n

if __name__ == '__main__':
    
    N, M = list(map(int, input().split()))
    # matrix = [list(map(int, input().split())) for _ in range(N)]
    matrix = [list(map(int, input().split())) for _ in range(N)]

    max_prime = -1
    # list
    max_prime_positions = []

    for i in range(N):
        for j in range(M):
            if is_Palindrome(matrix[i][j]):
                if matrix[i][j] > max_prime:
                    max_prime = matrix[i][j]
                    # Định nghĩa max_prime_positions là list nhưng chứa các tuple
                    max_prime_positions = [(i, j)]
                    # print(type([(i, j)]))
                elif matrix[i][j] == max_prime:
                    # Vì list mới có append nên add được các tuple khác
                    max_prime_positions.append((i, j))

    if max_prime == -1:
        print("NOT FOUND")
    else:
        print(max_prime)
        for pos in max_prime_positions:
            # print(type(pos))
            print(f"Vi tri [{pos[0]}][{pos[1]}]")
