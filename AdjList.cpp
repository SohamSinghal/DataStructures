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
void AddEdge(vector<int>adjlist[],int u,int v)
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}
void display(vector<int>adjlist[],int num_vert)
{
    for (int v = 0; v < num_vert; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n"<<v;
        for (auto x : adjlist[v])
           cout << "--> " << x;
        printf("\n");
    }
}
void BFS(vector<int>adjlist[],int start)
{
    vector<int>visited;
    queue<int>q;
    int v;
    visited.push_back(start);
    q.push(start);
    while (q.empty() == false)
    {
        v = q.front();
        q.pop();
        cout << v <<" ";
        for(auto i = adjlist[v].begin();i != adjlist[v].end();i++)
        {
            if(count(visited.begin(),visited.end(),*i) == false)
            {
                visited.push_back(*i);
                q.push(*i);
            }
        }
    }
}
void DFS(vector<int>adjlist[],int start)
{
    vector<int>visited;
    stack<int>s;
    visited.push_back(start);
    s.push(start);
    while (s.empty() == false)
    {
        int v = s.top();
        s.pop();
        cout << v <<" ";
        for(auto i = adjlist[v].begin();i != adjlist[v].end();i++)
        {
            if(count(visited.begin(),visited.end(),*i) == false)
            {
                visited.push_back(*i);
                s.push(*i);
            }
        }
    }
}

int main()
{
    int num_vert = 5;
    vector <int> adjlist[num_vert];
    AddEdge(adjlist,0,1);
    AddEdge(adjlist,0,2);
    AddEdge(adjlist,1,3);
    AddEdge(adjlist,1,4);
    display(adjlist,num_vert);
    cout<<"Bredth First Search:"<<endl;
    BFS(adjlist,0);
    cout<<"\nDepth First Search"<<endl;
    DFS(adjlist,0);
}