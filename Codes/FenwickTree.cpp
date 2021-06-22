#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define SIZE (ll)100000 
vector<int>BIT;
void update(int x,int val)
{
    for(int i = x;i<BIT.size();i += (i&-i))
        BIT[i] += val;

}
int query(int x)
{
    int sum = 0;
    for(int i = x;i>0;i-=(i&-i))
        sum+=BIT[i];
    return sum;
}
signed main()
{
    int n;
    cin>>n;
    vector<int>arr(n+10);
    BIT.resize(n+1,0);
    for(int i = 1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,arr[i]);
    }
    int q;
    cin>>q;
    int l,r;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }

}