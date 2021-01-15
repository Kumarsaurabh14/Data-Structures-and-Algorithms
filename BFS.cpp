#if 0      //NoTE:: Both programs are giving different output

#include <iostream>
#include<vector>
#include<queue>
//#define  vectors vector<vector<int> >
#define vect vector<int>
//#typedef for(int i = str; i < en; i++)  for(str, en)
using namespace std;
void CreateGraph(vect v[], int x)
{
    int u = 0, z = 0;
    while(true)
    {
        cout<<"Enter u and v: ";
        cin>>u>>z;
        if(u+1>=x) break;
        v[u].push_back(z);   v[z].push_back(u);
    }

}
void BFS(vect v[], int x)
{
    bool ar[x+1] = {false};
    queue<int> q;
    ar[s] = true;
    int s = 0;
    q.push(s);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int i = 0; i < v[node].size(); i++)
        {
            if(ar[v[node][i]]==false)
            {
                ar[v[node][i]] = true;
                q.push(v[node][i]);
            }
        }
    }

}
void printing(vect v[], int x)
{
    for(int i = 0; i < x; i++)
    {
        cout<<"vertex "<<i<<" : ";
        for(int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
int main()
{

   cout<<"Enter number of Nodes to Be created: ";
   int x;  cin>>x;
    vect v[x+1];
      CreateGraph(v, x);
      printing(v, x);
      BFS(v, x);

    return 0;
}
#elif 0
        #include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<bool> v;
vector<vector<int> > g;

void edge(int a, int b)
{
    g[a].pb(b);

    // for undirected graph add this line
     g[b].pb(a);
}

void bfs(int u)
{
    queue<int> q;

    q.push(u);
    v[u] = true;

    while (!q.empty()) {

        int f = q.front();
        q.pop();

        cout << f << " ";

        // Enqueue all adjacent of f and mark them visited
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}

// Driver code
int main()
{
    int n, e;
    cin >> n >> e;

    v.assign(n, false);
    g.assign(n, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edge(a, b);
    }

    for (int i = 0; i < n; i++) {
        if (!v[i])
            bfs(i);
    }

    return 0;
}

#elif 1
    #include<iostream>
    #include<vector>
    #include<queue>

    #define vect1 vector<bool>
    #define vect2 vector<vector<int> >
    #define pb push_back
    #define p push
    using namespace std;

    void makingGraph(vect2 &adj, int n)
    {
        cout<<"For undirected Graph...\n";
        int a, b;
        for(int i = 0; i < n; i++)
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
    void BFS(vect2 &adj, vect1 &vis, int siz, int srs)
    {
        queue<int> q;
        vis[srs] = true;
        q.p(srs);

        while(!q.empty())
        {
            int node = q.front();   q.pop();
            cout<<"BFS traversal Result: "<<node<<"\t";
            for(int i = 0; i < adj[node].size(); i++)
            {
                if(vis[adj[node][i]]==false)
                {
                    vis[adj[node][i]] = true;
                    q.p(adj[node][i]);
                }

            }
        }
        cout<<endl;
    }
    int main()
    {
        int n, e, s;
        cout<<"Enter number of vertices: "; cin>>n;
        cout<<"Enter number of edges to be formed: ";  cin>>e;
        cout<<"Enter the source vertex (vertex from where to begin): "; cin>>s;
        vect1  vis(false, n);  //maintaining visit list
        vect2  adj;  adj.assign(n, vector<int>());  // maintaining adjacency list

        makingGraph(adj, n);

        printing(adj, n);

        BFS(adj, vis, n, s);

        return 0;
    }


#endif // 1
