/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.03.20:45
*Mail          :  1584634848@qq.com
*Problem       :  luogu3800
************************************************/
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 4000 + 10;
int n,m,s,t,v[maxn][maxn],f[maxn][maxn],head,tail,ans;
struct que { int val,num; } q[maxn];
signed main() {
	freopen("luogu3800.in","r",stdin);
	freopen("luogu3800.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	for (int i = 1,x,y;i <= s;i++) {
		scanf("%lld%lld",&x,&y);
		scanf("%lld",&v[x][y]);
	}
	for (int i = 1;i <= n;i++) {
		head = 1; tail = 0;
		for (int j = 1;j <= min(m,t+1);j++) {
			for (;head <= tail && f[i-1][j] > q[tail].val;tail--);
			q[++tail] = { f[i-1][j],j };
		}
		f[i][1] = v[i][1]+q[head].val;
		for (int j = 2;j <= m;j++) {
			if (j+t <= m) {
				for (;head <= tail && f[i-1][j+t] > q[tail].val;tail--);
				q[++tail] = { f[i-1][j+t],j+t };
			}
			for (;q[head].num+t < j;head++);
			f[i][j] = v[i][j]+q[head].val;
		}
	}
	for (int i = 1;i <= m;i++) ans = max(ans,f[n][i]);
	printf("%lld",ans);
	return 0;
}
