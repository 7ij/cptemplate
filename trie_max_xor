//Alhamdulillah for everything you gave

#include <bits/stdc++.h>
typedef long long Long;
using namespace std;
//Bittrie
template <typename T> //T is the value of each node in trie
struct Trie
{
    int root, nnode;
    static const int ME=2; //MaxEdge = 2
    static const int MAXBIT=31; //31 for int, 63 for Long
    static const int MAX_NODE=500000; //Be  ware of instantiating in every solve()
    T node[MAX_NODE][ME];
    Trie()
    {
        root=0;
        nnode=0;
        for(int i=0; i<ME; i++)
            node[root][i]=-1;
    }
    void insert(T val)
    {
        int now=root;
        for(T i=MAXBIT; i>=0; i--)
        {
            int ithBit=(val&(1ll<<i))?1:0;
            if(node[now][ithBit]==-1)
            {
                nnode++;
                node[now][ithBit]=nnode;
                for(int j=0; j<ME; j++)
                    node[nnode][j]=-1;
            }
            now=node[now][ithBit];
        }
    }

    T query(T qval)
    {
        int now=root;
        T ret=0;
        for(T i=MAXBIT; i>=0; i--)
        {
            if((node[now][0]==-1)&&(node[now][1]==-1))
                return ret;
        int bit=(qval&(1ll<<i))?1:0;
        if(bit==0)
        {
            if(node[now][1]!=-1)
            {
                now=node[now][1];
                ret=(ret<<1)|1;
            }
            else
            {
                now=node[now][0];
                ret=ret<<1;
            }
            }
            else
            {
                if(node[now][0]!=-1)
                {
                    now=node[now][0];
                    ret=(ret<<1)|1;

                }
                else
                {
                    now=node[now][1];
                    ret=(ret<<1)|0;
                }
            }
        }
        return ret;
    }

};

void solve()
{

    Long n, x; cin>>n>>x;
    Trie<Long> trie;
    trie.insert(0);
    Long _max=0, ans=0, pre=0;
    for(int i=0; i<n; i++)
    {

        Long elem;
        cin>>elem;
        pre^=elem;
        trie.insert(pre);
        Long cur=trie.query(x^pre);
        if(cur>_max)
        {
            _max=cur;
            ans=cur^x;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    #endif
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
 }


 //https://www.spoj.com/problems/XORX/
