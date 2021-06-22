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
#define SIZE ll(100005)
#define FAIL -5677884
#define BIT_SIZE 35

signed main()
{
    fastio
    testcase
    {
        int n;
        cin>>n;
        string num;
        cin>>num;
        int ans =2;
        bool rage = false,breach = false;
        for(int i = 0;i<num.size();i++)
        {
            if((i+1)%2&&num[i]%2)
                rage = true;
            else if((i+1)%2==0&&num[i]%2==0)
                breach = true;
        }
        if(n%2&&rage||n%2==0&&!breach)
            cout<<"1"<<"\n";
        else
        {
            cout<<"2"<<"\n";
        }
        

    }
}