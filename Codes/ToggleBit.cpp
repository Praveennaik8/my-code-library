#include<bits/stdc++.h>
using namespace std;

int toggle_bit(int num,int pos)
{
    return num&(1<<pos)?num^(1<<pos):num|(1<<pos);
}
signed main()
{
    cout<<toggle_bit(5,1)<<endl;
}
