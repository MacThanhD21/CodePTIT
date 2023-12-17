with open('STRING.in', 'r') as file:
    lines = file.readlines()
num_tests = int(lines[0])

for t in range(1, num_tests * 2, 2):
    s1 = lines[t].strip()
    s2 = lines[t + 1].strip()

    positions = []
    index = -1

    while True:
        index = s1.find(s2, index + 1)
        if index == -1:
            break
        positions.append(index + 1)

    print(*positions)