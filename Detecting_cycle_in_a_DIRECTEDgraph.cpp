
#if 1


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Graph
{

    int V;
    vector<int> *adj;
    bool DEFRecur(vector<bool> &vist1, vector<bool> &recStack1, int x1);
    public:

    Graph(int V);
    void addEdge(int a, int b);
    void shortestPath();
    void printing();

};
//bool DEFRecr(vector<bool> vist, vector<bool> recStack, vector<int> adj[], int x);
Graph:: Graph(int V)
{
    this->V = V;
     adj = new vector<int>[V];

}
void Graph:: addEdge(int a, int b)
{
    adj[a].push_back(b);
    cout<<"AN EDGE ADDED\n";
}
bool Graph:: DEFRecur(vector<bool> &vist1, vector<bool> &recStack1, int x1)
{
    if(vist1[x1]==false)
    {
        vist1[x1] = true;
        recStack1[x1] = true;
        for(int i = 0; i < adj[x1].size(); i++)
        {
            if(vist1[i]==false && DEFRecur(vist1, recStack1, i)==true)
                return true;
            else if(recStack1[i]==true)
                return true;
        }
    }
    recStack1[x1]= false;
    return false;


}
void Graph:: shortestPath()
{
    vector<bool> recStack;
    vector<bool> vist;
     recStack.assign(V, false);
    vist.assign(V, false);
    bool f = true;
   for(int i = 0; i < V; i++)
   {
       //if(vist[i]==false)
            if((DEFRecur(vist, recStack, i))==true)
            {
                f = false;
                 cout<<"\nTRUE\n"; break;
            }
   }
if(f) cout<<"\nFALSE\n";

}
void Graph::printing()
{
        cout<<"printing\n";
    for(int i = 0;i< V; i++)
    {
        cout<<"Vertex "<<i<<": ";
        for(auto x: adj[i])
        {
            cout<<x<<"\t";
        }
        cout<<endl;
    }
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
    A.shortestPath();

    return 0;
}
#elif 0

// A C++ Program to detect cycle in a graph
#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// Utility function to detect cycle in a Graph
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and
    // not part of recursion stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect
    // cycle in different DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}

#endif // 1
