#include <iostream>

using namespace std;
#define N 6
int main()
{
    int Mv = N;
   //cout<<"Mv "<<Mv<<endl;
    int arr[N];
    cout<<"Insert "<<N<<" elements in to the array:\n";
    for(int i = 1; i <= N-1; i++)
    {
        cin>>arr[i];
    }
    cout<<"Initial array:\n";
    for(int i = 1; i <= N-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int item;
    cout<<"Enter item to be inserted: ";
    cin>>item;

    int ptr = Mv, par = 0;
    while(ptr>1)
    {
        par = (int)ptr/2;
        cout<<"par: "<<par<<endl;
        if(item <=arr[par])
        {
            arr[ptr] = item;
            cout<<"Item inserted.\n";
            return 0;
        }
        cout<<"asd";
        arr[ptr] = arr[par];
        ptr = par;
    }
    arr[1]= item;
    cout<<"N "<<N<<" Mv "<<Mv<<endl;
    for(int i = 1; i <= Mv; i++){  cout<<arr[i]<<" ";}
    return 0;
}
