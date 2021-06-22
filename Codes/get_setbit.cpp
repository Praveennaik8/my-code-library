#include<bits/stdc++.h>
using namespace std;

int get_setbit(int num)
{
    int cnt = 0;
    while(num)
    {
        if(num&1)
            ++cnt;
        num>>=1;
    }
    return cnt;
}
signed main()
{
    cout<<get_setbit(10)<<endl;
}