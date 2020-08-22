ns = []
nss = []
ms = []

def bb(elem):
    ini = 0
    fim = len(nss)-1
    while ini <= fim:
        meio = (ini+fim)//2
        num, l = nss[meio]
        if num == elem:
            return meio
        if num < elem:
            ini = meio+1
        else:
            fim = meio-1
    return -1

def multiply_all(pos, v, curr):
    if(pos == len(ns)):
        if(curr != 0):
           nss.append((curr, v.copy())) 
        return
    
    v.append(pos)
    if(curr == 0):
        multiply_all(pos+1, v, ns[pos])
    else:
        multiply_all(pos+1, v, curr*ns[pos])
    v.pop()

    multiply_all(pos+1, v, curr)
    return

def print_ans(p, q):
    print('Y')
    print("{0} {1}".format(len(p), len(q)))

    for i in p:
        print(ns[i], end = ' ')
    print()
    for i in q:
        print(ms[i], end = ' ')

def find_ans(pos, v, curr):
    if(pos == len(ms)):
        if(curr != 0):
            posf = bb(curr)
            if posf != -1:
                num, ans1 = nss[posf]
                ans2 = v.copy()
                print_ans(ans1, ans2)
                return True
        return False

    v.append(pos)
    L = False
    R = False
    if(curr == 0):
        L = find_ans(pos+1, v, ms[pos])
    else:
        L = find_ans(pos+1, v, curr*ms[pos])
    v.pop()

    if L:
        return True

    R = find_ans(pos+1, v, curr)
    return R

def sFunction(e):
    return e[0]

def print_vector(v):
    print(v)

a, b = map(int, input().split())

ns = list(map(int, input().split()))
ms = list(map(int, input().split()))

multiply_all(0, [], 0)
nss.sort(key = sFunction)

if not(find_ans(0, [], 0)):
    print('N')
