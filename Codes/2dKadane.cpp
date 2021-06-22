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
int mat[1001][1001];
int start,ending;
int n,m;
int result;
int leftcol,rightcol,toprow,bottomrow;
int kadanes(int arr[],int n)
{
    int temp = 0,max_sum = 0;
    ending = -1;
    start = 0;
    for(int i = 0;i < n;i++)
    {
        
        temp+=arr[i];
        if(temp < 0 )
        {
            start = i+1;
            ending = i+1;
            temp = 0;
        }
        if(max_sum<temp)
        {
            max_sum = temp;
            ending = i;
        }
    }
    if(ending != -1)
        return max_sum;
    max_sum = -99999999999;
    rep(i,n)
    {
        if(max_sum<arr[i])
        {
            max_sum = arr[i];
            start = i;
            ending = i;
        }
    }
    return max_sum;
}
int get_max()
{
    int max_sum = -9999999999;
    

    for(int i = 0;i<m;i++)
    {
        int temp[n+10] ;
        rep(x,n)
            temp[x] = 0;
        
        for(int j = i;j<m;j++)
        {
            rep(x,n){
                temp[x]+=mat[x][j];
                // cout<<temp[x]<<" ";
            }
            // cout<<endl;
            int sum = kadanes(temp,n);
            // cout<<"res "<<sum<<endl;
            if(sum>max_sum)
            {
                max_sum = sum;
                leftcol = i;
                rightcol = j;
                toprow = start;
                bottomrow = ending;
            }
        }
        
    }
    result = max_sum;
    return max_sum;
}
signed main()
{
    fastio
    
    cin>>n>>m;

    rep(i,n)
        rep(j,m)
            cin>>mat[i][j];

    cout<<get_max()<<endl;
    int max_sum = result;
    for(int i = leftcol;i<=rightcol;i++)
    {
        for(int j = toprow;j<=bottomrow;j++)
        {
            if(mat[j][i]<0)
            {
                max_sum+=abs(mat[i][j]);
            }
        }
    }
    cout<<max_sum<<endl;
}