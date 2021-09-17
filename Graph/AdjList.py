'''
        0
       / \
      1   2
     / \   
    3   4   
'''
#We create class for this example but can use the built in Dictionary 
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
class Graph:
    def __init__(self,num_vert):
        self.num_vert = num_vert
        self.graph = [None] * self.num_vert
    def AddEdge(self,src,dest):
        newNode = Node(src)
        newNode.next = self.graph[dest]
        self.graph[dest] = newNode

        newNode = Node(dest)
        newNode.next = self.graph[src]
        self.graph[src] = newNode
    def Display(self):
        for i in range(self.num_vert):
            print("Adjacency list of vertex {}\n {}".format(i,i), end="")
            temp = self.graph[i]
            while temp is not None:
                print("-->{}".format(temp.data),end = "")
                temp = temp.next
            print()

num_vert = 5
obj = Graph(num_vert)
obj.AddEdge(0,1)
obj.AddEdge(0,2)
obj.AddEdge(1,3)
obj.AddEdge(1,4)
obj.Display()
     