import random
from itertools import permutations

def is_sorted(l) :
    return all(l[i] <= l[i+1] for i in range(len(l)-1))

def bogo(V) :
    while not is_sorted(V) :
        random.shuffle(V)
    return V

def bad(V) :
    P = permutations(V)
    for X in P :
        if is_sorted(X) :
            return X
    return []

def worse(V) :
    P = list(permutations(V))
    for X in P :
        if is_sorted(X) :
            return X
    return []

def multinivel(V,N) :
    if N==0 :
        return sorted(V)
    else :
        P = list(permutations(V))
        multinivel(P,N-1)
        return P[0]

def cota(L) :
    return 3

def worst(V) :
    return multinivel( V, cota(len(V)) );