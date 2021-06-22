// Count K-Primes Problem Code: KPRIME
// Add problem to Todo list
// Submit

 
// Alice and Bob are studying for their class test together. The topic of the test is Prime Numbers. The preparation is getting too boring for their liking. To make it interesting, they turn it into a game. The winner will get an ice-cream treat from the other.

// The game is called Count K-Primes. A number is a k-prime if it has exactly k distinct prime factors. The game is quite simple. Alice will give three numbers A, B & K to Bob. Bob needs to tell Alice the number of K-prime numbers between A & B (both inclusive). If Bob gives the correct answer, he gets a point. If not, Alice gets a point. They play this game T times.

// Bob hasn't prepared so well. But he really wants to win the game. He wants you to tell him the correct answer.

// Input
// First line of input contains a single integer T, the number of times they play. Each game is described in a single line containing the three numbers A,B & K.

// Output
// For each game, output on a separate line the number of K-primes between A & B.

// Constraints:
// 1 ≤ T ≤ 10000
// 2 ≤ A ≤ B ≤ 100000
// 1 ≤ K ≤ 5

// Example:
// Input
// 4
// 2 5 1
// 4 10 2
// 14 15 2
// 2 20 3

// Output
// 4
// 2
// 2
// 0


#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define test int t;cin>>t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define MOD 1000000009
typedef long double ld;
typedef long long ll;
#define SIZE 100002


signed main()
{
    fastio
    vi prime;
    map<ll,ll>mprime;
    prime.push_back(2);
    for (int i = 3; i <= SIZE; i = i + 2) { 
        bool flag = 1; 
        for (int j = 2; j * j <= i; ++j) { 
            if (i % j == 0) { 
                flag = 0; 
                break; 
            } 
        } 
        if (flag == 1) 
        {
            prime.push_back(i);
            mprime[i]=1;
        }
            
    }
   
    ll dp[SIZE+10][6];
    for(int i = 1;i<6;i++)
    {
        dp[0][i] = 0;
        dp[0][i] = 0;
    }

    ll dpcount[SIZE+100]={0};

    for (int i = 0; i<prime.size(); i++)
    {
        dpcount[prime[i]]=1;
        for(ll j = 2*prime[i];j<SIZE;)
        {
            dpcount[j]++;
            j = j+prime[i];
        }
    }
    for(int i = 1;i<SIZE;i++)
    {
        for(int j =1 ;j<=5;j++)
        {
            if(j == dpcount[i])
            {
                dp[i][j] =1+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }
    test
    {
        ll a,b,k;
        cin>>a>>b>>k;
        ll r = max(a,b);
        ll l = min(a,b);
        cout<<dp[r][k]-dp[l-1][k]<<"\n";
    }
}


// 2 3 5 7 11 13 17 19 21



// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
// 0 1 1 1 1 2 1 1 1 02 01 02 01 02 02 01 01 01 01 02 02
// 0 1   1   2   1   2      1     2    1   2    1
// #include<bits/stdc++.h>
// using namespace std;
// #define SIZE 101
// int main()
// { ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//     bool a[ SIZE];
//     int b[SIZE]={0};
//     for(int i=0;i<SIZE;i++)
//     a[i]=true;
//     a[0]=false;
//     a[1]=false;
//     for(int i=2;i<SIZE;i++)
//     {
//         if(a[i]==true)
//         { b[i]=1;
//             for(int j=2*i;j<SIZE;j+=i)
//             {a[j]=false;
//             b[j]++;
//             cout<<b[j]<<" "<<j<<endl;
//             }

//          }
       
        
//     }
//    cout<<b[10]<<endl;
    
//     int p[SIZE][5];
//     for(int j=0;j<5;j++)
//     {p[0][j]=0;
//     p[1][j]=0;
//     }
  
//     for(int i=2;i<SIZE;i++)
//     { for(int j=0;j<5;j++)
//     {if(j==b[i]-1)
//         p[i][b[i]-1]=1+p[i-1][b[i]-1];
//         else
//         p[i][j]=p[i-1][j];
//     }
//     }
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int c,d,k;
//         cin>>c>>d>>k;
//         if(k>0&& k<=5)
//         cout<<p[d][k-1]-p[c-1][k-1]<<endl;
//     }
// }