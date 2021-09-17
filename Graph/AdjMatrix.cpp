/*
    0
   / \
  1   2
 / \
3   4
*/
#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;
void AddEdge(vector <vector<int>> &adjmat,int u,int v)
{
    adjmat[u][v] = 1;
    adjmat[v][u] = 1;
}
void display(vector<vector<int>> &adjmat,int num_vert)
{
    for(int i = 0;i<num_vert;i++)
    {
        for(auto x:adjmat[i])
        {
            cout<<x<<" ";
        }
    cout<<endl;
    }
}
void BFS(vector<vector<int>> &adjmat,int start)
{
    vector<int>visited = {start};
    queue<int>q;
    q.push(start);
    while(q.empty() == false)
    {
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(int i = 0;i<adjmat.size();i++)
        {
            if(adjmat[v][i] == 1 && count(visited.begin(),visited.end(),i) == false)
            {
                visited.push_back(i);
                q.push(i);
            }
        }
    }
    cout<<endl;
}
void DFS(vector<vector<int>> &adjmat,int start)
{
    vector<int>visited = {start};
    stack<int>s;
    s.push(start);
    while(s.empty() == false)
    {
        int v = s.top();
        cout<<v<<" ";
        s.pop();
        for(int i = 0;i<adjmat.size();i++)
        {
            if(adjmat[v][i] == 1 && count(visited.begin(),visited.end(),i) == false)
            {
                visited.push_back(i);
                s.push(i);
            }
        }
    }
    cout<<endl;
}
int main()
{
    int num_vert = 5;
    vector<vector<int>>adjmat(num_vert,(vector<int>(num_vert,0)));
    AddEdge(adjmat,0,1);
    AddEdge(adjmat,0,2);
    AddEdge(adjmat,1,3);
    AddEdge(adjmat,1,4);
    display(adjmat,num_vert);
    cout<<"Bredth First Search"<<endl;
    BFS(adjmat,0);
    cout<<"Depth First Search"<<endl;
    DFS(adjmat,0);
}