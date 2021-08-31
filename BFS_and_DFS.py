'''
    A
   / \
  B   C
 / \   \
D   E   F
     \
      G
'''
#In python we use dictionary to describe a graph in Adjacency List format. 
#We need not repeat a vertex again and again but for the heck of it I have.
Graph = {
    "A":["B","C"],
    "B":["A","D","E"],
    "C":["A","F"],
    "D":["B"],
    "E":["B","G"],
    "F":["C"],
    "G":["E"]
}
def BFS(Graph,start):
    visited = []
    queue = []
    visited.append(start)
    queue.append(start)
    while queue:
        v = queue.pop(0) #queue follows First in First out
        print(v,end = " ")
        for neighbour in Graph[v]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)
def DFS(Graph,start):
    visited = []
    stack = []
    visited.append(start)
    stack.append(start)
    while stack:
        v = stack.pop(-1) #Stack follows First In Last Out
        print(v,end = " ")
        for neighbour in Graph[v]:
            if neighbour not in visited:
                visited.append(neighbour)
                stack.append(neighbour)

BFS(Graph,"A")
print()
DFS(Graph,"A")




    