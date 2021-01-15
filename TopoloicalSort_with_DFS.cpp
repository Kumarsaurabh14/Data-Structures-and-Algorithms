#include<bits/stdc++.h>

#define vect1 vector<bool>
#define vect2 vector<vector<int> >
#define pb push_back
#define p push
using namespace std;

void makingGraph(vect2 &adj, int n, int e)
{
    cout<<"For Directed Graph...\n";
    int a, b;
    for(int i = 0; i < e; i++)
    {
            cout<<"Connect edge a = ";  cin>>a;
            cout<<"To the edge b = ";  cin>>b;
        adj[a].pb(b);  //adj[b].pb(a);
    }

}

void printing(vect2 &adj, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"For vertex "<<i<<" : ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void DFSRecr(vect2 &adj, vect1 &vis, int vertex, stack<int> &stk)
{
    vis[vertex] = true;
   // cout<<srs<<" ";
  // for(int i = 0; i < adj[srs].size(); i++)
   //     if(vis[i]==false)
    //        DFSRecr(adj, vis, i,stk);
    for(int u: adj[vertex])
        if(vis[u]==false)
            DFSRecr(adj, vis, u, stk);
    stk.push(vertex);
}
void TopoLogicalSort(stack<int> &stk, vect2 &adj, vect1 &vis, int n)
{
    for(int i = 0; i <  n ; i++)
    {
        for(int j = 0; j < adj[i].size(); j++ )
        {
            if(vis[adj[i][j]]==false)
                DFSRecr(adj, vis, adj[i][j], stk);

        }
    }
    while(!stk.empty())
    {
        int result = stk.top();  stk.pop();
        cout<<result<<"\t";
    }
    cout<<endl;

}
int main()
{
    int n, e, s;
    cout<<"Enter number of vertices: "; cin>>n;
    cout<<"Enter number of edges to be formed: ";  cin>>e;
    cout<<"Enter the source vertex (vertex from where to begin): "; cin>>s;
    vect1  vis; vis.assign(n, false);  //maintaining visit list
    vect2  adj;  adj.assign(n, vector<int>());  // maintaining adjacency list

    makingGraph(adj, n, e);

    printing(adj, n);
    stack<int> stk;
    TopoLogicalSort(stk, adj, vis, n);
    return 0;
}
