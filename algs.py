import random

def is_sorted(L) :
    return all(L[i] <= L[i+1] for i in range(len(L)-1))

def bogo(L) :
    while not is_sorted(L) :
        random.shuffle(L)
    return L

##################################
    
def LV(x, y) :
    y = x
    random.shuffle(y)
    return is_sorted(y)

def repetirLV(x) :
    y = x
    exito = False
    while not exito :
        exito = LV(x, y)
    return y
    
##################################

from itertools import permutations

def bad(L) :
    P = permutations(L)
    for X in P :
        if is_sorted(X) :
            return X
    return

def worse(L) :
    P = list(permutations(L))
    for X in P :
        if is_sorted(X) :
            return X
    return

def multi(L, N) :
    if N == 0 :
        return sorted(L)
    P = list(permutations(L))
    P = multi(P, N-1)
    return P[0]

def cota(L) :
    return 2

def worst(L) :
    return multi(L, cota(len(L)))

##################################

def slowrec(L, i, j) :
        if i >= j :
            return
        m = (i+j) // 2 
        slowrec(L, i, m)
        slowrec(L, m + 1, j)
        if L[j] < L[m] :
            L[j], L[m] = L[m], L[j]
        slowrec(L, i, j-1)
        return L
    
def slow(L) :
    return slowrec(L,0,len(L)-1)