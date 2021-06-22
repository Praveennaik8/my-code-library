#include<bits/stdc++.h>
using namespace std;

int unset_bit(int num,int pos)
{
    return num&(1<<pos)?num^(1<<pos):num;
}
signed main()
{
    cout<<unset_bit(5,1)<<endl;
}
