vector<int> kmpPi;
void prefixFunction(string &p)
{
    kmpPi.resize(p.size());
    int now;
    kmpPi[0]=now=-1;
    for(int i=1; i<p.size(); i++)
    {
        while(now!=-1 && p[now+1] != p[i])
            now=kmpPi[now];
        if(p[now+1]==p[i])
            kmpPi[i]=++now;
        else
            kmpPi[i]=now=-1;
    }
}

//text(t) and pattern(p) are 0 based
//kmp(t, p) returns the 0-based position of the first occurance of p
//if no occurance found returns -1
int kmp(string &t, string &p)
{
    int now=-1;
    int n=t.size(), m=p.size();
    for(int i=0; i<n; i++)
    {
        while(now!=-1 && p[now+1]!=t[i])
        {
            now=kmpPi[now];
        }
        if(p[now+1]==t[i])
            ++now;
        else
            now=-1;
        if(now==m-1)
            return i-m+1;
    }
    return -1;
}

int main()
{
    string t="I am the text containing pattern";
    string p="pattern";
    prefixFunction(t);
    cout<<kmp(t, p)<<endl;
    //outputs 25 which is the 0 based position of "pattern" in t

}
