#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    public:
        Graph(int V)
        {
            this->V=V;
            adj=new list<int>[V];
        }
        void addEdge(int u,int v,bool bidir)
        {
            adj[u].push_back(v);
            if(!bidir)
            {
                adj[v].push_back(u);
            }
        }
        void display()
        {
            for(int i=0;i<V;i++)
            {
                cout<<i<<"->";
                for(int neighbour:adj[i])
                {
                    cout<<neighbour<<" ";
                }
                cout<<endl;
            }
        }
        void BFS()//Time complexity: O(V+E)
        {
            queue<int>q;
            q.push(0);
            vector<bool>visited(V,false);
            while(q.size()>0)
            {
                int u=q.front();
                q.pop();
                cout<<u<<" ";
                visited[u]=true;
                for(int neighbour:adj[u])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
        }
        void DFSHelper(int u,vector<bool> &visited)//Time complexity: O(V+E)
        {
            cout<<u<<" ";
            visited[u]=true;
            for(int neighbour:adj[u])
            {
                if(!visited[neighbour])
                {
                    DFSHelper(neighbour,visited);
                }
            }
        }
        void DFS()
        {
            vector<bool>visited(V,false);
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                    DFSHelper(i,visited);
                }
            }
        }
        void TopologicalHelper(int u,vector<bool> &visited,vector<int> &TopologicalOrder)//Time complexity: O(V+E)
        {
            visited[u]=true;
            for(int neighbour:adj[u])
            {
                if(!visited[neighbour])
                {
                    TopologicalHelper(neighbour,visited,TopologicalOrder);
                }
            }
            TopologicalOrder.push_back(u);
        }
        void topologicalSort()//using DFS, Time complexity: O(V+E)
        {
            vector<bool>visited(V,false);
            vector<int>TopologicalOrder;
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                    TopologicalHelper(i,visited,TopologicalOrder);
                }
            }
            reverse(TopologicalOrder.begin(),TopologicalOrder.end());
            for(int i:TopologicalOrder)
            {
                cout<<i<<" ";
            }
            //We can use stack instead of vector and reverse function
        }
};

int main()
{
    Graph g(5);//Directional graph
    g.addEdge(0,1,false);
    g.addEdge(1,2,false);
    g.addEdge(1,3,false);
    g.addEdge(2,4,false);
    g.display();
    g.BFS();
    cout<<endl;
    g.DFS();
    cout<<endl;
    cout<<"Topological Sort: ";
    g.topologicalSort();
    cout<<endl;
    return 0;
}