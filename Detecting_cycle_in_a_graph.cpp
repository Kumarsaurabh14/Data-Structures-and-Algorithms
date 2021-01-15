#if 0   //For Undirected
#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;
void printing(list<int> *adj, int edge)
{
    cout<<endl;
    for(int i = 0; i < edge; i++)
    {
        cout<<"For Vertex :"<<i<<" : ";
        for(auto j = adj[i].begin(); j != adj[i].end(); ++j)
        {
            cout<<*j<<"\t";
        }
        cout<<endl;
    }
}
void DFS(list<int> *adj, int v,int src, vector<bool> &vist, int parent)
{
    stack<int> s;
    vist[src] = true;
    s.push(src);
    bool f = true;
    while(!s.empty())
    {
        src = s.top();
        s.pop();

       /* if(!vist[src])
        {
            vist[src] = true;
        }*/
      cout<<endl<<"ABXC\t\n";
        for(auto x = adj[src].begin(); x!=adj[src].end(); x++)
        {
            if(vist[*x]==false)
            {
                parent = src;
                src = *x;
                s.push(*x);
                vist[*x] = true;
            }
            else if(parent!=*x)
            {
               // cout<<"TRUE:: Cycle Found.\n";
                f =  false;
            }
        }

    }
     if(f)
        {
            cout<<"FALSE:: Cycle not Found.\n";
        }
        else
        {
            cout<<"TRUE:: Cycle Found.\n";
        }
}

int main()
{
    int v, edge, src;
    cout<<"Enter number of Vertices to be THERE in The Graph: "; cin>>v;
    cout<<"Enter number of Edges to be THERE in The Graph: "; cin>>edge;
    cout<<"Enter The Source Vertex from where to BEGIN: "; cin>>src;

    list<int> *adj;
    adj = new list<int>[v];
    vector<bool> vist(false, v);

    int a, b;
    cout<<"Making an Undirected Graph\n";
    for(int i = 0; i < edge; i++)
    {
        cout<<"Connect edge A = ";  cin>>a;
        cout<<"Connect edge B = ";  cin>>b;
        adj[a].push_back(b);  adj[b].push_back(a);
    }

    //Printing Adjacency List
    printing(adj, edge);
    //DFS Traversal for identifying Cycle in Undirected Graph
    int parent = -1;
    DFS(adj, v, src, vist, parent);
   /* for(int i = 0; i < v; i++)
    {
        if(vist[i]==false)
            DFS(adl, i, src, vist, parent);


    }*/

    return 0;
}

#elif 1      //For Undirected
    #include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;
void printing(list<int> *adj, int edge)
{
    cout<<endl;
    for(int i = 0; i < edge; i++)
    {
        cout<<"For Vertex :"<<i<<" : ";
        for(auto j = adj[i].begin(); j != adj[i].end(); ++j)
        {
            cout<<*j<<"\t";
        }
        cout<<endl;
    }
}
bool DFSCycleDectect(list<int> adj[], int src, vector<bool> &vist, int parent)
{
   vist[src] = true;
   for(list<int>::iterator x = adj[src].begin(); x!=adj[src].end(); ++x)
   {
       if(!vist[*x])
       {
           if(DFSCycleDectect(adj, *x, vist, src))
                return true;
           else if(*x!= parent)
            return true;
       }

   }
   return false;

}


int main()
{
    int v, edge, src;
    cout<<"Enter number of Vertices to be THERE in The Graph: "; cin>>v;
    cout<<"Enter number of Edges to be THERE in The Graph: "; cin>>edge;
    cout<<"Enter The Source Vertex from where to BEGIN: "; cin>>src;

    list<int> *adj;
    adj = new list<int>[v];
    vector<bool> vist(false, v);

    int a, b;
    cout<<"Making an Undirected Graph\n";
    for(int i = 0; i < edge; i++)
    {
        cout<<"Connect edge A = ";  cin>>a;
        cout<<"Connect edge B = ";  cin>>b;
        adj[a].push_back(b);  adj[b].push_back(a);
    }

    //Printing Adjacency List
    printing(adj, edge);
    //DFS Traversal for identifying Cycle in Undirected Graph
    int parent = -1;

    for(int i = 0; i < v; i++)
    {
        if(vist[i]==false)
           if(DFSCycleDectect(adj, i, vist, parent))
                cout<<"TRUE\n";
            else
                cout<<"FALSE\n";
    }

    return 0;
}



#endif // 1
