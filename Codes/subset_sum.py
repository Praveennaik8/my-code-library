

import random
# A Dynamic Programming solution for subset  
# sum problem Returns true if there is a subset of  
# set[] with sun equal to given sum  
  
# Returns true if there is a subset of set[]  
# with sun equal to given sum 
def isSubsetSum(subset, n, sum): 
      
    # The value of subset[i][j] will be  
    # true if there is a 
    # subset of set[0..j-1] with sum equal to i 
    
      
    # uncomment this code to print table  
    # for i in range(n + 1): 
    # for j in range(sum + 1): 
    # print (subset[i][j], end =" ") 
    # print() 
    wt = sum
    arr = set()
    for i in range(n, 0, -1): 
        # print(i,wt,"not")
        if wt == 0:
            # print("REturning")
            return arr
        # either the result comes from the 
        # top (K[i-1][w]) or from (val[i-1] 
        # + K[i-1] [w-wt[i-1]]) as in Knapsack 
        # table. If it comes from the latter 
        # one/ it means the item is included. 
        if subset[i - 1][wt]: 
            continue
        if i == wt or (subset[i-1][wt] == False and subset[i][wt]): 
            # This item is included. 
            # print(i) 
            # arr.append(int(i)) 
            arr.add(int(i))
            # arr.append(int(i)) 
            # Since this weight is included 
            # its value is deducted 
            wt = wt - (i)
        # if wt == 0:
        #     print("REturning")
        #     for i in arr:
        #         print(i,end = " ")
        #     print()
        #     return arr
    print(arr.__len__())
    return arr
    
      
def main():
    n = int(input())
    arr = []
    arr = [int(x) for x in input().split()]
    sum = 4353
    subset =([[False for i in range(sum + 1)]  
            for i in range(n + 1)]) 
      
    # If sum is 0, then answer is true  
    for i in range(n + 1): 
        subset[i][0] = True
          
    # If sum is not 0 and set is empty,  
    # then answer is false  
    for i in range(1, sum + 1): 
         subset[0][i]= False
              
    # Fill the subset table in botton up manner 
    for i in range(1, n + 1): 
        for j in range(1, sum + 1): 
            if j<arr[i-1]: 
                subset[i][j] = subset[i-1][j] 
            if j>= arr[i-1]: 
                subset[i][j] = (subset[i-1][j] or 
                                subset[i - 1][j-arr[i-1]]) 
    # cook your dish here
    # for i in range(1, n+1):
    #     for j in range(1,sum+1):
    #         print(subset[i][j],end=" ")
    #     print()
    powerof2 = [int(1) for x in range(n+1)]
    
    for i in range(1,n):
        powerof2[i] = powerof2[i-1]*2
    
    # for i in range(245):
    #     print(powerof2[i])
    
    # for i in range(240):
    #     arr.append(int(i+1))
    n = arr.__len__()   
    q = int(input())
    # print(q)
    # for i in range(240):
    #     print(arr[i],end = " ")
    # print()
    qlist = []
    qlist = [int(x) for x in input().split()]
    
    for x in qlist:
        # x = qlis
        
        inddex = isSubsetSum(subset,n,x)
        # inddex = inddex.sort()
        # print("Returned list",inddex)
        # for i in inddex:
        #     print(i,end=" ")
        # print()
        ans = 0
        for i in inddex:
            ans+=powerof2[i]
        # print(ans,powerof2[60])

            
        print(int(ans%powerof2[60]),end=" ")
        print(int((ans/powerof2[60])%powerof2[60]),end=" ")
        print(int((ans/powerof2[120])%powerof2[60]),end=" ")
        print(int((ans/powerof2[180])%powerof2[60]))
        # print()
        
        
main()