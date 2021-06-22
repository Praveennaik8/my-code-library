#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define MOD 1000000007
typedef long double ld;
typedef long long ll;
#define SIZE ll(10000)//00002)
#define FAIL -5677884

void solveme()
{ 
    int n,m;
    cin>>n>>m;
    int mat[n+1][m+1];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i = 0;i<m;i++)
        cout<<"1";
    cout<<"\n";
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            ll x = mat[i][j];
            if(j==0)
                mat[i][j] = max(max(mat[i-1][j],mat[i-1][j+1]),mat[i][j]);
            else if(j==m-1)
                mat[i][j] = max(max(mat[i-1][j],mat[i-1][j-1]),mat[i][j]);
            else
                mat[i][j] =max( max(max(mat[i-1][j],mat[i-1][j-1]),mat[i-1][j+1]),mat[i][j]);
            if(x!=mat[i][j])
                cout<<"0";
            else
                cout<<"1";
        }
        cout<<"\n";
    }
    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = 0;j<m;j++)
    //     {
    //         cout<<mat[i][j]<<"  ";
    //     }
    //     cout<<"\n";
    // }
}
signed main()
{
    fastio
    test
        solveme();
}