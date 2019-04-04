import numpy as np

def f(x):
    return x/(x+1)

temp = 0
for i in range(1,6):
    temp += (2/5)*f((2*i)/5)

print(temp)