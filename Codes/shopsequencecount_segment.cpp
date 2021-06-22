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

void update(int index, int value, vector<int>& tree, int size) {
    index += size;  
    tree[index] += value;
    while (index > 1) {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}


int query(int left, int right, vector<int>& tree, int size) {
   
    int result = 0;
    left += size;  
    right += size;
    while (left < right) {
        
        if (left % 2 == 1) {
            result += tree[left];
            left++;
        }
        left /= 2; 
        if (right % 2 == 1) {
            right--;
            result += tree[right];
        }
        right /= 2;
    }
    return result;
}

int countSmaller(vector<int>& nums) {
    int sum = 0 ;   
    int size = 100000 + 1;  
    vector<int> tree(size * 2);
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        int smaller_count = query(0, nums[i], tree, size);
        sum+=smaller_count;
        update(nums[i] , 1, tree, size);
    }
    
    return sum;
}
signed main()
{
    fastio
    testcase
    {
        int n,temp;
        cin>>n;

        vector<int> arr;
        rep(i,n){
            cin>>temp;
            arr.push_back(temp);
        }
        int max_sum = countSmaller(arr);
        cout<<max_sum<<endl;
        if(max_sum>=n)
            cout<<"YES\n";
        else
            cout<<"NO\n";   
    }
}