def encode_and_reverse(k, s, p):
    encoded = ""
    for char in s:
        encoded_char_index = (p.index(char) + k) % len(p)
        encoded += p[encoded_char_index]
    return encoded[::-1]

if __name__ == "__main__":
    p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
    
    while True:
        Str = input().split()
        if len(Str) > 1:
            k = int(Str[0])
            s = Str[1]
        else:
            break
        
        encoded_string = encode_and_reverse(k, s, p)
        print(encoded_string)
