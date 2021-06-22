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

map<int,vector<string> > substrings;
void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
void subString(string str, int n) 
{
    // Pick starting point
    for (int len = 1; len <= n; len++) 
    {    
        // Pick ending point
        for (int i = 0; i <= n - len; i++) 
        {
            //  Print characters from current
            // starting point to current ending
            // point.  
            string s= "";
            int j = i + len - 1;            
            for (int k = i; k <= j; k++) 
                s+=str[k];
            substrings[j-i+1].push_back(s);
        }
    }
}

bool check(string rev)
{
    int one = 0;
    for(auto it:rev)
    {
        if(it=='1')
            one++;
    }
    
    return one%2==0;
}
signed main()
{
    fastio
    testcase
    {
        substrings.clear();
        string str;
        cin>>str;
        subString(str,str.size());
        map<string,int>found;
        int cnt = 0;
        for(auto it = substrings.begin();it!=substrings.end();it++)
        {
            // cout<<it->first<<"  ->  ";
            for(auto j = it->second.begin();j!=it->second.end();j++)
            {
                string new1 = *j,rev = *j;
                if(check(rev))
                    reverse(all(rev));
                if(!found[new1]&&!found[rev])
                {
                    ++cnt;
                    found[new1]++;
                }
            }
            // cout<<endl;
        }
        cout<<cnt<<endl;

    }
}