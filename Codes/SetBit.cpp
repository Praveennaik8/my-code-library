#include<bits/stdc++.h>
using namespace std;

int set_bit(int num,int pos)
{
    return num|(1<<pos);
}
signed main()
{
    cout<<set_bit(5,2)<<endl;
    
}