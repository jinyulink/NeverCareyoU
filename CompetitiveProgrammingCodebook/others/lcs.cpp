// 第1行輸出上述兩個最長公共子序列的長度。
// 第2行輸出所有可能出現的最長公共子序列個數，答案可能很大，只要將答案對100,000,000求餘即可。
// ABCBDAB.
// BACBBD.
// =
// 4
// 7
#include<bits/stdc++.h>
#include<string>
using namespace std;
const int mod=1e8;
char a[5010],b[5010];
int f[5010][5010],g[5010][5010];
int len1,len2;
int main(){
    scanf("%s%s",a+1,b+1);
    len1=strlen(a+1);
    len2=strlen(b+1);
    len1--,len2--;
    for(int i=0;i<=len1;++i)
        for(int j=0;j<=len2;++j)
            g[i][j]=1;
    for (int i = 1 ;i <=len1; i++)
        for( int j = 1; j <=len2; j++) {
            if (a[i]==b[j]){
                f[i][j]=f[i-1][j-1] + 1;         
                g[i][j]=g[i-1][j-1];
                if(f[i][j]==f[i-1][j]) g[i][j]=(g[i][j]+g[i-1][j])%mod;
                if(f[i][j]==f[i][j-1]) g[i][j]=(g[i][j]+g[i][j-1])%mod;
            } 
            else{
                f[i][j] = max(f[i - 1][j], f[i][j - 1]); 
                g[i][j]=0;
                if(f[i][j]==f[i-1][j]) g[i][j]=(g[i][j]+g[i-1][j])%mod;
                if(f[i][j]==f[i][j-1]) g[i][j]=(g[i][j]+g[i][j-1])%mod;
                if(f[i][j]==f[i-1][j-1]) g[i][j]=(g[i][j]-g[i-1][j-1]+mod)%mod;
            }   
        }
    cout<<f[len1][len2]<<"\n"<<(g[len1][len2]+mod)%mod<<"\n";
    return 0;
}