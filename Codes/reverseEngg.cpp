#include<bits/stdc++.h>
using namespace std;

void print(int x =0 ,int y =0 ,int z = 0,int k = 0,string s= "")
{
    cout<<"Reached here "<<x<<"  "<<y<<"  "<<z<<"  "<<k<<s<<"\n";
}
void prints(string s= "",int x =0)
{
    cout<<"Reached 2 here "<<x<<" "<<s<<"\n";
}
void print(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i+1]<<" ";
    }
    cout<<endl;
}
int get(int y)
{
    int x = 0;
    for(int i =1 ;i<=y;i++)
        x+=i;
    return x;

}
signed main()
{
    int t;cin>>t;
    int iter = 0;
    while(iter<t)
    {
        ++iter;
        int x,y;
        cin>>x>>y;
        if(y<x-1||get(x)<y)
        {
            cout<<"Case #"<<iter<<": "<<"IMPOSSIBLE"<<"\n";
            continue;
        }
        int arr[x+10];
        for(int i = 0;i<x+10;i++)
         arr[i] = 0;
        
        int keep = x-2;
        int last = x-1;
        int curr = 1,ind = 0;
        bool flag = false, side = true;
        for(int i = 1;i<x;i++)
        {
            int avail = 0;
            //do
            side = true;
            cout<<y-keep<<" y-keep "<<last+2-i<<" "<<curr<<endl;
            if(y-keep<last+2-i)
            {
                flag = true;
                ind = y-keep;
                arr[i+y-keep] = curr;
                y -= (y-keep);
            }
            else
            {
                ind = last+2-i;
                arr[last+2-i] = curr;
                y-=(last+2-i);
            }
            

            ++curr;
            
            --keep;
            print(arr,x);
            if(flag)
                break;
            side = false;
             cout<<y-keep<<" y-keep "<<last+1-i<<" "<<curr<<endl;
            
            if(y-keep<last-i+1)
            {
                flag = true;
                // cout<<last-(y-keep)+1<<endl;
                arr[last-(y-keep)+1] = curr;
                y -= (y-keep);
            }
            else
            {
                ind = i;
                arr[i] = curr;
                y-=(last+1-i);
            }
            print(arr,x);
            
            ++curr;
            if(flag)
                break;
            last--;
            
            --keep;
            
            
        }
        cout<<curr<<endl;
        if(side)
        {
            for(int i = ind;i<=x;i++)
            {
                if(arr[i]==0)
                    arr[i] = curr++;
            }
            for(int i = ind;i>0;i--)
            {
                if(arr[i]==0)
                    arr[i] = curr++;
            }
        }
        else
        {
            for(int i = ind;i>0;i--)
            {
                if(arr[i]==0)
                    arr[i] = curr++;
            }
            for(int i = ind;i<=x;i++)
            {
                if(arr[i]==0)
                    arr[i] = curr++;
            }
            
        }
        

        
        cout<<"Case #"<<iter<<": ";
        print(arr,x);
        
    }
}