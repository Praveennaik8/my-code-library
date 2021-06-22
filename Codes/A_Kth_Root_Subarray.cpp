// A Kth Root Subarray
// Max. score: 100
// The problem statement is simple.

// You are given an array A of N integers. You have to answer Q queries of three types.

// 1 L R            :   Determine if the subarray [ AL , AL+1 , AL+2 , .....   AR ] is special or not. 
// 2 L R X Y     :    Multiply all the elements of the subarray  [ AL , AL+1 , AL+2 , .....   AR ] by XY.
// 3 L R X        :    Reset all the elements of the subarray [ AL , AL+1 , AL+2 , .....   AR ] to value X.
// Let  = Product of the subarray [ AL , AL+1 , AL+2 , .....   AR ]

// A subarray is special if   is a integer . In other words the Kth root of product of the subarray should be a integer.

 

// Input Format
// First line contains three integers N K Q.

// Next line contains N integers A1 , A2 , A3 , .....   AN .

// Next Q lines contains one of the three types of queries.

 

// Constraints
// 1 <=  N <= 105
// 1 <= Q <= 5*104 ,
// 1 <= Ai , X , Y <= 106
// 1 <= L<=R <= N
// 1 <= K <= 30000
 

// Output
// For each query of type 1 , print Yes if the subarray is special else No

   

// SAMPLE INPUT 
// 11 2 9
// 2 2 2 2 2 2 2 2 2 2 3
// 1 10 11
// 1 4 7
// 3 5 6 3
// 1 4 7
// 2 3 5 3 1
// 1 3 6
// 3 5 5 3
// 1 3 6
// 1 2 6
// SAMPLE OUTPUT 
// No
// Yes
// Yes
// No
// Yes
// No
// Explanation
// Array during first query : A =  [ 2  2  2  2  2  2  2  2  2  2  3 ]

// A[10] * A[11] = 6 which doesnot have a integer square root.

// Array during second query : A =  [ 2  2  2  2  2  2  2  2  2  2  3 ]

// A[4] * A[5] * A[6] * A[7] = 16 which has a integer square root = 4

// Array after third query : A =  [ 2  2  2  2  3  3  2  2  2  2  3 ]

// For 4th query :

// A[4] * A[5] * A[6] * A[7] = 36 which has a integer square root = 6

// Array after 5th query : A = [ 2  2  6  6  9  3  2  2  2  2  3 ]

// For 6th query :

// A[3] * A[4] * A[5] * A[6] =  972 which doesnot have a integer square root

// Time Limit:	2.5 sec(s) for each input file.
// Memory Limit:	256 MB
// Source Limit:	1024 KB
// Marking Scheme:	Score is assigned if any testcase passes.
// Allowed Languages:	Bash, C, C++, C++14, C++17, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, Java 14, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, Python 3.8, Racket, Ruby, Rust, Scala, Swift-4.1, Swift, TypeScript, Visual Basic
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
#define int long long
#define vi vector<int>
#define vll vector<long long>
#define testcase int t; cin>>t ;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
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
#define SIZE ll(100005)//00002)
#define FAIL -5677884
#define BIT_SIZE 35
int lazy[SIZE] ={0};

void build_tree(int arr[],int seg_tree[],int low, int high,int seg_pos)
{
    if(low == high)
    {
        seg_tree[seg_pos] = arr[low];
        return;
    }
    ll mid = (low+high)/2;

    build_tree(arr,seg_tree,low,mid,2*seg_pos+1);
    build_tree(arr,seg_tree,mid+1,high,2*seg_pos+2);

    seg_tree[seg_pos] = seg_tree[2*seg_pos+1]*seg_tree[2*seg_pos+2];
}
void reset(int seg_tree[],int low, int high,int q_low,int q_high,int seg_pos,int val)
{
    if(q_low > high || q_high < low)//ql>high||qh<low
    {
        return;
    }
    if(low == high)
    {
        //lazy[seg_pos] = 0;
        seg_tree[seg_pos] =val;
        return;
    }
    ll mid = (low+high)/2;

    reset(seg_tree,low,mid,q_low,q_high,2*seg_pos+1,val);
    reset(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2,val);

    seg_tree[seg_pos] = seg_tree[2*seg_pos+1]*seg_tree[2*seg_pos+2];
    //lazy[seg_pos] = 0;
}
void update(int seg_tree[],int low, int high,int q_low,int q_high,int seg_pos,int val)
{
    
    
    
    if(q_low > high || q_high < low)//ql>high||qh<low
    {
        return;
    }
    if(low == high)
    {
        //lazy[seg_pos] = 0;
        seg_tree[seg_pos] = seg_tree[seg_pos] * val;
        return;
    }
    ll mid = (low+high)/2;

    update(seg_tree,low,mid,q_low,q_high,2*seg_pos+1,val);
    update(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2,val);

    seg_tree[seg_pos] = seg_tree[2*seg_pos+1]*seg_tree[2*seg_pos+2];
    //lazy[seg_pos] = 0;
}
// void update(int seg_tree[],int low, int high,int q_low,int q_high,int seg_pos )
// {
//     if(lazy[seg_pos]!=0)
//     {
//         int add =  lazy[seg_pos];
//         lazy[seg_pos] = 0;
//         if(low!=high)
//         {
//             lazy[2*seg_pos+1]+=add;
//             lazy[2*seg_pos+2]+=add;
//         }
//         seg_tree[seg_pos ]=seg_tree[seg_pos ]+10*add;
//     }
//     if(q_low <= low && q_high >= high)
//     {
//         seg_tree[seg_pos ]+=(high-low+1)*10;
//         if(low!=high)
//         {
//             lazy[2*seg_pos+1]++;
//             lazy[2*seg_pos+2]++;
//         }
//         return;
//     }
//     if(q_low > high || q_high < low)//ql>high||qh<low
//     {
//         return;
//     }
//     ll mid = (low+high)/2;

//     update(seg_tree,low,mid,q_low,q_high,2*seg_pos+1);
//     update(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2);

//     seg_tree[seg_pos] = seg_tree[2*seg_pos+1]+seg_tree[2*seg_pos+2];

// }

// int sum_query(int seg_tree[],int low,int high,int q_low,int q_high,int seg_pos)
// {
//     if(lazy[seg_pos]!=0)
//     {
//         int add =  lazy[seg_pos];
//         lazy[seg_pos] = 0;
//         if(low!=high)
//         {
//             lazy[2*seg_pos+1]+=add;
//             lazy[2*seg_pos+2]+=add;
//         }
//         seg_tree[seg_pos ]+=(high-low+1)*10*add;
//     }
//     if(q_low <= low && q_high >= high)
//     {
//         return seg_tree[seg_pos];
//     }
//     if(q_low > high || q_high < low)//ql>high||qh<low
//     {
//         return 0;
//     }
//     int mid  = (low + high) /2;

//     return sum_query(seg_tree,low,mid,q_low,q_high,2*seg_pos+1) + sum_query(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2);
// }
void printarr(int seg_tree[],int low, int high,int seg_pos)
{
    if(low == high)
    {
        cout<<seg_tree[seg_pos]<<"  ";
        return;
    }
    ll mid = (low+high)/2;

    printarr(seg_tree,low,mid,2*seg_pos+1);
    printarr(seg_tree,mid+1,high,2*seg_pos+2);

    //seg_tree[seg_pos] = seg_tree[2*seg_pos+1]*seg_tree[2*seg_pos+2];
}
int mul_query(int seg_tree[],int low,int high,int q_low,int q_high,int seg_pos)
{
    if(q_low <= low && q_high >= high)
    {
        return seg_tree[seg_pos];
    }
    if(q_low > high || q_high < low)//ql>high||qh<low
    {
        return 1;
    }
    int mid  = (low + high) /2;

    return mul_query(seg_tree,low,mid,q_low,q_high,2*seg_pos+1) * mul_query(seg_tree,mid+1,high,q_low,q_high,2*seg_pos+2);
}
ld kthRoot(ld n, int k) 
{ 
    return pow(k, 
               (1.0 / k) 
                   * (log(n) 
                      / log(k))); 
} 
 
signed main()
{
    fastio
    
    int n,k;
    cin>>n>>k;
    ll q;
    cin>>q;
    int arr[n+10];
    rep(i,n)
    {
        cin>>arr[i];
    }
    ll seg_tree[4*n];
    rep(i,4*n)
    {
        seg_tree[i] = 1;
    }
    build_tree(arr,seg_tree,0,n-1,0);//4N
    // rep(i,4*n)
    // {
    //     cout<<seg_tree[i]<<" ";
    // }
    cout<<"\n";
    ll a,b,pp;
    ld res; 
    while(q--)
    {
        ll x,l,h;
        cin>>x>>l>>h;
        l = l-1;
        h = h-1;
        
       // cout<<mul_query(seg_tree,0,n-1,l,h,0)<<"\n";
        switch(x)
        {     
            case 1:
                pp = mul_query(seg_tree,0,n-1,l,h,0);
                //cout<<l<<"  "<<h<<" =  "<<pp<<endl;

                res =kthRoot((ld)pp,k);
                //cout<<res<<endl;
                if(abs(res - trunc(res)) < 0.000001)
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
                break;
            case 2:
                cin>>a>>b;
                a = pow(a,b);
                // cout<<"power == "<<a<<endl;
                update(seg_tree,0,n-1,l,h,0,a);
                //cout<<"updated\n";
                break;
            case 3:
                cin>>a;
                reset(seg_tree,0,n-1,l,h,0,a);
                break;
        }
        // cout<<x<<" 7777  -";
        // rep(i,4*n)
        // {
        //     cout<<seg_tree[i]<<" ";
        // }
        // cout<<"\n";
        //log(N)
        // cout<<"\n";
        // printarr(seg_tree,0,n-1,0);
        // cout<<"\n";
    }
    
}