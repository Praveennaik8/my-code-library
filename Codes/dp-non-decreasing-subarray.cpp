#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

typedef long double ld;
typedef long long ll;


signed main()
{
    fastio
    test
    {
        ll n;
        cin>>n;
        ll arr[n+10];
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        vi v1;
        ll count = 1;
        ll sum = n;
        for(int i = 1;i < n;i++)
        {
            if(arr[i]>=arr[i-1])
            {
                count++;
                if(i==n-1&&count !=1)
                    sum += count*(count+1)/2-count;
            }
            else
            {
                if(count !=1)
                    sum += count*(count+1)/2-count;
                
                count = 1;
            }
        }
        // if(arr[n-1]>=arr[n-2]&&count)
        // {
        //     v1.push_back(count);
        // }
        
        // ll sum = 0;
        // for(auto x:v1)
        // {
        //     sum += (int)(pow(2,x)+0.5)-x-1;
        //    cout<<x<<endl;
        // }
        
        cout<<sum<<endl;



        
        

        
    }
}

// 2
// 4
// 1 4 2 3 
// 1 3 1 3

// 1 2 3 4
// 1 3 
// 2^n -1


// 1
// 5