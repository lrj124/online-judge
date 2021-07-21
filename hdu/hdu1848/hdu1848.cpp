/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.14.11:03
*Mail          :  1584634848@qq.com
*Problem       :  hdu1848
************************************************/
#include <cstring>
#include <cstdio>
const int maxn = 1000 + 10;
int f[maxn] = { 0,1 },sg[maxn];
bool vis[maxn];
inline void get_sg() {
	for (int i = 1;i < maxn;i++) {
		memset(vis,false,sizeof vis);
		for (int j = 1;i-f[j] >= 0;j++) vis[sg[i-f[j]]] = true;
		for (int j = 0;;j++) if (!vis[j]) { sg[i] = j; break; }
	}
}
int main() {
	freopen("hdu1848.in","r",stdin);
	freopen("hdu1848.out","w",stdout);
	for (int i = 2;;i++) {
		f[i] = f[i-1]+f[i-2];
		if (f[i] > maxn) break;
	}
	get_sg();
	for (int n,m,p;scanf("%d%d%d",&n,&m,&p),n && m && p;puts(sg[n]^sg[m]^sg[p] ? "Fibo" : "Nacci"));
	return 0;
}
