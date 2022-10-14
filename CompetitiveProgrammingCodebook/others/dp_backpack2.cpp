// 有N种物品和一个容量为V的背包。第i种物品最多有n[i]件，每件费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大
// dp[i][v] = max{dp[i - 1][v - k * c[i]] + w[i] | 0 <=k <= n[i]}
#include <stdio.h>
#include <stdlib.h>
typedef struct rice {
    int price, weight, num;
} rice;
void dynamic(rice *rices, int m, int n)
{
    int i, j, cur, k, **dp;
    // 动态申请二维数组
    dp = (int **)malloc(sizeof(int *) * (m + 1));
    for (i = 0; i <= m; i ++)
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));
    // 初始化
    for (i = 0; i <= m; i ++)
        for (j = 0; j <= n; j ++)
            dp[i][j] = 0;
    // 动态规划
    for (i = 1; i <= m; i ++) {
        for (j = 1; j <= n; j ++) {
            for (k = 0; k <= rices[i].num; k ++) {
                if (j - k * rices[i].price >= 0) {
                    cur = dp[i - 1][j - k * rices[i].price] + k * rices[i].weight;
                    dp[i][j] = dp[i][j] > cur ? dp[i][j] : cur;
                } else {
                    break;
                }
            }
        }
    }
    printf("%d\n", dp[m][n]);
    for (i = 0; i <= m; i ++)
        free(dp[i]);
}
int main(void)
{
    int i, c, n, m;
    rice rices[2010];
    scanf("%d", &c);
    while (c --) {
        scanf("%d %d", &n, &m);
        // 接收数据
        for (i = 1; i <= m; i ++) {
            scanf("%d %d %d", &rices[i].price, &rices[i].weight, &rices[i].num);
        }
        // 多重背包问题
        dynamic(rices, m, n);
    }
    return 0;
}