
#if 1


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
    public:
    int V;
    vector<int> *adj;


    vector<int> dist;
    vector<bool> vist;
    Graph(int V);
    void addEdge(int a, int b);
    void shortestPath(int src);
    void printing();
};
Graph:: Graph(int V)
{
    this->V = V;
     adj = new vector<int>[V];
     dist.assign(V, 0);
    vist.assign(V, false);
}
void Graph:: addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void Graph:: shortestPath(int src)
{
    dist[src] = 0;


    queue<int> q;
    q.push(src);  vist[src]= true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++)
        {
            if(vist[adj[node][i]]==false)
            {
                dist[adj[node][i]] = dist[node]+1;
                vist[adj[node][i]] = true;
                q.push(adj[node][i]);

            }
        }
    }

}
void Graph::printing()
{

    for(int i = 0;i< V; i++)
    {
        cout<<"Vertex "<<i<<": ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

}
int main()
{
   int v, edge, src;
    cout<<"Enter number of Vertices to be THERE in The Graph: "; cin>>v;
    cout<<"Enter number of Edges to be THERE in The Graph: "; cin>>edge;
    cout<<"Enter The Source Vertex from where to BEGIN: "; cin>>src;


    Graph A(v);
    int a, b;
    cout<<"Making an Undirected Graph\n";
    for(int i = 0; i < edge; i++)
    {
        cout<<"Connect edge A = ";  cin>>a;
        cout<<"Connect edge B = ";  cin>>b;
        A.addEdge(a,b);
    }

    A.printing();
    A.shortestPath(src);
    cout<<"Dist Array: ";
    for(int i = 0; i < v; i++)
    {
        cout<<A.dist[i]<<"\t";
    }
    cout<<endl;

    return 0;
}

#endif // 1
