/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.04.21:16
*Mail          :  1584634848@qq.com
*Problem       :  luogu1429
************************************************/
#include <algorithm>
#include <cstdio>
#include <cmath>
#define min(a,b) (a < b ? a : b)
const int maxn = 200000 + 10;
struct point {
	double x,y;
	inline bool operator < (point cmp) const {
		return x < cmp.x;
	}
} p[maxn];
inline double calc(point x,point y) { return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y)); }
double ans = 999999999;
int n;
int main() {
	freopen("luogu1429.in","r",stdin);
	freopen("luogu1429.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	std :: sort(p+1,p+n+1);
	for (int i = 1;i <= n;i++)
		for (int j = i+1;j <= min(i+5,n);j++) ans = min(ans,calc(p[i],p[j]));
	printf("%.4f",ans);
	return 0;
}
