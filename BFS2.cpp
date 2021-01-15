#if 1                                      //counting number of disconnected components in a graph
    #include<iostream>
    #include<vector>
    #include<queue>

    #define pb push_back
    #define vect2D vector<vector<int> >
    #define vect1D vector<bool>
using namespace std;
void addEdge(vect2D &ar, int a, int b)
{
    ar[a].pb(b);
    ar[b].pb(a);
}
void BFSDisc(vect2D &ar, vect1D &vis, int i, int n)
{
    queue<int> q;
    vis[i] = true;
    q.push(i);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<"\t";
        for(int j = 0; j < ar[node].size(); j++)
        {
            if(vis[ar[node][j]]==false)
            {
                vis[ar[node][j]] = true;
                q.push(ar[node][j]);
            }
        }
    }
}
int main()
{
    int n, e;  cin>>n>>e;
    vect2D ar;
    vect1D vis;
    ar.assign(n, vector<int>());
    vis.assign(n, false);
    int a, b, cnt = 0 ;
    for(int i = 0;i < e; i++)
    {
        cin>>a>>b;
          addEdge(ar, a, b);
    }

    for(int i = 0; i < n; i++)
    {
        if(vis[i]==false)
        {

            BFSDisc(ar, vis, i, n);
            cnt += 1;
        }
    }
    cout<<endl<<"No. of Disconnected components present in the Graph are: "<<cnt<<endl;
    return 0;
}
#endif // 1
