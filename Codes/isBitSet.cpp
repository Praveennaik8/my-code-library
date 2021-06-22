#include<bits/stdc++.h>
using namespace std;

bool isSet(int num,int pos)
{
    return num&(1<<pos);
}
signed main()
{
    cout<<isSet(4,2)<<endl;
}