/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.14.10:38
*Mail          :  1584634848@qq.com
*Problem       :  hdu1847
************************************************/
#include <cstring>
#include <cstdio>
const int maxn = 1000 + 10;
int f[maxn],sg[maxn];
bool vis[maxn];
inline void get_sg() {
	for (int i = 1;i < maxn;i++) {
		memset(vis,false,sizeof vis);
		for (int j = 1;j <= f[0] && i-f[j] >= 0;j++) vis[sg[i-f[j]]] = true;
		for (int j = 0;;j++) if (!vis[j]) { sg[i] = j; break;}
	}
}
int main() {
	freopen("hdu1847.in","r",stdin);
	freopen("hdu1847.out","w",stdout);
	for (int i = 1;i < maxn;i <<= 1) f[++f[0]] = i;
	get_sg();
	for (int n;scanf("%d",&n) ^ EOF;puts(sg[n] ? "Kiki" : "Cici"));
	return 0;
}
