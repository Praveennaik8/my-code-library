// // 11-85%
// #include<bits/stdc++.h>
// using namespace std;

// using namespace std; 

// class base 
// { 
// public: 
//     void fun_1() { cout << "base-1\n"; } 
//     virtual void fun_2() { cout << "base-2\n"; } 
//     virtual void fun_3() { cout << "base-3\n"; } 
//     virtual void fun_4() { cout << "base-4\n"; } 
// }; 

// class derived : public base 
// { 
// public: 
//     void fun_1() { cout << "derived-1\n"; }
//     void fun_2() { cout << "derived-2\n"; } 
//     void fun_4(int x) { cout << "derived-4\n"; }
//     void fun_4() { cout << "derived-4\n"; } 
// }; 
// int main() 
// { 
//     base *p; 
//     derived obj1; 
//     p = &obj1; 

//     // Early binding because fun1() is non-virtual 
//     // in base 
//     p->fun_1(); 

//     // Late binding (RTP) 
//     p->fun_2(); 

//     // Late binding (RTP) 
//     p->fun_3(); 

//     // Late binding (RTP) 
//     p->fun_4(); 

//     // Early binding but this function call is 
//     // illegal(produces error) becasue pointer 
//     // is of base type and function is of 
//     // derived class 

// } 

// #include<bits/stdc++.h>
// using namespace std;

// class Exception
// {
//     public:
//     int errNo;
//     string errMsg;

//     Exception(int x,string s)
//     {
//         errNo = x;
//         errMsg = s;
//     }
//     void displayError()
//     {
//         cout<<"\nError No : "<<errNo<<" "<<errMsg<<endl;
//     }
// };

// int main()
// {
//     int a = 2,b = 0;
//     try
//     {
//         if(b==0)
//             throw Exception(404," denominator cant be zero");
//         a = a/b;
        
//     }
//     // catch(const std::exception& e)
//     // {
//     //     std::cerr << e.what() << '\n';
//     // }
//     catch(Exception &e)
//     {
//         e.displayError();
//     }
    
// }

// #include<bits/stdc++.h>
// using namespace std;

// class searchClass
// {
//     public:
//     int size;
//     int arr[1000];
    
//     void getinput()
//     {
//         cout<<"\nenter size\n";
//         cin>>size;
//         for(int i =0 ;i<size;i++)
//             cin>>arr[i];
//     }
//     virtual int search(int key)
//     {
//         cout<<"hi";
//     }
//     virtual int search(int key,int s,int e)
//     {
//         cout<<"hi";
//     }
//     virtual void sortme()
//     {
//         cout<<"dd";
//     }
// };
// class sequential :public searchClass
// {
//     public:
//     int search(int key)
//     {
//         for(int i=0;i<size;i++)
//             if(key==arr[i])
//                 return i;
//         return -1;
//     }
// };
// class binSearch : public searchClass
// {
//     public:
//     void sortme()
//     {
//         sort(arr,arr+size);
//     }
//     int search(int key,int st,int end)
//     {
//         if(st==end)
//            return -1;
//         int mid = (st+end)/2;
//         if(arr[mid]==key)
//             return 1;
//         else if(arr[mid]<key)
//             search(key,mid,end);
//         else
//         {
//             search(key,st,mid);
//         }
        
//     }
// };
// int main()
// {
//     searchClass *c1;
    
//     int key;
    
//     binSearch bs;
    
//     c1= & bs;
//     c1->getinput();
//     cout<<"\n enter key to search \n";
//     cin>>key;
//     c1->sortme();
//     cout<<c1->search(key,0,c1->size-1)<<endl;
//     binary_search()
// }


// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define rep(i, n)    for(int i = 0; i < (n); ++i)
// #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
// #define repD(i, a, n)  for(int i = a; i >= (n); --i)
// #define trav(a, x) for(auto& a : x)
// #define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define fill(a)  memset(a, 0, sizeof (a))
// #define fst first
// #define snd second
// #define mp make_pair
// #define pb push_back
// #define test int t;cin>>t;while(t--)
// #define endl "\n"
// typedef long double ld;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;

// int main()
// {
//     fastio
//     test
//     {
//         ll n,k,temp;
//         cin>>n>>k;
//         map<ll,ll>mp;
//         for(int i=0;i<n;i++)
//         {
//             cin>>temp;
//             mp[temp]=1;
//         }
//         vi v1;
        
//         ll key = sqrt(k);
//         for(int i=1;i<=key;i++)
//         {
//             if(k%i==0)
//             {
//                 v1.push_back(i);
//                 v1.push_back(k/i);
//             }
//         }
//         sort(v1.begin(),v1.end(),greater<>());
//         // cout<<"dividers\n";
//         // for(auto x : v1)
//         // {
//         //     cout<<x<<"  ";
//         // }
//         for(auto x : v1)
//         {
//             if(mp[x]==1)
//             {
//                 cout<<x<<endl;
//                 goto here;
//             }
//         }
//         cout<<"-1"<<endl;
//         here:
//         {

//         }
//     }
// }



// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define rep(i, n)    for(int i = 0; i < (n); ++i)
// #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
// #define repD(i, a, n)  for(int i = a; i >= (n); --i)
// #define trav(a, x) for(auto& a : x)
// #define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define fill(a)  memset(a, 0, sizeof (a))
// #define fst first
// #define snd second
// #define mp make_pair
// #define pb push_back
// #define test int t;cin>>t;while(t--)
// #define endl "\n"
// typedef long double ld;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;

// int main()
// {
//     fastio
//     test
//     {
//         ll pc,pr,f_pc,f_pr;
//         cin>>pc>>pr;
        
//         pc%9==0?f_pc = pc/9:f_pc = pc/9+1;
//         pr%9==0?f_pr = pr/9:f_pr = pr/9+1;
        
//         if(f_pc<f_pr)
//         {
//             cout<<"0"<<" "<<f_pc<<endl;
//         }
//         else
//         {
//             cout<<"1"<<" "<<f_pr<<endl;
//         }
        
//     }
// }




// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define rep(i, n)    for(int i = 0; i < (n); ++i)
// #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
// #define repD(i, a, n)  for(int i = a; i >= (n); --i)
// #define trav(a, x) for(auto& a : x)
// #define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define fill(a)  memset(a, 0, sizeof (a))
// #define fst first
// #define snd second
// #define mp make_pair
// #define pb push_back
// #define test int t;cin>>t;while(t--)
// #define endl "\n"
// typedef long double ld;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;

// int main()
// {
//     // fastio
//     test
//     {
//         int arr[30]={0};
//         string s,p;
//         cin>>s>>p;
//         bool flag = false;
//         for(int i = 0;i<s.size();i++)
//             arr[s[i]-97]+=1;
//         for(int i = 0;i<p.size();i++)
//             arr[p[i]-97]-=1;
//         int key =p[0]-97;
//         if(p[0]>p[1])
//             flag =true;
        
//         for(int i = 0;i < 26;i++)
//         {
//             if(i==key&&flag)
//             {
//                 cout<<p;
//             }
//             for(int j = 0;j<arr[i];j++)
//                 printf("%c",i+97);
//             if(i==key&&!flag)
//             {
//                 cout<<p;
//             }
            
//         }
//         while(ref_str[i]<pattern[0])
//         {
//             i++;
//         }
//         cout<<endl;

//     }
// }


// aaakaeekmnnry
// abohotypsu
// aabadawyehhorst

// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define rep(i, n)    for(int i = 0; i < (n); ++i)
// #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
// #define repD(i, a, n)  for(int i = a; i >= (n); --i)
// #define trav(a, x) for(auto& a : x)
// #define all(x) x.begin(), x.end()
// #define sz(x) (int)(x).size()
// #define fill(a)  memset(a, 0, sizeof (a))
// #define fst first
// #define snd second
// #define mp make_pair
// #define pb push_back
// #define test int t;cin>>t;while(t--)
// #define endl "\n"
// typedef long double ld;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;


// ll currentcost;

// bool checkme(ll newcost,ll cost,bool match,ll k,ll i,ll oldi)
// {
//     if(newcost<= cost)
//     {
//         if( newcost< cost&&match)
//         {
//             return false;
//         }
//         if( newcost== cost||!match)
//             return true;
//         if( newcost<cost||!match)
//             return true;
//     }
//     if( newcost - cost <=k)
//     {
//         return true;
//     }
//     return false;
// }

// void solveme(int arr[], int n,int k)
// {
//     currentcost = k;
//     int i = 0;
//     map<int,int>mp1;
//     while(1)
//     {
//         cout<<"while1 "<<i<<endl;
//         if(mp1[arr[i]]||i==n)
//             break;
//         mp1[arr[i]]=1;
//         ++i;
//     }
//     if(i==n)
//         return;
//     while(i<n)
//     {
//         cout<<"while2 "<<i<<endl;
//         int newcost = k,newcostlag =k;
//         int cost = 0;
//         bool match = false;
//         map<int,int>mp2;
//         ll oldi = i;
//         while(checkme(newcost,cost,match,k,i,oldi))
//         {
//             newcostlag = newcost;
//             cout<<"while3 "<<i<<endl;
//             if(i==n)
//                 break;
//             if(mp1[arr[i]]&&mp2[arr[i]]==0)
//             {
//                 if(mp1[arr[i]]==1)
//                     cost+=2;
//                 else
//                 {
//                     cost+=1;
//                 }
                
//             }
            
//             match = false;
//             if(mp2[arr[i]]&&mp1[arr[i]]==0)
//             { 
//                 match = true;
//                 if(mp2[arr[i]]==1)
//                 {
//                     newcost +=2;
//                     cost +=2;
//                 }
//                 else 
//                 {
//                     newcost++;
//                     cost++;
//                 }
//             }
//             if(mp2[arr[i]]&&mp1[arr[i]])
//             {
//                 match = true;
//                 if(mp2[arr[i]]==1)
//                 {
//                     newcost +=2;
//                 }
//                 else 
//                 {
//                     newcost++; 
//                 }
//                 cost ++;
//             }  
//             mp2[arr[i]]+=1;
//             ++i;
//         }
//         mp2[arr[i]]--;

//         if(cost>newcost)
//         {
//             cout<<"new tabe"<<endl;
//             currentcost +=newcostlag;
//             mp1 = mp2;
//         }
//         else
//         {
//             currentcost +=cost;
//             cout<<"map update"<<endl;
//             for(int m = 0;m<101;m++)
//             {
               
//                 mp1[m]+=mp2[m];
//             }
//         }
//     }
// }



// int main()
// {

//     test
//     {
//         int n,k;
//         cin>>n>>k;
//         int arr[n+10];
//         for(int i=0;i<n;i++)
//         {
//             cin>>arr[i];
//         }
//         // bool flag=true;
//         // int extra = 0,table = 0;
//         // while(flag)
//         // {
//         //     flag = false;
//         //     for(auto it=mp.begin();it!=mp.end();it++)
//         //     {
//         //         if(it->second>0)
//         //         {
//         //             flag = true;
//         //             if(it->second%k==0&&k!=1)
//         //                 extra +=k;
//         //             else if(it->second!=1)
//         //                 extra += it->second%k;
                    
//         //             mp[it->first] = it->second - k;
//         //         }
//         //     }
//         //     table+=1;
//         // }
//         // int ans = table*k+extra;
//         // cout<<ans<<endl;
//         // int i=0;
//         // while(i<n)
//         // {

//         //     map<int,int>mpx;
//         //     for(;i<n;i++)
//         //     {
//         //         if(mpx[arr[i]]==k)
//         //            break;
//         //         mpx[arr[i]] += 1;
//         //     }
//         //     for(auto it=mpx.begin();it!=mpx.end();it++)
//         //     {
//         //         if(it->second>1)
//         //             extra+=it->second;
//         //     }
//         //     table++;
            
//         // }
//         if(k==1)
//         {
//             int i =0;
//             currentcost =0;
            
//             while(i<n)
//             {
//                 map<int,int>mp1;
//                 while(!mp1[arr[i]])
//                 {
//                     mp1[arr[i]]=1;
//                     ++i;
//                 }
//                 currentcost++;
//             }
//         }
//         else
//             solveme(arr,n,k);

//         cout<<"ans = "<<currentcost<<endl;

//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// typedef long double ld;
// typedef long long ll;



// ll currentcost;

// bool checkme(ll newcost,ll cost,bool match,ll k,ll i,ll oldi)
// {
//     if(newcost<= cost)
//     {
//         if( newcost< cost&&match)
//         {
//             return false;
//         }
//         if( newcost== cost||!match)
//             return true;
//         if( newcost<cost||!match)
//             return true;
//     }
//     if( newcost -  cost <=k)
//     {
//         return true;
//     }
//     return false;
// }

// int solveme(int arr[], int n,int k)
// {
//     currentcost = k;
//     int i = 0;
//     int tableindex[1000][3],tablecount=0;
//     vector<map<int,int>>v1;
    
//     map<int,int>mp1;
//     tableindex[tablecount][0]=0;
//     while(1)
//     {
  
//         if(mp1[arr[i]]||i==n)
//             break;
//         mp1[arr[i]]=1;
//         ++i;
//     }
//     tableindex[tablecount][1]=i-1;
    
//     v1.push_back(mp1);
//     if(i==n)
//         return currentcost;
//     while(i<n)
//     {
 
//         int newcost = k,newcostlag =k;
//         int cost = 0;
//         bool match = false;
//         map<int,int>mp2;
//         ll oldi = i;
//         while(checkme(newcost,cost,match,k,i,oldi))
//         {
//             if(i==n)
//                 break;
//             newcostlag =newcost;
            
//             if(mp1[arr[i]]&&mp2[arr[i]]==0)
//             {
//                 if(mp1[arr[i]]==1)
//                     cost+=2;
//                 else
//                 {
//                     cost+=1;
//                 }
                
//             }
            
//             match = false;
//             if(mp2[arr[i]]&&mp1[arr[i]]==0)
//             { 
//                 match = true;
//                 if(mp2[arr[i]]==1)
//                 {
//                     newcost +=2;
//                     cost +=2;
//                 }
//                 else 
//                 {
//                     newcost++;
//                     cost++;
//                 }
//             }
//             if(mp2[arr[i]]&&mp1[arr[i]])
//             {
//                 match = true;
//                 if(mp2[arr[i]]==1)
//                 {
//                     newcost +=2;
//                 }
//                 else 
//                 {
//                     newcost++; 
//                 }
//                 cost ++;
//             }  
//             mp2[arr[i]]+=1;
//             ++i;
//         }
// 	    mp2[arr[i]]--;
//         if(cost>newcost)
//         {
//             currentcost +=newcostlag ;
//             v1.push_back(mp2);
//             mp1 = mp2;
//             tableindex[++tablecount][1]=i-1;
//             tableindex[++tablecount][0]=oldi;
//         }
//         else
//         {
//             currentcost +=cost;
//             for(int m = 0;m<101;m++)
//             {
//                 mp1[m]+=mp2[m];
//             }
//             v1.pop_back();
//             v1.push_back(mp1);
//             tableindex[tablecount][1]=i-1;
//         }
//     }
//     //minimize
//     ll latest = currentcost;
//     for(i=1;i<=tablecount;i++)
//     {
//         // for(int j = tableindex[i][1];j<=tableindex[i][0]; j--)
//         // {
//         //     if(v[i+1][arr[j]]==1&&v[i][arr[j]]==1)
//         //     {
//         //         break;
//         //     }
//         //     if(v[i+1][arr[j]]!=1&&v[i][arr[j]]==1)
//         //     {
                
//         //     }
//         //     if(v[i+1][arr[j]]!=1&&v[i][arr[j]]==1)
//         //     {

//         //     }

//         // }
//         map<int,int>mp1 = v1[i-1];
//         map<int,int>mp2 = v1[i];
//         ll less=0;
//         for(int j = tableindex[i][0];j<=tableindex[i][1];j++)
//         {
            
//             if(v1[i-1][arr[j]]==0)
//             {
//                 if(v1[i][arr[j]]==2)
//                     less+=2;
//                 else if(v1[i][arr[j]]>2)
//                 {
//                     less+=1;
//                 }
//                 mp1[arr[i]]++;
//                 mp2[arr[i]]--;
//             }
//             if(mp1[arr[i]]==1&&mp2[arr[i]]>1)
//             {
//                 break;
//             }
//         }
//         if(less > 0)
//         {
//             v1[i-1] = mp1;
//             v1[i] = mp2;
//             latest-=less;
//         }
//     }
//     return min(currentcost,latest);
// }



// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,k;
//         cin>>n>>k;
//         int arr[n+10];
//         int rev[n+10];
//         for(int i=0;i<n;i++)
//         {
//             cin>>arr[i];
//             rev[n-i-1] = arr[i];
//         }
//         int ans;
//         if(k==1)
//         {
//             int i =0;
//             currentcost =0;
            
//             while(i<n)
//             {
//                 map<int,int>mp1;
//                 while(!mp1[arr[i]])
//                 {
//                     mp1[arr[i]]=1;
//                     ++i;
//                 }
//                 currentcost++;
//             }1hj
//             ans = currentcost;
//         }
//         else
//         {
//             ans = min(solveme(arr,n,k),solveme(rev,n,k));
//         }

//         cout<<ans<<endl;

//     }
// }


#include <bits/stdc++.h> 
using namespace std; 
vector<int>freq;
void mostFrequent(vector<int>arr, int n) 
{ 
    // Insert all elements in hash. 
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
    {
        hash[arr[i]]++; 
        cout<<arr[i]<< " ";
    }
    // find the max frequency 
    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if ((max_count < i.second)) { 
            res = i.first;
            max_count = i.second; 
        } 
        else if((max_count==i.second&&res>i.first))
        {
            res = i.first;
        }
        
    } 
    cout<<"  =   "<<res<<endl;
    freq.push_back(res);

} 
  
// Recursive function to print all 
// possible subsequences for given array 
void printSubsequences(vector<int> arr, int index,  
                       vector<int> subarr) 
{ 
    // Print the subsequence when reach 
    // the leaf of recursion tree 
    if (index == arr.size()) 
    { 
        int l = subarr.size(); 
  
        // Condition to avoid printing 
        // empty subsequence 
        if (l != 0) 
            mostFrequent(subarr, l); 
    } 
    else
    { 
        // Subsequence without including 
        // the element at current index 
        printSubsequences(arr, index + 1, subarr); 
  
        subarr.push_back(arr[index]); 
  
        // Subsequence including the element 
        // at current index 
        printSubsequences(arr, index + 1, subarr); 
    } 
    return; 
} 
  
// Driver Code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> arr; 
        int temp;
        for(int i = 0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }

        vector<int> b; 
        freq = {0};
        map<int,int>mpx;
        printSubsequences(arr, 0, b); 
        for(auto it = freq.begin();it!=freq.end();it++)
        {
            mpx[*it]++;
        }
        for(auto it = mpx.begin();it != mpx.end();it++)
        {
            cout<<it->first<< " --->  "<<it->second<<endl;
        }

        
    }
    return 0; 
} 