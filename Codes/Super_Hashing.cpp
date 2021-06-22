#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
const ll mod = 1e9 + 7;


using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    return out;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}

ll dp[54][54][1400];
int s,l;

ll solve(int index, int left, int sum)
{
	if(index==53)
		return left==0 && sum==s;
	if(sum==s)
		return left==0;
	if(sum>s)
		return 0;
	if(dp[index][left][sum]!=-1)
		return dp[index][left][sum];

	dp[index][left][sum]=solve(index+1, left-1, sum+index)+solve(index+1, left, sum);	

	return dp[index][left][sum];
}

int main()	
{
	#ifdef SANS
		freopen("ongoingin.txt","r",stdin);
		freopen("ongoingout.txt","w",stdout);
	#endif
	fast
	int t, tt=1;
	cin>>t;
	while(t--)
	{
		cin>>l>>s;
		if(l>52)
		{
			cout<<"Case "<<tt<<": "<<0<<endl;
			tt++;
			continue;
		}
		memset(dp,-1,sizeof(dp));
		cout<<solve(1,l,0)<<endl;
		tt++;
	}
	#ifdef SANS
		cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
	#endif
}