// Given integers N and M, find the number of ordered pairs (a,b) such that 1≤a<b≤N 
// and ((M mod a) mod b)=((M mod b) mod a).
// ((m%a)%b) = ((m%b)%a)

// ((m - (int(m/a))*a) - ((((m - (int(m/a))*a))/b)*b)) 

// Input
// The first line contains an integer T, the number of test cases. Then the test cases follow.
// The only line of each test case contains two integers N, M.
// Output
// For each testcase, output in a single line the answer to the problem.

// Constraints
// 1≤T≤1000
// 2≤N≤106
// 1≤M≤5⋅105
// The sum of N over all test cases does not exceed 106.
// Note: Multiplier for JAVA for this problem is reduced to 1.25 instead of usual 2.
// Rules:

// 1. ans+=n-1
// 2. if m%i == 0 then add n-i
// 3. else for every i add all Multipliers less than m && add all numbers greater than m and less than n
// 6  if i>m then add n-i
// 5
// 2
// 0
// 0
// 0
// 0
// 14  100 = 2 5 3




// Subtasks
// Subtask #1 (10 points):

// 1≤T≤10
// 2≤N≤103
// 1≤M≤105
// Subtask #2 (40 points):

// 1≤T≤100
// 2≤N≤105
// 1≤M≤105
// The sum of N over all test cases does not exceed 106.
// Subtask #3 (50 points): Original Constraints
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

signed main()
{
    fastio
    testcase
    {
        int n,m;
        cin>>n>>m;
        int cnt = 0;
        // cout<<"----\n";
        // repA(i,1,n)
        //     cout<<m%i<<endl;
        // repA(i,1,n)
        // {
        //     // cout<<i<<endl;
        //     for(int j = i+1;j<=n;j++)
        //     {
        //         // cout<<j<<endl;
        //         // ((M mod a) mod b)=((M mod b) mod a)
        //         if(((m%i)%j) == ((m%j)%i))
        //         {
        //             cout<<i<<" "<<j<<" = "<<((m%i)%j)<<endl;
        //             cnt+=1;
        //         }
        //     }
        // }
        int freq[n+1];
        rep(i,n+1)freq[i] = 0;
        int maxRem = 0;
        for(int i = n;i >=1 ;i--)
        {
            
            int x = m%i;
            maxRem = max(maxRem,x);
            int sum = 0;
            for(int j = 0;((i*j)+x)<=n ;++j)
            {
                sum+=freq[(j*i)+x];
                if(((i*j)+x) > maxRem)
                    break;
                
            }
            // for(auto xx: freq)
            // {
            //     if((xx.first-x)%i==0)
            //         sum+=xx.second;
            // }
            // cout<<i<<" "<<sum<<endl;
            cnt+=sum;
            freq[m%i]+=1;
        }
        
        cout<<cnt<<endl;
    }
}
