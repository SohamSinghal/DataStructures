import sys
def PrimsAlgo(Graph,V):
    visited = [False]*V
    no_of_edge = 0
    visited[0] = True
    net_cost = 0
    while(no_of_edge<V-1):
        min = sys.maxsize
        x,y = 0,0
        for i in range(V):
            if visited[i]:
                for j in range(V):
                    if((not visited[j]) and Graph[i][j] != 0):
                        if min>Graph[i][j]:
                            min = Graph[i][j]
                            x = i
                            y = j
        net_cost += Graph[x][y]
        print(str(x + 1) + " - " + str(y + 1) + "\nCost = " + str(Graph[x][y]))
        visited[y] = True
        no_of_edge += 1
    print("Net Cost = "+ str(net_cost))
vertex = 5
G = [[0, 9, 7, 0, 0],
     [9, 0,10, 12, 5],
     [6, 9, 0, 4, 7],
     [0, 10, 5, 0, 3],
     [0, 4, 6, 3, 0]]
PrimsAlgo(G,vertex)

