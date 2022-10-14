#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")//常數優化
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector 
#define pb push_back
#define pll pair<ll,ll>
#define F first
#define S second
#define INF 0x3f3f3f3f //接近9
#define INFF 0x3f3f3f3f3f3f3f3f //接近19
#define PI acos(-1) //等同圓周率
//unsigned ll 0~18,446,744,073,709,551,615
//大數交給python
//解題數>penalty(時間+錯的次數*20)
//每題都要看過
using namespace std;
int main()
{
    IO;
    memset(arr,0,sizeof arr);//放0 -1 0x3f(接近10^9)
    max({a,b,c});//找三個值的最大值
    sort(v.begin(),v.end(),[](int lhs,int rhs){
        return lhs<rhs;
    })//lambda
    for(auto i:vec)  cout<<i<<'\n';
    for(auto &i:vec)    i++;//修改值要加&
    if(x&1) cout<<"odd";
    else    cout<<"even";
    x<<=1;//x*=2
    cerr<<"debug"<<__LINE__<<" line";//在程式碼第幾行
    //只會在cmd輸出 不會再std output 不會wa
    assert(x<=5);//如果條件不成立 會RE
    //可以用來猜測資
    return 0;
}