n = int(input())  

unique_wishes = set()

for _ in range(n):
    wish = input()
    unique_wishes.add(wish)

print(len(unique_wishes))
