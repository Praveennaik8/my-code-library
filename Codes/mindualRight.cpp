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
    // fastio
    testcase
    {
        int n;
        cin>>n;
        vector<pair<int,int> >x,y;
        multiset<int>X,Y;
        int a,b;
        rep(i,n)
        {
            cin>>a>>b;
            x.push_back(mp(a,b));
            y.push_back(mp(b,a));
            X.insert(a);
            Y.insert(b);
        }
        sort(all(x));
        sort(all(y));
        print();
        int maxh1 = 0,minh1 = INF,h1 = 0,h2 = 0,area = INF;
        rep(i,n)
        {
            maxh1 = max(maxh1,x[i].second);
            minh1 = min(minh1,x[i].second);
            h1 = maxh1 - minh1;
            auto it = Y.find(x[i].second);
            if(it!=Y.end())
                Y.erase(it);
            if(Y.empty())
                h2 = 0;
            else
                h2 = *(Y.rbegin()) - *(Y.begin());
            int newArea = (x[i].first - x[0].first)*h1+(x[n-1].first - x[i+1].first)*h2;
            area = min(area,newArea);
        }
        if(area ==INF)
            area = 0;
        cout<<area<<endl;


        
    }
}