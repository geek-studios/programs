#this program finds the minimum and maximum from a list

def minMax(ls):
    maxNum = minNum = ls[0]
    for i in  ls:
        if maxNum <i:
            maxNum  = i
        elif minNum >i:
            minNum = i
    return maxNum,minNum
    
ls = input("ENTER THE ARRAY ").split()
for i in range(len(ls)):
    ls[i] = int(ls[i])

maximum,minimum = minMax(ls)


print("MAXIMUM ",maximum)
print("MINIMUM ",minimum)