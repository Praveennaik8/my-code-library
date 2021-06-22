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
    fastio
    testcase
    {
        int n,k;
        cin>>n>>k;
        int arr[n+10];
        rep(i,n)
            cin>>arr[i];
        int rem = 0,i;
        for( i = 0;i<n;i++)
        {
            rem+=arr[i];
            if(rem<k)
                break;
            rem-=k;
        }
        if(i!=n)
            ++i;
        if(rem>k)
        {
            int x = rem/k;
            i+=(x+1);
        } 
        
        cout<<i<<'\n';
    }
}

map<int,int> diffx,diffy;
void uniquex(vector<int> arr,int n) 
{ 
    //diffx.clear();
    int i = 0; 
    for(i  = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            diffx[abs(arr[i] - arr[j])]++;
        }
    } 
} 
void uniquey(vector<int> arr,int n) 
{ 
    //diffy.clear();
    int i = 0; 
    for(i  = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            diffy[abs(arr[i] - arr[j])]++;
        }
    } 
} 
void uniquey2(vector<int>arr,int n,int x)
{
    int i = 0; 
    for(i  = 0;i<arr.size();i++)
    {
        diffy[abs(arr[i] - x)]++;
        
    } 
}
int count()
{
    int cnt = 0;
    for(auto x : diffy)
    {
        if(diffx[x.first]==MARK&&x.first > 0)
            cnt++;
    }
    return cnt;
}
// Driver program to run the case 
main() 
{ 
    int H,W,n,m,temp;
    cin>>W>>H>>n>>m;
    vector<int>xxxx,yyyy;
    map<int,int>existyyyyy,backup;
    for(int i = 0;i<n;i++)
    {
        cin>>temp;
        xxxx.push_back(temp);
        //frqx[temp] = MARK;
    }   
    for(int i = 0;i<m;i++)
    {
        cin>>temp;
        yyyy.push_back(temp);
        existyyyyy[temp] = MARK;
    }
        
    uniquex(xxxx,n);
    uniquey(yyyy,m);
    int ans = count();
    // cout<<"--------\n";
    // for(auto x:diffx)
    //     cout<<x.first<<"  ";
    // cout<<endl;
    // cout<<"--------\n";

    // for(auto x:diffy)
    //     cout<<x.first<<"  ";
    // cout<<endl;
    // cout<<ans<<endl;
    for(int i = 0;i<=H;i++)
    {
        if(existyyyyy[i]!=MARK)
        {
            backup = diffy;
            ////yyyy.push_back(i);
            uniquey2(yyyy,m,i);
            ans = max(ans,count());
            diffy = backup;
            //yyyy.pop_back();
        }
    }
    cout<<ans<<"\n";
    
    
    return 0; 
} 