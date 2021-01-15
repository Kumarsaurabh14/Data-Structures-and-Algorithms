#if 0
#include<iostream>

#include<vector>

using namespace std;
void addValue(vector<int> adj[], int a, int b)
{
        adj[a].push_back(b);
        adj[b].push_back(a);

}
void printing(vector<int> adj[], int v)
{

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"\t";

        }
        cout<<endl;
    }
}

int main()
{
    int v;  cout<<"Enter number of vertices: ";
            cin>>v;
    vector<int> adj[v];
    int a = 0, b = 0, k = 0 ;
    while(k<v){
    cout<<"Enter node1 value: "; cin>>a;
    cout<<"Enter node2 value: "; cin>>b;
    addValue(adj, a,b);

    k += 1;
     }
     /*addValue(adj, 0, 1);
     addValue(adj, 0, 2);
    addValue(adj, 1, 2);
    addValue(adj, 1, 3);*/
           printing(adj, v);
    return 0;
}
#elif 1

    #include<iostream>

    #include<vector>

using namespace std;
void addValue(vector<vector<int> > &adj, int a, int b)
{
        adj[a].push_back(b);
       adj[b].push_back(a);

}
void printing(vector<vector<int> > &adj, int v)
{

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j]<<"\t";

        }
        cout<<endl;
    }
}

int main()
{
    int v;  cout<<"Enter number of vertices: ";
            cin>>v;
    vector<vector<int> > adj(v+2);
    int a = 0, b = 0, k = 0 ;
    while(k<v){
    cout<<"Enter node1 value: "; cin>>a;
    cout<<"Enter node2 value: "; cin>>b;
    addValue(adj, a,b);

    k += 1;
     }
     printing(adj, v);
   /*  addValue(adj, 0, 1);
     addValue(adj, 0, 2);
    addValue(adj, 1, 2);
    addValue(adj, 1, 3);
           printing(adj, v);  */
    return 0;
}
#endif // 1
