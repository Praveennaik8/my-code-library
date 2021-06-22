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

signed main()
{
    fastio
    testcase
    {
        int n,m;
        cin>>n>>m;
        int arr[n+10][4];
        rep(i,n)
        {
            rep(j,4)
            {
                cin>>arr[i][j];
            }
        }
        // rep(i,n)
        // {
        //     rep(j,4)
        //     {
        //         cout<<arr[i][j]<<" ";
        //     }
        // }
        bool flag = false;
        if(m%2)
        {
            flag =false;
        }
        else 
        {
            rep(i,n)
            {
               // cout<<"entered\n";
                if(arr[i][1]==arr[i][2])
                {
                    //cout<<"Success\n";
                    flag =true;
                    break;
                }
            }
        }
        if(flag)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
}