//在給定的 N 個整數 A1，A2……AN 中選出兩個進行 xor運算，得到的結果最大是多少？
//第一行輸入一個整數 N。
// 第二行輸入 N 個整數 A1～AN。
#include<bits/stdc++.h>
#define IO cin.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN = 1e5+10;
ll n,ans,idx;
ll a[MAXN],son[31*MAXN][2];
void insert(int x)
{
    int p=0;
    for(ll i=30;i>=0;i--)
    {
        int u=x>>i&1; // x第i位的二進制數
        if(!son[p][u])  son[p][u]=++idx; // 如果沒路，就建新的路
        p=son[p][u]; // p指向idx所指的下標
    }
}
ll query(ll x) //返回第i元素前與二進制a[i]相比最多位數不同的數 
{
    int p=0;
    int res=0; 
    for(ll i=30;i>=0;i--)
    {
        ll u=x>>i&1;
        if(son[p][!u])  
        {
            p=son[p][!u];
            res=res*2+!u;
        }
        else
        {
            p=son[p][u];
            res=res*2+u;
        }
    }
    return res;
}
int main()
{
    IO;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        insert(a[i]);//建樹
        int t=query(a[i]);//返回第i元素前與二進制a[i]相比最多位數不同的數 
        ans=max(ans,a[i]^t);
    }
    cout<<ans<<'\n';
    return 0;
}