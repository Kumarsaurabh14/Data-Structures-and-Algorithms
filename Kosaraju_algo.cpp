#include<bits/stdc++.h>
#define  vec vector<int>
// I GIVE UP
using namespace std;

void addEdge(vec adj[], int sr, int des )
{
    adj[sr].push_back(des);  //Directed Graph
}
void printing(vec adj[], int v)
{
    for(int i= 0; i < v; i++)
    {
        cout<<"Vertex i = "<<i<<": ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void DFSRecr(vec adj[], vec &visit, int vertex, stack<int> &st)
{
    visit[vertex] = 1;

    for(int i = 0; i < adj[vertex].size(); i++)
       if(visit[adj[vertex][i]]==0)
            DFSRecr(adj, visit, adj[vertex][i], st);
    st.push(vertex);
}
void TopologicalSort(vec adj[], vec &visit, int v,  stack<int> &st)
{


    for(int i = 0; i < v; i++)
    {

        for(int j = 0; j < adj[i].size(); j++)
        {
            if(visit[adj[i][j]]==0)
            {
                DFSRecr(adj, visit, adj[i][j], st);
            }
        }
    }

    while(!st.empty())
    {

        int x = st.top(); st.pop();
        cout<<x<<"\t";
    }
    cout<<endl;

}
void Transpose(vec adj[], vec trans[], int v)
{
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; adj[i].size(); j++)
           trans[adj[i][j]].push_back(i);
    }
    for(int i = 0; i < v; i++)
    {
        cout<<" Trans Vertex i = "<<i<<": ";
        for(int j = 0; j < trans[i].size()+1; j++)
        {
            cout<<trans[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{

    int v, e, src;
    //cin>>v>>e>>src;
    cout<<"Enter number of vertices: "; cin>>v;
    cout<<"Enter number of edges: "; cin>>e;
   // cout<<"Enter source vertex: "; cin>>src;

    vec adj[v];
    vec visit;
    stack<int> st;
//    adj.assign(v, vector<int>());
    visit.assign(v, 0);

    for(int i = 0; i < e; i++)
    {
        int a, b;  //a-> represent Source;  b -> represent Destination
        cin>>a>>b;
        addEdge(adj,a, b);
    }
    printing(adj, v);

    TopologicalSort(adj, visit, v, st);
    cout<<"topo ends\n";
    vec trans[v];
   // trans.assign(v, vector<int>());
  //  trans  = new vector<int>[v];
  for(int i = 0; i < e; i++)
  {
      trans[i].push_back(0);
  }
    Transpose(adj, trans, v);

//    visit.assign(v, 0);
//    DFSRecPrint(trans, visit, v);
    cout<<endl;
    //printing(trans, v);
    return 0;
}
