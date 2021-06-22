#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    string str1,str2;
    cin>>str1;
    str2 = str1;
    reverse(str1.begin(),str1.end());
    int lcs[str1.size()+1][str2.size()+1];

    for(int i = 0;i <= str1.size(); i++)
        lcs[i][0] = 0;
    for(int i = 0;i <= str2.size(); i++)
        lcs[0][i] = 0;

    for(int i = 1;i <= str1.size(); i++)
    {
        for(int j = 1;j <= str2.size(); j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout<<str1.size()-lcs[str1.size()][str2.size()]<<endl;
}