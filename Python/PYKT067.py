def generate_permutations(n, a, visited):
    def ou():
        for i in range(1, n + 1):
            print(a[i], end='')
        print(" ", end='')

    def back(i):
        for j in range(n, 0, -1):
            if not visited[j]:
                a[i] = j
                visited[j] = True
                if i == n:
                    ou()
                else:
                    back(i + 1)
                visited[j] = False

    count = [0]  # Initialize a list to store the count

    def count_permutations(i):
        if i > n:
            count[0] += 1
        else:
            for j in range(1, n + 1):
                if not visited[j]:
                    visited[j] = True
                    count_permutations(i + 1)
                    visited[j] = False

    count_permutations(1)
    print(count[0])  # Print the length of permutations
    back(1)

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [0] * 100
        visited = [False] * 100
        generate_permutations(n, a, visited)
        print()

if __name__ == "__main__":
    main()
