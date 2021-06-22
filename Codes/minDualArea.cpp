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
int getArea(vector<pair<int,int> >points,int n)
{
    sort(all(points));
    int reverseMin[n+10],reverseGrt[n+10];
    reverseMin[n] = LLONG_MAX,reverseGrt[n] = 0;
    for(int i = points.size()-1; i >=0;i--)
    {
        reverseGrt[i] = max(reverseGrt[i+1],points[i].second);
        reverseMin[i] = min(reverseMin[i+1],points[i].second);
    }
    int minWidth = LLONG_MAX,maxWidth = 0,height1,height2,area = LLONG_MAX;
    for(int i = 0;i<points.size()-1;i++)
    {
        int temp = points[i].first;
        int start = points[i].second;
        // int end = start;
        // while(points[i].first == temp)
        // {
        //     end = points[i].second;
        //     ++i;
        // }
        // if(i>=points.size())
        // {
        //     break;
        // }
        minWidth = min(minWidth,start);
        maxWidth = max(maxWidth,start);
        int width1 = maxWidth - minWidth;
        int width2 = reverseGrt[i+1] - reverseMin[i+1];
        height1 =  temp - points[0].first; 
        height2 = points[points.size()-1].first - points[i+1].first;
        // cout<<width1<<" "<<height1<<" "<<width2<<" "<<height2<<endl;
        int tempArea = width1*height1+height2*width2;
        area = min(area,tempArea);
    }
    return area;
}
signed main()
{
    fastio
    testcase
    {
        int n;
        cin>>n;
        vector<pair<int,int> > points1,points2;
        int x,y;
        rep(i,n)
        {
            cin>>x;
            cin>>y;
            points1.push_back(make_pair(x,y));
            points2.push_back(make_pair(y,x));
        }
        int area = getArea(points1,n);
        area  = min(area,getArea(points2,n));
        if(area == LLONG_MAX)area = 0;
        cout<<area<<endl;
    }
}