//給一個無向圖，點的編號最多為500，邊數最多為1024，首先輸入一個m代表邊的數量，然後讓輸出字典序最小的歐拉路徑(字典序最小—經過點的編號字典序最小)。題目保證至少有一個歐拉路徑。
int n = 500, m,ans[1100], cnt,d[N],g[N][N];
void dfs(int u)
{   
    //因為最後的歐拉路徑的序列是ans數組逆序，
    //節點u只有在遍歷完所有邊之後最後才會加到ans數組裡面，所以逆序過來就是最小的字典序
    for (int i = 1; i <= n; i ++ )
        if (g[u][i])//刪邊優化
            g[u][i] --, g[i][u] -- ; dfs(i);
    ans[ ++ cnt] = u;
}
int main()
{
    cin >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] ++, g[b][a] ++ ;
        d[a] ++, d[b] ++ ;
    }
    int start = 1;
    while (!d[start]) ++start; // 較小編號作為起點
    //數據保證有解一定存在歐拉迴路,那麼讓第一條度數為奇數的點作為起點
    for (int i = 1; i <= 500; ++i) {
        if (d[i] % 2) { // 奇數點作為起點
            start = i;
            break;
        }
    }
    dfs(start);
    for (int i = cnt; i; i -- ) printf("%d\n", ans[i]);
    return 0;
}