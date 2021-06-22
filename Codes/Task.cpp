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
#define int long long
int n,a,x;

signed main()
{
    fastio
    test
    {
        int l,r;
        cin>>l>>r;
        // cout<<l<<r<<endl;
        int ans = 0;
        int factor;
        for(int i= 1;i<=sqrt(r);i++)
        {
            factor = round(((ld)((ld)(l-i*i)/(ld)(i*2)))+0.5);
            // factor = (int)((ld)(((ld)(l)-(ld)(i*(ld)i))/(ld)(i*2))+0.5);
            cout<<"fact "<<factor<<endl;
            factor+=1;
            if(factor<0)
            {
                if(r<i*i)
                    break;
                
                ans+=(int)((r-i*i)/i*2 +1);
            }
            else
            {
                ans+=(int)((r-i*i)/(i*2) +1) - factor+1;
            }
            cout<<i<<" --> "<<factor<<" "<<(int)((r-i*i)/(i*2) +1) <<" "<<ans<<endl;
            
        }
        cout<<ans<<endl;

    }
    
    
}
