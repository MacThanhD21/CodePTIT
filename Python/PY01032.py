def main():
    a, b, k = [int(x) for x in input().split()]
    TH = 0
    if a == 0 and b > 1:
        if a == 0:
            TH = 2
        elif a == 1:
            TH = 1
        a = 2
    val = [x for x in range(a, b+1) if check_bin(x)]
    for i in range(3, k+1):
        val = [x for x in val if check(x, i)]
        if len(val) == 0:
            break
    print(len(val)+TH)
def check(n, k):
    ans = ""
    while n > 0:
        ans += str(n % k)
        n //= k
    return ans == ans[::-1]
def check_bin(n):
    n = bin(n)[2:]
    return n == n[::-1]
main()