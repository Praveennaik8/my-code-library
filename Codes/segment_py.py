lazy = []
def build(arr,seg,low,high,pos):
    if low == high:
        seg[pos] = arr[low]
        return

    mid = int((low+high)/2)
    build(arr,seg,low,mid,int(2* pos+1))
    build(arr,seg,mid+1,high,int(2*pos+2))
    seg[pos] = min(seg[2*pos+1],seg[2*pos+2])

def min_query(seg,low,high,q_low,q_high,pos):
    if lazy[pos]!=0:
        
        add = int(lazy[pos])
        lazy[pos] = 0
        seg[pos] = seg[pos] +10*add
        if low != high:
            seg[2*pos+1]+=add
            seg[2*pos+2]+=add

    if low >=q_low and high <= q_high:
        return seg[pos]
    if low > q_high or high <q_low :
        return 99999999
    
    mid = int((low+high)/2)
    return min(min_query(seg,low,mid,q_low,q_high,2*pos+1),
                min_query(seg,mid+1,high,q_low,q_high,2*pos+2))

def update(seg,low,high,q_low,q_high,pos):
    if lazy[pos]!=0:
        add = int(lazy[pos])
        lazy[pos] = 0
        seg[pos] = seg[pos] + 10 *add
        if low != high:
            lazy[2*pos+1]+=add
            lazy[2*pos+2]+=add
    
    if low >=q_low and high <= q_high:
        seg[pos] = seg[pos] + 10
        if(low!=high):
            lazy[2*pos+1]+=1
            lazy[2*pos+2]+=1
        return
    if low > q_high or high <q_low :
        return 

    mid = int((low+high)/2)
    update(seg,low,mid,q_low,q_high,2*pos+1)
    update(seg,mid+1,high,q_low,q_high,2*pos+2)
    seg[pos] = min(seg[2*pos+1],seg[2*pos+2])

if __name__ == "__main__":
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(arr.__len__(),arr[0])

    seg = []
    lazy.clear()
    for i in range(4*n):
        lazy.append(0)
        seg.append(99999999)
    
    build(arr,seg,0,n-1,0)
    print(seg)
    q = int(input())
    for i in range(q):
        l,h = [int(x) for x in input().split()] 
        print(min_query(seg,0,n-1,l,h,0))
        


    

