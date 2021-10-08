import sys
'''
    0 --- 1
    |    / \ 
    |   /   4
    |  /   /
    2 --- 3
    0->2 : 1    2->3 : 4
    0->1 : 4    3->4 : 4
    1->2 : 2    1->4 : 4
'''
class Graph:
    def __init__(self,vert):
        self.vert = vert
        self.graph = [[0 for i in range(self.vert)]for j in range(self.vert)]
    def MinDist(self,dist,visited):
        min = sys.maxsize
        for v in range(self.vert):
            if dist[v]<min and visited[v] == False:
               min = dist[v]
               vert = v
        return vert
    def Dijksrra(self,start_node):
        dist = [sys.maxsize] * self.vert
        visited = [False] * self.vert
        dist[start_node] = 0
        for i in range(self.vert):
            u = self.MinDist(dist,visited)
            visited[u] = True
            for j in range(self.vert):
                if self.graph[u][j]>0 and visited[j] == False and dist[j] > dist[u] + self.graph[u][j]:
                    dist[j] = dist[u] + self.graph[u][j]
        self.print_sol(dist)
    def print_sol(self,dist):
        print("Distance from source to :-")
        for vert in range(self.vert):
            print(vert," = ",dist[vert])       
g = Graph(5)
g.graph = [[0,4,1,0,0],
           [4,0,2,0,4],
           [1,2,0,4,0],
           [0,0,4,0,4],
           [0,4,0,4,0]]
g.Dijksrra(0)