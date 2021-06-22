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
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
vector<pair<int,int> > abpair;
int minel = LLONG_MAX,bought = 0,coin = 0;
int flag = false;
int n,a,b;
template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
void randomfunction()
{
    // cout<<"hellom\n";
    flag = false;
    for(int i = abpair.size()-1;i>=0;i--)
    {
        if(minel <= bought)
            break;
        if(minel>= bought+ abpair[i].first)
        {
            coin += abpair[i].first*2;
            bought+=abpair[i].first;
            abpair[i].first = 0;
            abpair.pop_back();
        }
        else
        {
            int temp = minel - bought;
            coin+= temp*2;
            bought+= temp;
            abpair[i].first -= temp;
        }
    }

    // cout<<"hellom\n";
    if(minel<=bought)
        flag = true;
    return ;
}
signed main()
{
    // fastio

    cin>>n;

    rep(i,n)
    {
        cin>>a>>b;
        abpair.push_back(mp(a,b));
    }
    sort(all(abpair),cmp);
    
    // for(auto x:abpair)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    // cout<<"hello\n";
    minel = abpair[0].second;
    // cout<<"hello\n";
    coin = 0;
    bought = 0;
    
    for(auto x :abpair )
    {
        if(bought<x.second)
        {
            minel = x.second;
            randomfunction();
            if(flag)
            {
                coin+=x.first;
                bought+=x.first;
                x.first = 0;
                pop_front(abpair);
            }
            else
            {
                coin+=x.first*2;
                x.first = 0;
                bought+=x.first;
                pop_front(abpair);
            }
        }
        else
        {
            coin+=x.first;
            bought+=x.first;
            x.first = 0;
            pop_front(abpair);
        }
        
        // cout<<x.second<<endl;

    }
    // for(auto x:abpair)
    // {
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    // cout<<"hellom\n";
    cout<<coin<<endl;

}