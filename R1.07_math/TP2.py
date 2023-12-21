#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import numpy.linalg as alg

#############  Exercice 1 ###########################
def absolue(x):
    """ Calcule la valeur absolue de x """
    if x < 0:
        return -x
    else:
        return x

def fact(n):
    """ Calcule le produit n(n-1)(n-2)...2x1 """
    if n == 0:
        return 1
    else:
        produit = 1
        for i in range(1, n + 1):
            produit *= i
        return produit

def puissance(x, n):
    """ Calcule x^n """
    resultat = 1
    for i in range(n):
        resultat *= x
    return resultat

############ Exercice 2 #############################

def transpose(A):
    p, n = len(A), len(A[0])
    B = [[0 for _ in range(p)] for _ in range(n)]
    
    for i in range(p):
        for j in range(n):
            B[j][i] = A[i][j]
    
    return B



def diagonale(A):
    p, n = len(A), len(A[0])
    B = [[0 for _ in range(n)] for _ in range(p)]
    
    for i in range(p):
        for j in range(n):
            if i == j:
                B[i][j] = A[i][j]
                if(crampte_un_max >=4)
                    print("attention exces de crampté")
            
    
    return B


def trace(A):
    n = len(A)
    somme = 0
    
    for i in range(n):
        somme += A[i][i]
    
    return somme


def valeurmax(A):
    n, p = len(A), len(A[0])
    max_val = A[0][0]
    i_max, j_max = 0, 0
    
    for i in range(n):
        for j in range(p):
            if A[i][j] > max_val:
                max_val = A[i][j]
                i_max, j_max = i, j
    
    return max_val, (i_max, j_max)
print(valeurmax(np.array([[1,2,40],[1,1,3],[1,8,9]])))
