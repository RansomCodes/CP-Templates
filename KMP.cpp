void generateKMParray(string &s,vector<int> &lps)
{
    int m=s.size();
    for(int i=1;i<m;i++)
    {
        int j=lps[i-1];
        while(j!=0 and s[j]!=s[i]) j=lps[j-1];
        if(s[i]==s[j]) j++;
        lps[i]=j;
    }
}
    
void KMP(string &text,string &pat,vector<int> &pos)
{
    int n=text.size(),m=pat.size();
    vector<int> lps(m);
    generateKMParray(pat,lps);
    int idx1=0,idx2=0;
    while(n-idx1>=m-idx2)
    {
        if(text[idx1]==pat[idx2])
        {
            idx1++;
            idx2++;
        }
        if(idx2==m)
        {
            pos.pb(idx1-idx2);
            idx2=lps[idx2-1];
        }
        else if(idx1<n and text[idx1]!=pat[idx2])
        {
            if(idx2!=0) idx2=lps[idx2-1];
            else idx1++;
        }
    }
}