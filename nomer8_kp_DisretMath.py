import networkx as nx
import numpy.random as rnd
import matplotlib.pyplot as plt

def sum(f):
    sum = 0
    for i in range(len(f)):
        sum += f[i]
    return sum
'''
def function(matrix, g, f, n, m, j):
    for l in range(n):
        if matrix[l][j] == -1:
            for k in range(m):
                if matrix[l][k] == 1 and g[k] > 1:
                    matrix[l][k] = -1
                    g[k] -= 1
                    f[l] -= 1
                    return
                elif g[k] == 1:
                    function(matrix, g, f, n, m, k)
                else:
                    return
'''            
def add_edge(f_item, s_item, graph=None):
  graph.add_edge(f_item, s_item)
  graph.add_edge(s_item, f_item)

def minimal_cover(matrix, f, g, n, m, graph, first_partition_nodes):
        for i in range(n):
            if f[i] > 1:
                for j in range(m):
                    if matrix[i][j] == 1:
                        for k in range(n):
                            if matrix[k][j] == -1:
                                for l in range(m):
                                    if matrix[k][l] == 1 and g[l] > 1:
                                        matrix[k][l] = -1
                                        f[k] -= 1
                                        g[l] -= 1
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 1:
                    x_i = ''.join("x%d" %(i + 1))
                    y_j = ''.join("y%d" %(j + 1))
                    graph.add_node(x_i)
                    graph.add_node(y_j)
                    add_edge(x_i, y_j, graph=graph)
                    first_partition_nodes.append("x%d" %(i + 1))

n = int(input("Enter count of rows:"))
m = int(input("Enter count of colums:")) 

g = [0] * m
f = [0] * n

graph = nx.Graph()
matrix = []

for i in range(n):
    single_row = list(map(int, input().split()))
    matrix.append(single_row)


for i in range(n):
    for j in range(m):
        if matrix[i][j] == 1:
            x_i = ''.join("x%d" %(i + 1))
            y_j = ''.join("y%d" %(j + 1))
            graph.add_node(x_i)
            graph.add_node(y_j)
            f[i] += 1

for i in range(m):
    for j in range(n):
        if matrix[j][i] == 1:
            g[i] += 1
first_partition_nodes = []

sum = sum(f)

if sum == max(n, m):
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 1:
                x_i = ''.join("x%d" %(i + 1))
                y_j = ''.join("y%d" %(j + 1))
                add_edge(x_i, y_j, graph=graph)
                first_partition_nodes.append("x%d" %(i + 1))

elif sum > max(m, n):
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                if f[i] > 1 and g[j] > 1:
                    matrix[i][j] = -1
                    f[i] -= 1
                    g[j] -= 1
    minimal_cover(matrix, f, g, n, m, graph, first_partition_nodes)
"""if sum > max(m, n):
    while sum != max(n, m):
        for i in range(n):
            if f[i]>1:
                for j in range(m):
                    if matrix[i][j]==1:
                        function(matrix, g, f, n, m, j)
for i in range(m):
        for j in range(n):
            if matrix[i][j] == 1:
                x_i = ''.join("x%d" %(i + 1))
                y_j = ''.join("y%d" %(j + 1))
                add_edge(x_i, y_j, graph=graph)
                first_partition_nodes.append("x%d" %(i + 1))"""

for i in range(n):
  first_partition_nodes.append("".join("x%d" %(i + 1)))

print("Minimal cover:")
nx.draw_networkx(
    graph,
    node_color='blue',
    pos = nx.drawing.layout.bipartite_layout(graph, first_partition_nodes), 
    node_size=1000,
    with_labels=True) 

plt.show() 
