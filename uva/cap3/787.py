lista = []

while(True):
    try:
        n = input()
        l2 = n.split()
        
        for a in l2:
            if int(a) != -999999:
                lista.append(int(a))

         
        prod = lista[0]
        for i in range(len(lista)): 
            subprod = 1
            for j in range(i, len(lista)):
                subprod *= lista[j]
                if subprod > prod:
                    prod = subprod
            
        print(prod)
        del(lista[:])

    except EOFError:
        break
