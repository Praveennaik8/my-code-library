#include<bits/stdc++.h>
using namespace std;


signed main()
{
    int arr1[] = {1,3,4,5,7,9,14,16};
    int arr2[] = {0,2,3,6,8,10,11,90,99};
    int n1 = sizeof(arr1)/sizeof(int),n2 = sizeof(arr2)/sizeof(int);
    int i = 0,j = 0, p = -1;
    int arr3[n1+n2+10];
    while(i<n1&&j<n2)
    {
        if(arr1[i]<arr2[j])
            arr3[++p] = arr1[i++];
        else
            arr3[++p] = arr2[j++];
    }
    if(i==n1)
    {
        while(j<n2)
            arr3[++p] = arr2[j++];
    }
    else
    {
        while(i<n1)
            arr3[++p] = arr1[i++];
    }
    for(int i = 0;i<n1+n2;i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}