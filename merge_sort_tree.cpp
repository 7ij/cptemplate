//n must be 1-based
typedef long long int T;
struct ST {
    static const int N = 2e5 + 9;
    vector<T> t[4 * N];
    vector<T> a; //a is the base array. a must be filled magically
    ST()
    {
        t.clear();
    }
    void build(int n, int b, int e)
    {
        if(b==e)
        {
          t[n].emplace_back(a[b]);
          return;
        }
        int mid=(b+e)>>1, l=n<<1, r=l|1;
        build(l, b, mid);
        build(r, mid + 1, e);
        merge(n, l, r);

    }
    void merge(int n, int l, int r )
    {
       for(int i=0, j=0; i<t[l].size()||j<t[r].size();)
       {
            if(i<t[l].size()&&j<t[r].size())
            {
                if(t[l][i]<t[r][j])
                {
                    t[n].emplace_back(t[l][i]);
                    i++;
                }
                else
                {
                    t[n].emplace_back(t[r][j]);
                    j++;
                }
            }
            else if(i<t[l].size())
            {
                t[n].emplace_back(t[l][i]);
                i++;
            }
            else
            {
                t[n].emplace_back(t[r][j]);
                j++;
            }
       }
    }
    int query(int n, int b, int e, int i, int j, T val) //number of elements greater than val
    {
        if(b>j || e<i)
            return 0;
        if(b >= i && e <= j)
        {
            int x=t[n].end()-upper_bound(t[n].begin(), t[n].end(), val);
            return x;
        }
        int mid=(b+e)>>1, l=n<<1, r=l|1;
        int L = query(l, b, mid, i, j, val);
        int R = query(r, mid + 1, e, i, j, val);
        return L+R;
    }
} mst;
