#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int in[10010];
vector<int> v[10010];
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)&&n&&m)
    {
        memset(in,0,sizeof in);//清空入度
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >>x>>y;//比如x贏了y  或者y是x的兒子 ；那麼就讓x指向y；
            v[x].push_back(y);
            in[y]++;//y的入度加1
        }
        priority_queue<int,vector<int>,greater<int> >q;//優先隊列，設置從小到大排序，小的在隊列下麵
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);//把入度為0的節點壓入隊列
        }
        while(!q.empty())
        {
            int xx=q.top();
            q.pop();
            n--;//每次去掉一個節點
            for(int i=0;i<v[xx].size();i++)
            {
                int yy=v[xx][i];
                in[yy]--;
                if(!in[yy])
                    q.push(yy);//如果去掉上一個節點之後下一個節點的入度變為0，則壓入隊列中
            }
        }
        if(n) cout <<"NO"<<endl;//如果有環的話節點數不會為0
        else cout <<"YES"<<endl;
    }
    return 0;
}
