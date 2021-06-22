inp = input()
flag = True
for i in range(2,len(inp)):
    if (ord(inp[i])-ord('A')+1)+1 != ((ord(inp[i-1])-ord('A')+1)+(ord(inp[i-2])-ord('A')+1))%26:
        # print((ord(inp[i])-ord('A')+1),(ord(inp[i-1])-ord('A')+1)+(ord(inp[i-2])-ord('A')+1)%26)
        flag = False
        break

if flag:
    print("YES")
else:
    print("NO")