// 給出有 n 個元素的數組 a[] , m 個元素的數組 b[] ,求出它們的最長上升公共子序列的長度.
// F[i][j]表示以a串的前i個整數與b串的前j個整數且以b[j]爲結尾構成的LCIS的長度。
// O(n^2)
// 4
// 2 2 1 3
// 2 1 2 3
// = 
// 2
#include <iostream>
using namespace std;
const int N = 3010;
int n;
int a[N], b[N];
int f[N][N];
int main()
{
    //input
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    //dp
    for (int i = 1; i <= n; ++ i)
    {
        int maxv = 1;
        for (int j = 1; j <= n; ++ j)
        {
            f[i][j] = f[i - 1][j];
            if (b[j] == a[i]) f[i][j] = max(f[i][j], maxv);
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }
    //find result
    int res = 0;
    for (int i = 0; i <= n; ++ i) res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
}