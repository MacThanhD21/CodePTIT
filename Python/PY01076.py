import math

def find_gcd(a, b):
    return math.gcd(a, b)

def main():
    T = int(input())
    for _ in range(T):
        gcd = find_gcd(int(input()), int(input()))
        print(gcd)

if __name__ == "__main__":
    main()
