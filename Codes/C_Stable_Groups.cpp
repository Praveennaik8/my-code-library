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
/*
 1 5
 8 12
 13 20

8
1 16
1 9 17
16
16

8
1 7




*/

signed main()
{
    fastio
    
    int n,k,x;
    cin>>n>>k>>x;

    vector<int>arr;
    int temp;
    rep(i,n)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    sort(all(arr));
    vector<int >enddiff;

    for(int i =1;i<arr.size();i++)
    {
        if(arr[i] - arr[i-1]>x)
        {
            int temp = (arr[i]-arr[i-1]);
            enddiff.push_back((temp-1));

        }
    }
    // cout<<enddiff.size()<<endl;
    sort(all(enddiff),less<int>());
    int count = 0;
    int ans = 0;
    for(auto xx:enddiff)
    {
        if(count == k)
            break;
        int fac = xx/x;
        // if(xx%x!=0)
        // {
        //     fac+=1;
        // }
        if(fac <=(k-count))
        {
            // cout<<"dd "<<xx<<endl;
            count+=fac;
            ans+=1;
        }
        
    }
    cout<<enddiff.size()-ans+1<<"\n";
    

        
    
}