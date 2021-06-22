#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n+10];
	    for(int i = 0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    bool flag = false;
        int i;
	    for(i = 0;i<n;i++)
	    {
	           if((i+1)%arr[i])
	            {
	                break;
	            }
	    }
	    if(i == n-1)
	        cout<<"NO\n";
	    else
	       cout<<"YES\n";
	}
	return 0;
}
