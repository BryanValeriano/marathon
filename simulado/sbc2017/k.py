import math

def main():
    row = input()    
    roww = row.split(' ')
    b = []
    print(roww)
    for a in roww:
       b.append(float(a)) 
    x = b[0] + math.sqrt(b[1])
    print(b[2])
    y = x**100
    print(y)


if __name__ == "__main__":
    main()

