#include<iostream>
#include<vector>
#include<queue>
                                                         //       Kahn’s algorithm for Topological Sorting
#define note inDegree                                    //       Using BFS Traversal;
using namespace std;
class Graph
{
    int V;
    vector<int> *adj;
    vector<int> note;
public:
    Graph(int v);
    void addEdge(int a, int b);
    void printing();
    void TopoLogicalSort();

};
Graph:: Graph(int v)
{
    V = v;
    adj = new vector<int>[v];
    note.assign(v,0);
}
void Graph:: addEdge(int a, int b)
{
     adj[a].push_back(b);
     note[b]++;
}
void Graph:: TopoLogicalSort()
{
    queue<int> q;
    vector<int> result;
    for(int i = 0; i <note.size(); i++)
    {
       if(note[i]==0)
        q.push(i);

    }
    int cnt = 0;
    while(!q.empty())
    {
        int p = q.front();  q.pop();
        result.push_back(p);
        for(int i = 0; i < adj[p].size(); i++)
        {
            note[adj[p][i]]--;
            if(note[adj[p][i]]==0)
                q.push(adj[p][i]);
        }
        cnt++;
    }
     if (cnt != V) {
        cout << "There exists a cycle in the graph so Topological sort is not possible.\n";
        return;
    }
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<"\t";
    cout<<endl;
}
void Graph:: printing()
{
    for(int i = 0; i < V; i++)
    {
        cout<<"Connecting edge "<<i<<": ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"printing NOTE\n";
    for(auto x: note)
        cout<<x<<"\t";
    cout<<endl;

}
int main()
{
 int v, edge;
   //int src;

    cout<<"Enter number of Vertices to be THERE in The Graph: "; cin>>v;
    cout<<"Enter number of Edges to be THERE in The Graph: "; cin>>edge;
   // cout<<"Enter The Source Vertex from where to BEGIN: "; cin>>src;
    Graph A(v);
    int a=0, b=0;
    cout<<"Making an directed Graph\n";
    for(int i = 0; i < edge; i++)
    {
        cout<<"Connect edge A = ";  cin>>a;
        cout<<"Connect edge B = ";  cin>>b;
        A.addEdge(a,b);
    }
    A.printing();
    A.TopoLogicalSort();
   // A.printing();
    return 0;
}
