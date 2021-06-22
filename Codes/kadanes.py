
def kadanes(arr,n):
    crnt_sum = 0;
    max_sum = -10000000009

    for i in range(n):
        crnt_sum += arr[i]
        crnt_sum = max(crnt_sum,arr[i])
        max_sum = max(max_sum,crnt_sum)
    
    return max_sum

n = int(input())
arr = [int(x) for x in input().split()]

print(kadanes(arr,n))

# #include<bits/stdc++.h> 
# #include <chrono>
# using namespace std; 
# using namespace std::chrono; 
# #define int long long
# #define MARK 8765433
# int MOD_val = 1.1529215e+18 ;
# int n = 240;
# int arr[245];
# int dp[245];
# // Function to calculate sum of absolute difference 
# // of all pairs in array 
# // arr[]  --> array of elements 
# pair<int,int> find_sum(int sum)
# {
   
#     /* Initialize curr_sum as value of  
#     first element and starting point as 0 */
#     int curr_sum = arr[0], start = 0, i; 
  
#     /* Add elements one by one to curr_sum and  
#     if the curr_sum exceeds the sum, 
#     then remove starting element */
#     for (i = 1; i <= n; i++) { 
#         // If curr_sum exceeds the sum, 
#         // then remove the starting elements 
#         while (curr_sum > sum && start < i - 1) { 
#             curr_sum = curr_sum - arr[start]; 
#             start++; 
#         } 
  
#         // If curr_sum becomes equal to sum, 
#         // then return true 
#         if (curr_sum == sum) { 
#             return {start,i-1};
#         } 
  
#         // Add this element to curr_sum 
#         if (i < n) 
#             curr_sum = curr_sum + arr[i]; 
#     } 
  
    
# }
#  Driver program to run the case 
# main() 
# { 
#     dp[0 ] = 1;
#     for(int i = 1;i<n;i++)
#     {
#         dp[i] = (dp[i-1]*2)%MOD_val;
#     }
#     for(int i = 0;i<n;i++)
#         cin>>arr[i];
#     int q;
#     cin>>q;
#     while(q--)
#     {
#         cin>>sum;
#         pair<int,int>index = find_sum(sum);
#         int ans = 0;
#         for(int i = index.first;i<index.second;i++)
#         {
#             ans =+ dp[i]
#             ans%=MOD_val;
#         }
        
#     }
    
# } 