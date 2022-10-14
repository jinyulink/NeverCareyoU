void init()
{
    for(ll i=1;i<=n;i++) p[i]=i;
}
ll find(ll x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(ll a,ll b)
{
    if(find(a)!=find(b))
    {
        p[find(a)]=find(b);
    }
}