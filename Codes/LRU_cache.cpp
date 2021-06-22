#include<bits/stdc++.h>
using namespace std;

class LRU
{
    list<int>pageQ;
    unordered_map<int ,list<int>::iterator >pageHash;
    int capacity;
    public:
    LRU(int n)
    {
        capacity = n;
    }
    void refer(int n)
    {
        if(pageHash.find(n) == pageHash.end())
        {
            if(pageQ.size() == this->capacity)
            {
                int last = pageQ.back();
                pageQ.pop_back();
                pageHash.erase(last);
            }
        }
        else
            pageQ.erase(pageHash[n]);
        pageQ.push_front(n);
        pageHash[n] = pageQ.begin();
    }
    void display()
    {
        for(auto x:pageQ)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
signed main()
{
    LRU ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
}