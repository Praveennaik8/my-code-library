
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
vector<int>subarray[10000];
int cur_index = -1;
void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
int setBitNumber(int n) 
{ 
    n |= n >> 1; 
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    // Increment n by 1 so that 
    // there is only one set bit 
    // which is just before original 
    // MSB. n now becomes 1000000000 
    n = n + 1; 
  
    // Return original MSB after shifting. 
    // n now becomes 100000000 
    return (n >> 1); 
} 
// Prints all subarrays in arr[0..n-1] 
void subArray(int arr[], int n) 
{ 
    // Pick starting point 
    for (int i=0; i <n; i++) 
    { 
        // Pick ending point 
        for (int j=i; j<n; j++) 
        { 
            // Print subarray between current starting 
            // and ending points 
            ++cur_index;
            for (int k=i; k<=j; k++) 
            {
                subarray[cur_index].pb(arr[k]);
            }
  
            //cout << endl; 
        } 
    } 
}
int recur(map<int,vector<int> > mapfrq,map<int,vector<int> >::reverse_iterator it,int n)
{
    if(it == mapfrq.rend())
        return 0;
    if(it->first < 1)
        it->second.size()%2;

    int sz = it->second.size();
    if(sz %2 )
        return it->first;
    // if(n-sz>=sz)
    //     return 0;
    int xor1 = 0;
    for(int i = 0;i<it->second.size();i++)
    {
        cout<<it->second[i]<<endl;
        xor1^=it->second[i];
    }
    mapfrq[setBitNumber(xor1)].push_back(xor1);
    it++;
    recur(mapfrq,it,n);
    
} 
int cur_min = INT_MAX;
int least_xor(vector<int> arr)
{
    if(cur_min== 0 )
        return 0;

    map<int,int > newmap;
    for(auto x: arr)
    {
        newmap[setBitNumber(x)]++;
    }
    if(  newmap[*max_element(all(arr))]%2)
        return cur_min=min(setBitNumber(*max_element(all(arr))),cur_min);

//     // for(auto x = newmap.rbegin();x!=newmap.rend();x++)
//     // {
//     //     int sz = x->second.size();
//     //     if(sz%2)return x->first;
//     //     if(arr.size()-sz>=sz)
//     //         return 0;
//     //     newmap[1].push_back(1);
//     // }'
//     auto x = newmap.rbegin();

//     return recur(newmap,x,arr.size());
//     // auto it = newmap.rbegin();
//     // int add = 0;
//     // for(;it!=newmap.rend();it++)
//     // {
//     //     it->second+=add;
//     //     if(it->second%2 == 0)
//     //         break;
        
//     //     add =1;
//     // }
//     // sort(arr.begin(),arr.end());//,greater<>());
//     // while(arr.size()>1)
//     // {
//     //     int i  = arr[arr.size()-1];
//     //     int j = arr[arr.size()-2];
//     //     arr.pop_back();
//     //     arr.pop_back();
//     //     arr.push_back(setBitNumber(i^j));

//     // }
//    // return arr[0];//setBitNumber(sum_xor);
    if(arr.size()==1)
        return cur_min = min(cur_min, arr[0]);
    int ans = INT_MAX;
    //print(arr.size());
    rep(i,arr.size()-1)
    {
        repA(j,i+1,arr.size()-1)
        {
            vector<int>new1 = arr;
            //print(arr[i],arr[i]);
            
            new1.push_back(setBitNumber(arr[i]^arr[j]));
            new1.erase(find(all(new1),arr[i]));
            new1.erase(find(all(new1),arr[j]));
            
            ans = min(least_xor(new1),ans);
            if(ans == 0)
                return 0;
            //arr = new1;
        }
    }
    return cur_min = min(cur_min, ans);

}
void printarr(vector<int> arr)
{
    for(auto x : arr)
    {
        cout<<x<<"  ";
    }
    cout<<"\n";
}
int sumcal(vector<int> vv)
{
    int sum = 0;
    for(auto x:vv)
        sum+=x;
    return sum;
}
signed main()
{
    //fastio
    
    int n;
    cin>>n;
    int arr[n+10];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    //print();
    subArray(arr,n);
    ////print();
    

    mpl mpbit;
    int sum = 0;

    // for(int i = 0;i<n;i++)
    // {
    //    mpbit[setBitNumber(arr[i])] = arr[i];
    // }
    for(int i = 0;i<=cur_index;i++)
    {
        cur_min = INT_MAX;
        // if(sumcal(subarray[i])==45)
        //  sum+=0;
            
        //if(subarray[i].size()<n){
     printarr(subarray[i]);
        sum+=least_xor(subarray[i]);
        cout<<least_xor(subarray[i])<<endl;
        //}
    }
    cout<<sum<<endl;//<<cur_index<<endl;
    // while(1)
    // {

    // }
    
}
