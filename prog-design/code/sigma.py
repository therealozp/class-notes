n = int(input("Enter a positive integer n: "))
x = float(input("Enter a positive real number x: "))

def f(term_, i): 
    return term_*x / (i-1)


sum = 0
term = 0
isNegative = False

for i in range(1, 2*n+1):
    if i == 1: 
        term = 1
    else: 
        term = f(term, i)

    if i % 2 == 0: 
        # if the iteration is on the even edge, then multply the term and save it
        continue

    if isNegative: 
        sum -= term
    else: 
        sum += term

    isNegative = not isNegative


print(f'w = {sum}')