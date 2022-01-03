struct ST {
    static const int N = 3e5 + 9;
    int t[4 * N];
    vector<int> a; //a is the base array. a must be filled magically
    static const int inf = INT_MAX;
    ST()
    {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e)
    {
        if(b==e) {
          t[n]=a[b];
          return;
        }
        int mid=(b+e)>>1, l=n<<1, r=l|1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n]=min(t[l], t[r]);
    }

    int query(int n, int b, int e, int i, int j)
    {
        if(b>j || e<i)
            return inf;
        if(b >= i && e <= j)
            return t[n];
        int mid=(b+e)>>1, l=n<<1, r=l|1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return min(L, R);
    }
} t;
