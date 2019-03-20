def star(n): # this draws star
    for i in range(n):
        for _ in range(n-i-1):
            print(" ",end="")
        for _ in range(2*i+1):
            print("*",end="")
        print("")
        
if __name__ == "__main__":
    n = int(input("Enter n:"))
    star(n)