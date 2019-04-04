import numpy as np

# var
X = -3

def f(a):
    return 3*np.cos(a) - a - 1

def f_(a):
    return -3*np.sin(a) - 1

def F(a):
    return a-f(a)/f_(a)

def comp(n):
    temp = X
    for _ in range(n-1):
        temp = F(temp)
        print(temp)
    return temp

if __name__ == "__main__":
    for i in range(-10,10):
        X = i
        print(comp(10))