#include<bits/stdc++.h>
using namespace std;
void print_arr(int arr[],int n,int j,int k)
{
    for(int i = j;i<=k;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void print_subarrays(int arr[],int n,int i,int j)
{
    if(i == n) 
        return;
    if(j == n)
        return;
    print_arr(arr,n,i,j);
    if(j == n-1)
        print_subarrays(arr,n,i+1,i+1);
    else
        print_subarrays(arr,n,i,j+1);
    
}
int main()
{
    int arr[5] = {1,2,3,4,5},n = 5;
    print_subarrays(arr,n,0,0);
}