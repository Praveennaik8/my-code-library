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

//this function: = https://www.geeksforgeeks.org/how-to-turn-off-a-particular-bit-in-a-number/
int turnOffK(int n, int k) 
{ 
    return (n ^ (1 << (k-1)));  
} 
bool isKthBitSet(int n, int k) 
{ 
    if ((n >> (k - 1)) & 1) 
        return true; 
    return false; 
} 
void printarr(int arr[],int n,int k )
{
    cout<<k<<"--->  ";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    

}
main()
{
    fastio
    testcase
    {
        int n,k;
        cin>>n>>k;

        int arr[n+10];
        map<int,queue<int> >bit_map;
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
            cout<<arr[i]<<"  ";
            for(int j = 1;j<32 ; ++j)
            {
                // cout<<j<<endl;
                if(isKthBitSet(arr[i],j))
                {
                    cout<<j<<" , ";

                    bit_map[j].push(i);
                }
            }
            cout<<endl;
        }
        for(auto it = bit_map.begin();it!=bit_map.end();it++)
        {
            auto kkk = it->second;
            cout<<it->first<<"  ";
            while(!kkk.empty())
            {
                cout<<kkk.front()<<" ";
                kkk.pop();
            }
            cout<<endl;
        }
        // cout<<n<<" "<<k<<endl;
        for(int i = 0;i<n-1;i++)
        {
            if(k==0)
                break;
            for(int j = 31;j>0;--j)
            { 
                if(k==0)
                    break;
                if(isKthBitSet(arr[i],j))
                {
                    // cout<<i<<" "<<iter<<endl;
                    --k;
                    // cout<<"before  "<<arr[i]<<endl;
                    arr[i] = turnOffK(arr[i],j);
                    // cout<<"after  "<<arr[i]<<endl;
                    if(!bit_map[j].empty())
                    {
                        int p = bit_map[j].front();
                        bit_map[j].pop();
                        if(p <= i)
                        {
                            if(!bit_map[j].empty())
                            {
                                int p = bit_map[j].front();
                                bit_map[j].pop();
                                // cout<<"before  "<<arr[p]<<endl;
                                arr[p]= turnOffK(arr[p],j);
                                // cout<<"after  "<<arr[p]<<endl;
                            }
                            else
                            {
                                // cout<<"before  "<<arr[n-1]<<endl;
                                arr[n-1] = turnOffK(arr[n-1],j);
                                // cout<<"after  "<<arr[n-1]<<endl; 
                            }
                            
                        }
                        else
                        {
                            // cout<<"before  "<<arr[p]<<endl;
                            arr[p]= turnOffK(arr[p],j);
                            // cout<<"after  "<<arr[p]<<endl; 
                        }
                        
                        
                    }
                    else
                    {
                        // cout<<"before  "<<arr[n-1]<<endl;
                        arr[n-1] = turnOffK(arr[n-1],j);
                        // cout<<"after  "<<arr[n-1]<<endl; 
                    }
                    printarr(arr,n,k);
                    
                }
            }
        }
        for(auto it = bit_map.begin();it!=bit_map.end();it++)
        {
            auto kkk = it->second;
            cout<<it->first<<"  ";
            while(!kkk.empty())
            {
                cout<<kkk.front()<<" ";
                kkk.pop();
            }
            cout<<endl;
        }
        if(k>0&&k%2)
        {
            arr[n-2] ^= 1;
            arr[n-1] ^=1;
        }
        for(int i = 0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";


        
    }
}