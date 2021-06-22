#include<bits/stdc++.h>
using namespace std;
int onesCompliment(int n)
{
    int size = floor(log2(n))+1;
    return ((1<<size)-1)^n;
}
string conv_LtoU(string s)
{
    for(int i = 0;i < s.size(); i++)
        s[i] = onesCompliment(int(s.at(i)) ^ 32);
    return s;
}
string conv_UtoL(string s)
{
    for(int i = 0;i < s.size(); i++)
        s[i] = int(s.at(i))| 32;
    return s;
}
signed main()
{
    string s = "ABC";
    cout<<conv_LtoU("abc")<<endl;
    cout<<conv_UtoL("ABC");
}