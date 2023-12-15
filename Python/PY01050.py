import itertools
def is_valid(s):
    return s.count('A') <= s.count('B') and s.count('B') <= s.count('C')
def is_valid2(s):
    return all(char in s for char in ['A', 'B', 'C'])

N = int(input())

characters = ['A', 'B', 'C']

for length in range(3, N + 1):
    all_strings = itertools.product(characters, repeat=length) # return product obj
    # each string is tuple of characters
    for string in all_strings:
        s = ''.join(string)
        if is_valid(s) and is_valid2(s):
            print(s)
