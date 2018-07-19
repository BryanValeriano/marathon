n = input()
l2 = n.split()
x = l2[0]
y = l2[1]

aux1 = pow(int(x),int(y))
aux2 = pow(int(y),int(x))


if(aux1 > aux2):
    print(">")
else:
    print("<")
