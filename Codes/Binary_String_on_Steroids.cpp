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
        string binary;
        cin>>n>>binary;
        
        int lasti = -1;
        int diff = -1;
        bool flag = true;
        int count=0;
        int onecount = 0;
        vector<int>diffarr;
        for(int i=0;i<n;i++)
        {
            // cout<<"ii\n";
            if(binary[i] == '1')
            {
                onecount+=1;
                if(lasti==-1)
                    lasti=i;
                else if(diff!=0){

                    if(diff == -1)
                    {
                        diff = i - lasti-1;
                        diffarr.push_back(i - lasti-1);
                    }
                    else
                    {
                        if(i - lasti-1 == 0)
                        {
                            diff = 0;
                            continue;
                        }
                        if((i - lasti-1) % diff == 0|| diff % (i-lasti-1) == 0)
                        {
                            int tempx = min(diff,i-lasti-1);
                            int tempm = max(diff,i-lasti-1);
                            count += tempm/tempx;
                            diff = tempx;
                            diffarr.push_back(i - lasti-1);
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    lasti = i;
                }
            }
        }
        // cout<<"ddd"<<diff<<endl;
        if(diff == 0)
            flag = false;
        else if(n%diff)
            flag = false;
        if(flag)
        {
            // cout<<"ddd"<<diff<<endl;
            int count = 0;
            for(auto x:diffarr)
            {
                // cout<<x<<endl;
                if(diff!=0 && diff!= x)
                    count+=x/diff;
            }
            cout<<count<<endl;
        }
        else
        {
            cout<<n-onecount<<endl;
        }
        
    }
}

