#include<bits/stdc++.h>

using namespace std;
class Graph
{
    int v;
    vector<int> *adj;
  public:
      Graph(int a)
      {
          v = a;
          adj = new vector<int>[a];
      }
      void addEdge(int x, int y)
      {
          adj[x].push_back(y);
          adj[y].push_back(x);
      }
      void printList()
      {
          for(int i = 0; i < v; i++)
          {
              cout<<"For node i "<<i<<": ";
              for(int j = 0; j < adj[i].size(); j++)
              {
                  cout<<adj[i][j]<<"\t";
              }
              cout<<"\n";
          }
      }
      void Dijkstra(int src)
      {
           vector<int> dist(v, INT_MAX);
           dist[src] = 0;
           vector<bool> finalize(v, false);

           for(int cnt = 0; cnt < v - 1; cnt++)
           {
               int u = -1;
               for(int i = 0; i < v; i++)
               {
                   if(!finalize[i] && (u==-1 || dist[i]< dist[u]))
                     u = i;
               }
               finalize[u] = true;
               for(int i = 0; i < v; i++)
               {
                   if(adj[u][i]!=0 && finalize[i]==false)
                   {
                       dist[i]= min(dist[i], dist[u] + adj[u][i]);
                   }
               }

           }
           for(int i = 0; i < v; i++)
           {
               cout<<dist[i]<<"\t";
           }
           cout<<endl;
      }


};
int main()
{
   int vertices, edges, src;
    cout<<"Enter number of Vertices to be THERE in The Graph: "; cin>>vertices;
    cout<<"Enter number of Edges to be THERE in The Graph: "; cin>>edges;
    cout<<"Enter The Source Vertex from where to BEGIN: "; cin>>src;
   Graph st(vertices);
     for(int i = 0; i < edges; i++)
     {
         int a, b; cin>>a>>b;
         st.addEdge(a, b);
     }
     st.printList();
    st.Dijkstra(src);

    return 0;
}
