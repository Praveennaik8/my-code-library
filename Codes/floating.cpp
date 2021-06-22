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
#define float long double
int n,a,x;
bool approximatelyEqual(float a, float b, float epsilon)
{
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool essentiallyEqual(float a, float b, float epsilon)
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyGreaterThan(float a, float b, float epsilon)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(float a, float b, float epsilon)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
signed main()
{
    fastio
    int b,c;
    ld a;
    cin>>a>>b>>c;
    ld ans = 1.0;
    int cnt = 0;
    if(a<1)
    {
        ans = ans+(ld)((ld)b*(ld)c);
        ans = log2(ans);
    }
    else
    {
        while(cnt<c&&definitelyLessThan(ans*a,ans+b,0.00000000000001))
        {
            ans+=(b);
            cnt+=1;
        }
        if(c-cnt+1>0)
        {
            // ans= ans*(pow(a,(ld)(a)*(ld)(c-cnt)));
            ans = log2(ans)+log2(c-cnt+1)*log2(a);
        }
        else{
            ans = log2(ans);
        }
            
    }
    
    cout<<fixed<<setprecision(10)<<ans<<endl;

    
}
