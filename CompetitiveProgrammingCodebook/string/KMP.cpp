在字串s找是否存在qs字串 KMP(s,qs) return bool
-------------------------------------------------------
const ll MAXN = 1e5+10;
string s,qs;
ll failure[MAXN];
-------------------------------------------------------
bool KMP(string& t, string& p)
{
    if (p.size() > t.size()) return false;
    for (ll i=1, j=failure[0]=-1; i<p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }
    bool flag=false;
    for (ll i=0, j=-1; i<t.size(); ++i)
    {
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1)
        {
            flag=true;
            j = failure[j];
        }   
    }   
    return flag;
}