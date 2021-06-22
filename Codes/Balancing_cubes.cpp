#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define test int t;cin>>t;while(t--)
#define endl "\n"
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int main()
{
    //fastio
    int n;
    cin>>n;
    int cnt = 0;
    while(n>1)
    {
        if(n==2)
        {
            ++cnt;
            break;
        }
        ll x=n/3;
        // // if(n+1==(x+1)*3)
        // // {
        // //     x = x+1;
        // // }
        // if(n==8)
        // {
        //     cnt+=2;
        //     break;
        // }

        ll y=n-2*x;
       // cout<<x<<" "<<y<<endl;
      // cout<<x<<"  "<<y<<"  "<<n<<endl;
        ll a,b;
        a = x+1;
        b = n-2*a;
        n = min(max(x,y),max(a,b));

        
        
        ++cnt;
    }
    cout<<cnt<<"\n";
}
