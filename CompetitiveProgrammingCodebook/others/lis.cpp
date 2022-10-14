// 5
// 4 2 3 1 5
// =
// 3 (2,3,5)
#include <bits/stdc++.h>
#define maxn 1005
#define INF 99999999
using namespace std;
int n,a[maxn];
int dp[maxn];    //dp[i]:長度爲i+1的上升子序列中末尾元素的最小值（不存在的話就是INF）
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	fill(dp,dp+n,INF);   //初始化dp數組爲INF
	for(i=0;i<n;i++)     //找到更新dp[i]的位置並用a[i]更新之
    {
        *lower_bound(dp,dp+n,a[i])=a[i];//找到>=a[i]的第一個元素，並用a[i]替換； 
       /* for(j=0;j<n;j++)    //觀察dp數組的填充過程，dp裏面保存着最長不下降子序列
            printf("%d ",dp[j]);
        printf("\n");  */
    }
	printf("%d\n",lower_bound(dp,dp+n,INF)-dp);  //第一個INF出現的位置即爲LIS長度
	return 0;
}