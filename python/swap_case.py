#Program to swapcases of a string. In other words,to convert all lowercase letters to uppercase letters and vice versa.
def swap_case(s):
    s = s.swapcase()
    return s

print("Enter String:")
s = input()
result = swap_case(s)
print(result)