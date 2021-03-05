# Python3 programa de implementação de caixeiro viajante.

# problema usando abordagem ingênua.

from sys import maxsize 
from itertools import permutations
V = 6#definir o tamanho da matriz para o grafo
 
# implementação do problema do caixeiro viajante
def caixeiroViajante(graph, s): 
  
    # armazenar todos os vértices além do vértice de origem
    vertice = [] 
    for i in range(V): 
        if i != s: 
            vertice.append(i) 
  
    # armazenar peso mínimo,Ciclo Hamiltoniano
    caminhoMinimo = maxsize 
    next_permutation=permutations(vertice)
    for i in next_permutation:
 
        # armazenar o peso do caminho atual (custo)
        current_pathweight = 0
  
        # calcular o peso do caminho atual
        k = s 
        for j in i: 
            current_pathweight += graph[k][j] 
            k = j 
        current_pathweight += graph[k][s] 
 
        
        # atualização do menor caminho
        caminhoMinimo = min(caminhoMinimo, current_pathweight) 
         
    return caminhoMinimo 
 
 

# Código principal 
if __name__ == "__main__": 
 
    # representação de matriz do grafo
    graph = [[0, 10, 15, 20, 0, 10], [10, 0, 35, 25, 10, 0], 
            [15, 35, 0, 30, 15, 20], [20, 25, 30, 0, 20, 35],
            [15, 10, 20, 35, 0, 70], [30, 35, 25, 10, 0, 89],
            [18, 19, 30, 70, 8, 70], [10, 30, 0, 35, 60, 79]] 
    s = 0
    print(caixeiroViajante(graph, s))


