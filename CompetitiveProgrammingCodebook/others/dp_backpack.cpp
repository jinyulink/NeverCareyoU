//有 N 件物品和一個容量為 V 的背包。第 i 件物品的費用是 c[i]，價
// 值是 w[i]。求解將哪些物品裝入背包可使價值總和最大。
#include<iostream>
using namespace std;
const int N = 1010;
int v[N], w[N], dp[N];//dp[N][N]
int main(){
    int n, m;    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i++){
        // for(int j = 0; j <= m; j++){
        //     if(j < v[i])
        //         dp[i][j] = dp[i-1][j];
        //     else
        //         dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
        // }
        for(int j = m; j >=v[i]; j--){
            dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<endl;;
    return 0;
}