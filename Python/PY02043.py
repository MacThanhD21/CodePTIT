
if __name__ == "__main__":
    
    t = int(input())
    for _ in range(t):
        S = input()
        N = input()
        
        print(len(S.split(N)) - 1)
        
        # count = 0
        
        # while N in S:
        #     count += 1
        #     idx = S.index(N)
        #     S = S[:idx] + S[idx + len(N):]
        
        # print(count)
        

