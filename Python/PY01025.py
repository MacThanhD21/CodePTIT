import re

def format_with_commas(n):
    num_str = str(n)
    
    formatted_str = re.sub(r'(\d)(?=(\d{3})+(?!\d))', r'\1,', num_str)
    
    return formatted_str

N = int(input())

formatted_number = format_with_commas(N)
print(formatted_number)
