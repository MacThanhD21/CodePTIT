
s1, s2 = "", ""
while True:
    try:
        s1 = set(input().lower().split())
        s2 = set(input().lower().split())
    except EOFError:
        break

union_set = sorted(s1.union(s2))
intersection_set = sorted(s1.intersection(s2))

print(" ".join(union_set))
print(" ".join(intersection_set))
