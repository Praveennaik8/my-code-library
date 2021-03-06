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
int maxor = 0;
vector<int>ans;



void combinationUtil(int arr[], int data[],
					int start, int end,
					int index, int r);

void printCombination(int arr[], int n, int r)
{
	int data[r];

	combinationUtil(arr, data, 0, n-1, 0, r);
}

/* arr[] ---> Input Array
data[] ---> Temporary array to
store current combination
start & end ---> Staring and
Ending indexes in arr[]
index ---> Current index in data[]
r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[],
					int start, int end,
					int index, int r)
{
	if (index == r)
	{
        int temp = data[0];
		for (int j = 1; j < r; j++)
			temp^= data[j] ;
		if(temp>maxor)
        {
            maxor = temp;
            rep(i,r)
                ans[i] = data[i];
        }
		return;
	}

	for (int i = start; i <= end &&
		end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,
						end, index+1, r);
	}
}

signed main()
{
    fastio
    testcase
    {
        maxor = 0;
        int n,k;
        cin>>n>>k;
        int arr[n+10];
        ans.clear();
        ans.resize(k+1);
    
        rep(i,n)
            arr[i] = i+1;
        printCombination(arr, n, k);
        rep(i,k)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
	
}

