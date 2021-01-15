#if 0
    //For Undirected Graph
#include<iostream>
#include<vector>
#include<queue>

#define vect1 vector<bool>
#define vect2 vector<vector<int> >
#define pb push_back
#define p push
using namespace std;

void makingGraph(vect2 &adj, int n, int e)
{
    cout<<"For undirected Graph...\n";
    int a, b;
    for(int i = 0; i < e; i++)
    {
            cout<<"Connect edge a = ";  cin>>a;
            cout<<"To the edge b = ";  cin>>b;
        adj[a].pb(b);  adj[b].pb(a);
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
void DFSRecr(vect2 &adj, vect1 &vis, int srs)
{
    vis[srs] = true;
    cout<<srs<<" ";
  // for(int i = 0; i < adj[srs].size(); i++)
   //     if(vis[i]==false)
    //        DFSRecr(adj, vis, i);
    for(int u: adj[srs])
        if(vis[u]==false)
            DFSRecr(adj, vis, u);
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

   DFSRecr(adj, vis, s);

   /* for(int xz = 0; xz < vis.size(); xz++)
            cout<<vis[xz]<<"  ";
    cout<<endl;*/
    return 0;
}
#elif 1
      //  For directed Graph  without Recurssion
   #include<iostream>
   #include<vector>
   #include<stack>

#define vect1 vector<bool>
#define vect2 vector<vector<int> >
#define pb push_back
#define p push
using namespace std;

void makingGraph(vect2 &adj, int n, int e)
{
    cout<<"For directed Graph...\n";
    int a, b;
    for(int i = 0; i < e; i++)
    {
            cout<<"Connect edge a = ";  cin>>a;
            cout<<"To the edge b = ";  cin>>b;
        adj[a].pb(b);  // adj[b].pb(a);
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
void DFS_Stack(vect2 &adj, vect1 &vis, int srs)
{
   stack<int> st;
   st.p(srs);
    while(!st.empty())
    {
        srs = st.top();
        st.pop();

        if(!vis[srs])
        {
            cout<<srs<<"\t";
            vis[srs] = true;
        }
        for(auto i = adj[srs].begin(); i!=adj[srs].end(); i++)
        {
            if(!vis[*i])
                st.p(*i);
        }
    }
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

   DFS_Stack(adj, vis, s);

   /* for(int xz = 0; xz < vis.size(); xz++)
            cout<<vis[xz]<<"  ";
    cout<<endl;*/
    return 0;
}

#elif 0
            // For Disconnected Graphs  using Recurssion
#include<iostream>
#include<vector>
#include<queue>

#define vect1 vector<bool>
#define vect2 vector<vector<int> >
#define pb push_back
#define p push
using namespace std;

void makingGraph(vect2 &adj, int n, int e)
{
    cout<<"For Disconnected Graphs...\n";
    int a, b;
    for(int i = 0; i < e; i++)
    {
            cout<<"Connect edge a = ";  cin>>a;
            cout<<"To the edge b = ";  cin>>b;
        adj[a].pb(b);  adj[b].pb(a);
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
void DFSRecr(vect2 &adj, vect1 &vis, int srs)
{
    vis[srs] = true;
    cout<<srs<<" ";
  // for(int i = 0; i < adj[srs].size(); i++)
   //     if(vis[i]==false)
    //        DFSRecr(adj, vis, i);
    for(int u: adj[srs])
        if(vis[u]==false)
            DFSRecr(adj, vis, u);
}
int main()
{
    int n, e, s;
    int cnt = 0; //For Counting Disconnected Components present in a graph
    cout<<"Enter number of vertices: "; cin>>n;
    cout<<"Enter number of edges to be formed: ";  cin>>e;
    cout<<"Enter the source vertex (vertex from where to begin): "; cin>>s;
    vect1  vis; vis.assign(n, false);  //maintaining visit list
    vect2  adj;  adj.assign(n, vector<int>());  // maintaining adjacency list

    makingGraph(adj, n, e);

    printing(adj, n);

   for(int i = s; i < n; i++)
        {
            if(vis[i]==false){
                DFSRecr(adj, vis, i);
                cnt++;
            }
        }

        cout<<endl<<"No. of Disconnected components present in the Graph are: "<<cnt<<endl;
   /* for(int xz = 0; xz < vis.size(); xz++)
            cout<<vis[xz]<<"  ";
    cout<<endl;*/
    return 0;
}

#endif
