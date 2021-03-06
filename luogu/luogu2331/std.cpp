#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110;
const int M=11;
int n,m,K,s1[N],s2[N],dp[N][M],f[N][N][M];
int main(){
    freopen("luogu2331.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
    if(m==1){
        for(int i=1,x;i<=n;i++) scanf("%d",&x),s1[i]=s1[i-1]+x;
        for(int k=1;k<=K;k++){
            for(int i=1;i<=n;i++){
                dp[i][k]=dp[i-1][k];
                for(int j=0;j<i;j++) dp[i][k]=max(dp[i][k],dp[j][k-1]+s1[i]-s1[j]);
            }
        }
        printf("%d\n",dp[n][K]);
    }
    else{
        for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),s1[i]=s1[i-1]+x,s2[i]=s2[i-1]+y;
        for(int k=1;k<=K;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    f[i][j][k]=max(f[i-1][j][k],f[i][j-1][k]);
                    for(int l=0;l<i;l++) f[i][j][k]=max(f[i][j][k],f[l][j][k-1]+s1[i]-s1[l]);
                    for(int l=0;l<j;l++) f[i][j][k]=max(f[i][j][k],f[i][l][k-1]+s2[j]-s2[l]);
                    if(i==j)  for(int l=0;l<i;l++) f[i][j][k]=max(f[i][j][k],f[l][l][k-1]+s1[i]-s1[l]+s2[j]-s2[l]);
                }
            }
        }
        printf("%d",f[n][n][K]);
    }
    return 0;
}
