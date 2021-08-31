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
