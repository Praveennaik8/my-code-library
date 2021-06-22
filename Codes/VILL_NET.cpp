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

ll ini_x,ini_y,final_x,final_y;
ll min_ans = INF;


void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}

ll dfs_method1(ll cur_x,ll cur_y,ll depth)
{
    if(depth > 20||depth>=min_ans)
        return INF;
    
    if(cur_x == final_x&&cur_y == final_y)
    {
        min_ans = min(min_ans,depth);
        return depth;
    }
    if(sqrt(pow((abs(final_x)-abs(cur_x)),2)+pow((final_y-cur_y),2))>20)
        return INF;
    ll part1 = min(dfs_method1((cur_x+2*cur_y),cur_y,depth+1),dfs_method1((cur_x-2*cur_y),cur_y,depth+1));
    ll s,n;
    if((cur_y+2*cur_x)>0)
        s = dfs_method1(cur_x,cur_y+2*cur_x,depth+1);
    else
        s = dfs_method1(-1*cur_x,-1*(cur_y+2*cur_x),depth+1);
    if((cur_y-2*cur_x)>0)
        n = dfs_method1(cur_x,cur_y-2*cur_x,depth+1);
    else
        n = dfs_method1(-1*cur_x,-1*(cur_y-2*cur_x),depth+1);
    return min(part1,min(n,s));
}

ll dfs_method2(ll cur_x,ll cur_y,ll depth)
{
    if(depth > 7)
        return INF;
    if(cur_x == final_x&&cur_y == final_y)
        return depth;
    ll part1 = min(dfs_method2((cur_x+2*cur_y),cur_y,depth+1),dfs_method2((cur_x-2*cur_y),cur_y,depth+1));
    ll s,n;
    if((cur_y+2*cur_x)>0)
        s = dfs_method2(cur_x,cur_y+2*cur_x,depth+1);
    else
        s = dfs_method2(-1*cur_x,-1*(cur_y+2*cur_x),depth+1);
    if((cur_y-2*cur_x)>0)
        n = dfs_method2(cur_x,cur_y-2*cur_x,depth+1);
    else
        n = dfs_method2(-1*cur_x,-1*(cur_y-2*cur_x),depth+1);
    return min(part1,min(n,s));

}
signed main()
{
    fastio
    testcase
    {
        min_ans = INF;
        cin>>ini_x>>ini_y>>final_x>>final_y;
        if(max(ini_x,final_x)<11&&min(ini_x,final_x)>-11&&max(ini_y,final_y)<11&&min(ini_y,final_y)>-1)
            cout<<dfs_method1(ini_x,ini_y,0)<<"\n";
        else
            cout<<dfs_method2(ini_x,ini_y,0)<<"\n";
        
    }
}
