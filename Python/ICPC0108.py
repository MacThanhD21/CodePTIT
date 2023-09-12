


if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        a = sorted([int(x) for x in input().split()])
        
        ans = 0
        for i in range(0, len(a) - 2):
            l = i + 1 # chỉ số bắt đầu tìm thằng thứ 3
            r = n - 1 
            
            while l < r:
                if a[i] + a[l] + a[r] == 0:
                    ans += 1
                    l += 1
                elif a[i] + a[l] + a[r] < 0:
                    l += 1
                else:
                    r -= 1
        
        print(ans)