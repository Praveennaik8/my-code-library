#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
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
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35

int setBitNumber(int n) 
{ 
    if (n == 0) 
        return 0; 
        
    int msb = 0; 
    n = n / 2; 
    while (n != 0) { 
        n = n / 2; 
        msb++; 
    } 
  
    return (1 << msb); 
} 

signed main()
{
    fastio
    testcase
    {
        int n;
        cin>>n;
        int arr[n+10];
        map<ll,ll>cnt;
       // map<ll,ll> mapp;
        rep(i,n)
        {
            cin>>arr[i];
            //mapp[arr[i]]++;

            // if(mapp[arr[i]]<=2)
                cnt[setBitNumber(arr[i])]++;
        }
        int sum = 0;
        for(auto x:cnt)
        {
            sum+= (((x.second)*(x.second-1))/2);
        }
        cout<<sum<<endl;

    }
}