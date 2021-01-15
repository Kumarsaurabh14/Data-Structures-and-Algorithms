#if 1
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
//#include<bits/stdc++.h>

using namespace std;
bool myComp(const pair<int, int>  &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
void printData(vector< pair <int,int> > &data, int no_of_tasks)
{
      for( int i = 0; i < no_of_tasks; i++)
     {
         cout<<data[i].first<<"\t"<<data[i].second<<endl;
     }
}
int main()
{
    int no_of_tasks;
    cout<<"Enter Number of Tasks: ";  cin>>no_of_tasks;

    vector<pair<int, int> > data;
    for(int i = 0; i < no_of_tasks; i++)
    {
        int end_time, profit; cin>>end_time>>profit;
        data.push_back(make_pair(end_time, profit));
    }


     sort(data.begin(), data.end(), myComp);
     printData(data, no_of_tasks);
     auto mxm = *max_element(data.begin(), data.end(), [](const auto &left, const auto &right)
                           { return left.first < right.first; });

    cout<<"Maximum: "<<mxm.first<<endl;
    // int arr[mxm.first] = {0};
     vector<int> arr;
     bool visit[mxm.first] = {false};
    int maxm_profit = 0;
    int index = 0;
    for(int i = 0; i <no_of_tasks; i++)
    {

        if(visit[data[i].first-1]==false)
        {
           // arr[i] = data[i].first;
            arr.push_back(data[i].first);
            visit[data[i].first-1] = true;
            maxm_profit += data[i].second;
            //index = i;
        }
        else
        {
           cout<<"data_first_as false: "<<data[i].first<<"\t"<<data[i].second<<endl;
            int d = 0;
            while(d< mxm.first)
            {
                if(visit[d]==false && d < data[i].first)
                {
                   cout<<"d: "<<d<<"  data["<<i<<"].first\n";
                   // arr[++index] = data[i].first;
                   arr.push_back(data[i].first);
                    visit[d]=true;
                    maxm_profit += data[i].second;
                    break;
                }
                d += 1;
            }
        }
    }
    cout<<"Required Job Sequence: ";
    for(int i = 0; i < arr.size(); i++)
    {
       // if(arr[i])
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<"Maximum Profit: "<<maxm_profit<<endl;
   // printData(data, no_of_tasks);
    return 0;
}
#elif 0
//Source- GFG
// C++ program to find the maximum profit
// job sequence from a given array
// of jobs with deadlines and profits
#include<iostream>
#include<algorithm>
using namespace std;

// A structure to represent a job
struct Job
{
    char id; // Job Id
    int dead; // Deadline of job

    // Profit if job is over
    // before or on deadline
    int profit;
};

// This function is used for sorting all
// jobs according to profit
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

// Returns minimum number of platforms reqquired
void printJobScheduling(Job arr[], int n)
{
    // Sort all jobs according to
    // decreasing order of prfit
    sort(arr, arr+n, comparison);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]; // To keep track of free time slots

    // Initialize all slots to be free
    for (int i=0; i<n; i++)
        slot[i] = false;

    // Iterate through all given jobs
    for (int i=0; i<n; i++)
    {
        // Find a free slot for this job
        // (Note that we start
        // from the last possible slot)
        for (int j=min(n, arr[i].dead)-1; j>=0; j--)
        {
            // Free slot found
            if (slot[j]==false)
            {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    for (int i=0; i<n; i++)
    if (slot[i])
        cout << arr[result[i]].id << " ";
}

// Driver Code
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                {'d', 1, 25}, {'e', 3, 15}};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Following is maximum profit sequence of job : ";

    printJobScheduling(arr, n);

    return 0;
}
#endif // 0
