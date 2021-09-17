'''
        0
       / \
      1   2
     / \   
    3   4   
'''
class Graph:
    def __init__(self,size):
        self.size = size
        self.adjmat = []
        for i in range(size):
            self.adjmat.append([0 for i in range(size)])
    def AddEdge(self,d1,d2):
        if d1 is d2:
            print("Same value so no edje present")
            return
        self.adjmat[d1][d2] = 1
        self.adjmat[d2][d1] = 1
    def BFS(self,start,visited):
        queue = [start]
        visited[start] = True
        while queue:
            v = queue.pop(0) #Queue uses First in First Out
            print(v, end = " ")
            for i in range(self.size):
                if (self.adjmat[v][i] == 1 and (visited[i] == False)):
                    visited[i] = True
                    queue.append(i)
    def DFS(self,start,visited):
        visited[start] = True
        stack = [start]
        while stack:
            v = stack.pop(-1) #Stack uses First In Last Out
            print(v,end = " ")
            for i in range(self.size):
                if (self.adjmat[v][i] == 1 and visited[i] == False):
                    visited[i] = True
                    stack.append(i)
    def Display(self):
        for row in self.adjmat:
            for val in row:
                print("{}".format(val),end = " ")
            print()
    
num_vert = 5
obj = Graph(num_vert)
obj.AddEdge(0,1)
obj.AddEdge(0,2)
obj.AddEdge(1,3)
obj.AddEdge(1,4)
obj.Display()
print("Bredth First Search")
visited = [False]*num_vert
obj.BFS(0,visited)
print("\nDepth Fisrst Search")
visited = [False]*num_vert
obj.DFS(0,visited)
