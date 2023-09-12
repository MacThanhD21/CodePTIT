
import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

class Fraction:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def simplify(self):
        divisor = gcd(self.a, self.b)
        self.a //= divisor
        self.b //= divisor

    def __add__(self, other):
        new_a = self.a * other.b + other.a * self.b
        new_b = self.b * other.b
        return Fraction(new_a, new_b)

    def __str__(self):
        return f"{self.a}/{self.b}"

if __name__ == '__main__':
    # Đọc tử số và mẫu số của hai phân số p và q
    a_p, b_p, a_q, b_q = map(int, input().split())

    # Tạo đối tượng phân số p và q
    p = Fraction(a_p, b_p)
    q = Fraction(a_q, b_q)

    # Tính tổng p + q và rút gọn
    sum_fraction = p + q
    sum_fraction.simplify()

    # In ra kết quả
    print(sum_fraction)

