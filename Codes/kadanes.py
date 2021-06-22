
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
