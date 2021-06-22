# cook your dish here
t = int(input())

for _ in range(t):
    n = int(input())
    ind = [0 for _ in range(n+1)]
    for i in range(n-1):
        x,y = [int(z) for z in input().split()]
        ind[x]+=n
    cnt = 0
    for key in ind:
        if ind[key] == 0:
            cnt+=1
    print(cnt-1)