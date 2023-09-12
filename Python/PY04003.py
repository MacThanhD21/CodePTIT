def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

class Fraction:
    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator

    def simplify(self):
        divisor = gcd(self.numerator, self.denominator)
        self.numerator //= divisor
        self.denominator //= divisor

    def __str__(self):
        return f"{self.numerator}/{self.denominator}"

# Đọc tử số và mẫu số
a, b = map(int, input().split())
PhanSo = Fraction(a, b)
PhanSo.simplify()
print(PhanSo)
