/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.02.18:21
*Mail          :  1584634848@qq.com
*Problem       :  2b
************************************************/
#include <cstdio>
int m,n,a[6],b[6],c[6],ans;
inline int abs(int x) { return x < 0 ? -x : x; }
int main() {
	freopen("2b.in","r",stdin);
	freopen("2b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for (int x = 1;x <= m;x++)
		for (int y = x;y <= m;y++) {
			int abs_c_del_z = abs(a[1]-x)^abs(b[1]-y)^9;
		}
	printf("%d",ans);
	return 0;
}
