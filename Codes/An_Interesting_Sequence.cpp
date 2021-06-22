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
// fstream new_file; 

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
    // new_file.open("answer.txt",ios::out);
    testcase
    {
        int k;
        cin>>k;
        // int dp[2*k+2];
        // for(int i = 1;i<=2*k+1;i++)
        //     dp[i] = k+i*i;
        // 1 to 7
        // 2 to 20

        int sum = 0,prev = 1,curr;
        for(int i = 2;i<=2*k+1;i++)
        {
            curr = i*i;
            // cout<<dp[i-1]<<"  "<<dp[i]<<" = ";
            // int gc = __gcd(dp[i-1],dp[i]);
            // cout<<k+prev<<" "<<curr-prev<<" = ";
            int gc = __gcd(k+prev,curr-prev);
            // cout<<gc<<endl;
            sum+=gc;
            prev = curr;
        }
        cout<<sum<<endl;
        // cout<<zz<<endl;
        // string ans = "";
        // ans+="ans["+to_string(k)+"] = "+to_string(sum)+"; ";
        // new_file<<ans;
        
    }
    // new_file.close();
}