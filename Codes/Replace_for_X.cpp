// Replace for X Problem Code: REPLESX
// Add problem to Todo list
// Submit
// Tweet
 
// You are given an array of N integers A1,A2,…,AN and three more integers X,p, and k.

// An operation on the array is defined to be: replace the k-th smallest integer in the array with any integer you want.

// Output the minimum number of operations you must perform on the array (possibly 0 operations) to make the p-th smallest element of the array equal to X. If it is impossible to do so output −1.

// Note: the k-th smallest number in an array is the k-th number from the left when the array is sorted in non-decreasing order.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains four integers N,X,p,k respectively.
// The second line contains N space-separated integers A1,A2,…,AN.
// Output
// For each test case, print a single line containing one integer ― the minimum number of operations you must perform to make X the p-th smallest element or −1 if its impossible to do so.

// Constraints
// 1≤T≤100
// 1≤p,k≤N
// 0≤X≤109
// The sum of N over all test cases does not exceed 4∗105
// 0≤Ai≤109 for each valid i
// Subtasks
// Subtask #1 (10 points): N≤5
// Subtask #2 (40 points): The sum of N over all test cases does not exceed 3∗103
// Subtask #3 (50 points): Original constraints

// Example Input
// 2
// 5 4 3 4
// 4 9 7 0 8
// 2 25 1 2
// 100 20
// Example Output
// 1
// -1
// Explanation
// Example case 1:

// We can perform one operation in the array. Take the k-th smallest integer of the current array (which is 8 in this case) and replace it with 0. The array then becomes [4,9,7,0,0] which now makes 4 as the 3rd smallest number of the array.
// Example case 2:

// It is impossible to make 25 as the smallest number of the array.
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define INF (ll)1e19
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define mpl map<ll,ll>
#define pii pair<int,int>
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
#define MOD 1000000007

void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
int left(int arr[],int n,int p,int x)
{
    int i;
    for( i = p ;i>= 0 ;i--)
    {
        // cout<<arr[i]<<endl;
        if(arr[i] <= x)
        {
            // flag = 1;
            break;
        }
    }
    return p-i;
}
int right(int arr[],int n,int p,int x)
{
    int i;
    for( i = p ;i< n ;i++)
    {
        if(arr[i] >= x)
            break;
        
    }
    return i-p;
}
signed main()
{
    //fastio
    testcase
    {
        int n,x,p,k;
        cin>>n>>x>>p>>k;
        int arr[n+10];
        rep(i,n)
            cin>>arr[i];
        sort(arr,arr+n);
        --p;
        --k;
        if(arr[p] == x)
         cout<<"0\n";
        else if(p<k)
        {   
            if(arr[p] < x)
            {
                cout<<"-1\n";
            }
            else
                cout<<left(arr,n,p,x)<<"\n";
        }
        else if(p==k)
        {
            if(arr[p] < x)
            {
                cout<<right(arr,n,p,x)<<"\n";
            }
            else
                cout<<left(arr,n,p,x)<<"\n";
        }
        else
        {
            if(arr[p] > x)
            {
                cout<<"-1\n";
            }
            else
                cout<<right(arr,n,p,x)<<"\n";
        } 
    }
}