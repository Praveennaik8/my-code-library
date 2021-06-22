// // You are given a sequence A1,A2,…,AN and you have to perform the following operation exactly X

// // times:

// //     Choose two integers i

// // and j such that 1≤i<j≤N
// // .
// // Choose a non-negative integer p
// // .
// // Change Ai
// // to Ai⊕2p, and change Aj to Aj⊕2p, where ⊕

// //     denotes bitwise XOR.

// // Find the lexicographically smallest sequence which can be obtained by performing this operation exactly X

// // times.

// // A sequence B1,B2,…,BN
// // is said to be lexicographically smaller than a sequence C1,C2,…,CN if there is an index i such that Bi<Ci and for each valid j<i, Bj=Cj

// // .
// // Input

// //     The first line of the input contains a single integer T

// // denoting the number of test cases. The description of T
// // test cases follows.
// // The first line of each test case contains two space-separated integers N
// // and X
// // .
// // The second line contains N
// // space-separated integers A1,A2,…,AN

// //     .

// // Output

// // For each test case, print a single line containing N

// // space-separated integers ― the lexicographically smallest obtainable sequence.
// // Constraints

// //     1≤T≤10

// // 2≤N≤105
// // 1≤X≤109
// // 1≤Ai≤109
// // for each valid i

// // Subtasks

// // Subtask #1 (30 points): N≤100

// // Subtask #2 (70 points): original constraints
// // Example Input

// // 1
// // 3 3
// // 2 2 3

// // Example Output

// // 0 0 3

// // Explanation

// // Example case 1: The original sequence is (2,2,3)

// // . Consider the following three operations:

// //     Choose i=1

// // , j=2 and p=1. Then, A1 changes from 2 to 2⊕21=0 and similarly, A2 changes from 2 to 2⊕21=0. Now the sequence is (0,0,3)
// // .
// // Next, choose i=1
// // , j=2 and p=1. Then, A1 changes to 0⊕21=2 and A2 changes to 0⊕21=2. The sequence is (2,2,3)
// // .
// // Next, again choose i=1
// // , j=2 and p=1. Then, A1 changes to 2⊕21=0 and A2 changes to 2⊕21=0. The sequence is (0,0,3)

// //     again.

// // We can check that after exactly 3 operations, this is the lexicographically smallest sequence we can obtain.
// #include<bits/stdc++.h>
// using namespace std;

// typedef long double ld;
// typedef long long ll;
// #define int long long
// #define vi vector<int>
// #define vll vector<long long>
// #define INF (ll)1e19
// #define testcase int t; cin>>t ;while(t--)
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define all(x) x.begin(), x.end()
// #define fill(a)  memset(a, 0, sizeof (a))
// #define fst first
// #define snd second
// #define mp make_pair
// #define pb push_back
// #define rep(i, n)    for(int i = 0; i < (n); ++i)
// #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
// #define repD(i, a, n)  for(int i = a; i >= (n); --i)
// #define mpl map<ll,ll>
// #define pii pair<int,int>
// #define SIZE ll(100005)//00002)
// #define FAIL -5677884
// #define BIT_SIZE 35
// #define MOD 1000000007

// void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
// {
//     cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
// }
// void prints(string s= "",int x =0)
// {
//     cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
// }
// bool bitAtGivenPosSetOrUnset(int n, int k) 
// { 
//     int new_num = n >> (k - 1); 
  
//     // if it results to '1' then bit is set, 
//     // else it results to '0' bit is unset 
//     return (new_num & 1); 
// } 
// int toggleKthBit(int n, int k) 
// { 
//     return (n ^ (1 << (k-1))); 
// } 
// void printarr(int arr[],int n)
// {
//     // cout<<k<<"--->  ";
//     for(int i = 0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\n";

    

// }
// signed main()
// {
//     fastio
//     testcase
//     {
//         int n,k;
//         cin>>n>>k;
        
//         int arr[n+10];
//         map<int,queue<int> >bit_map;
//         rep(i,n)
//         {
//             cin>>arr[i];
//             for(int j = 1;j<32;++j)
//             {
//                 if(bitAtGivenPosSetOrUnset(arr[i],j))
//                     bit_map[j].push(i);
//             }
//         }

//         for(int i = 0 ;i<n-1;i++)
//         {
//             if(k <= 0)
//                 break;
//             for(int j = 31;j>0;--j)
//             {
//                 if(k <= 0)
//                     break;
//                 if(bitAtGivenPosSetOrUnset(arr[i],j))
//                 {
//                     --k;
//                     arr[i] = toggleKthBit(arr[i],j);
//                     if(i!=bit_map[j].front())
//                     {
//                         print(i,j,bit_map[j].front());
//                         //cout<<"error\n";
//                         while(1);
//                     }
//                     bit_map[j].pop();
//                     int p = n-1;
//                     if(!bit_map[j].empty())
//                     {
//                         p = bit_map[j].front();
//                         bit_map[j].pop();
                        
//                     }
//                     else
//                     {
//                         if(!bitAtGivenPosSetOrUnset(arr[n-1],j))
//                             bit_map[j].push(n-1);
//                     }
//                     arr[p] = toggleKthBit(arr[p],j);
//                 }

//             }

//         }
//         for(auto it = bit_map.begin();it!=bit_map.end();it++)
//         {
//             auto kkk = it->second;
//             cout<<it->first<<"-> ";
//             while(!kkk.empty())
//             {
//                 cout<<kkk.front()<<" ";
//                 kkk.pop();
//             }
//             cout<<endl;
//         }
//         if(k>0&&k%2)
//         {
//             arr[n-1] = toggleKthBit(arr[n-1],1);
//             arr[n-2] = toggleKthBit(arr[n-2],1);
//         }
//         printarr(arr,n);
//     }
// }
// You are given a sequence A1,A2,…,AN and you have to perform the following operation exactly X

// times:

//     Choose two integers i

// and j such that 1≤i<j≤N
// .
// Choose a non-negative integer p
// .
// Change Ai
// to Ai⊕2p, and change Aj to Aj⊕2p, where ⊕

//     denotes bitwise XOR.

// Find the lexicographically smallest sequence which can be obtained by performing this operation exactly X

// times.

// A sequence B1,B2,…,BN
// is said to be lexicographically smaller than a sequence C1,C2,…,CN if there is an index i such that Bi<Ci and for each valid j<i, Bj=Cj

// .
// Input

//     The first line of the input contains a single integer T

// denoting the number of test cases. The description of T
// test cases follows.
// The first line of each test case contains two space-separated integers N
// and X
// .
// The second line contains N
// space-separated integers A1,A2,…,AN

//     .

// Output

// For each test case, print a single line containing N

// space-separated integers ― the lexicographically smallest obtainable sequence.
// Constraints

//     1≤T≤10

// 2≤N≤105
// 1≤X≤109
// 1≤Ai≤109
// for each valid i

// Subtasks

// Subtask #1 (30 points): N≤100

// Subtask #2 (70 points): original constraints
// Example Input

// 1
// 3 3
// 2 2 3

// Example Output

// 0 0 3

// Explanation

// Example case 1: The original sequence is (2,2,3)

// . Consider the following three operations:

//     Choose i=1

// , j=2 and p=1. Then, A1 changes from 2 to 2⊕21=0 and similarly, A2 changes from 2 to 2⊕21=0. Now the sequence is (0,0,3)
// .
// Next, choose i=1
// , j=2 and p=1. Then, A1 changes to 0⊕21=2 and A2 changes to 0⊕21=2. The sequence is (2,2,3)
// .
// Next, again choose i=1
// , j=2 and p=1. Then, A1 changes to 2⊕21=0 and A2 changes to 2⊕21=0. The sequence is (0,0,3)

//     again.

// We can check that after exactly 3 operations, this is the lexicographically smallest sequence we can obtain.
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
#define BIT_SIZE 50
#define MOD 1000000007

void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
//https://www.geeksforgeeks.org/check-whether-bit-given-position-set-unset/
bool bitAtGivenPosSetOrUnset(int n, int k) 
{ 
    int new_num = n >> (k - 1); 
    return (new_num & 1); 
} 
int toggleKthBit(int n, int k) 
{ 
    return (n ^ (1 << (k-1))); 
} 
void printarr(int arr[],int n)
{
    // cout<<k<<"--->  ";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    

}
signed main()
{
    fastio
    testcase
    {
        int n,k;
        cin>>n>>k;
        
        int arr[n+10];
        map<int,queue<int> >bit_map;
        rep(i,n)
        {
            cin>>arr[i];
            for(int j = 1;j<=BIT_SIZE;++j)
            {
                if(bitAtGivenPosSetOrUnset(arr[i],j))
                    bit_map[j].push(i);
            }
        }
        for(int i = 0 ;i<n-1;i++)
        {
            if(k <= 0)
                break;
            for(int j = BIT_SIZE;j>0;--j)
            {
                if(k <= 0)
                    break;
                if(bitAtGivenPosSetOrUnset(arr[i],j))
                {
                    --k;
                    arr[i] = toggleKthBit(arr[i],j);
                    if(i!=bit_map[j].front())
                    {
                        print(i,j,bit_map[j].front());
                        //cout<<"error\n";
                        while(1);
                    }
                    bit_map[j].pop();
                    int p = n-1;
                    if(!bit_map[j].empty())
                    {
                        p = bit_map[j].front();
                        bit_map[j].pop();
                        
                    }
                    else
                    {
                        if(!bitAtGivenPosSetOrUnset(arr[n-1],j))
                            bit_map[j].push(i);
                    }
                    arr[p] = toggleKthBit(arr[p],j);
                }

            }

        }
        if(n==2&&k>0&&k%2==0)
        {
            arr[n-1]^=1;
            arr[n-2]^=1;
        }
        printarr(arr,n);
    }
}