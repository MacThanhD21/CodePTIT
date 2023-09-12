
def count_occurrences(S, N):
    count = 0
    N_str = str(N)
    i = 0

    while i < len(S):
        if S[i:i + len(N)] == N:
            count += 1
            i += len(N)  # Bỏ qua các ký tự đã xét
        else: 
            i += 1

    return count

if __name__ == '__main__':
    T = int(input())

    for _ in range(T):
        S = input()
        N = input()
        
        result = count_occurrences(S, N)
        print(result)
