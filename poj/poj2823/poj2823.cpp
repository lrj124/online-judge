//2021.07.11 08:46 by lrj124.
#include <cstdio>
const int maxn = 1e6 + 10;
int n,k,hmax,tmax,hmin,tmin,ansmax[maxn],ansmin[maxn];
struct que { int num,val; } qmax[maxn],qmin[maxn];
int main() {
	scanf("%d%d",&n,&k);
	hmax = hmin = 1;
	tmax = tmin = 0;
	for (int i = 1,x;i <= n;i++) {
		scanf("%d",&x);
		for (;hmax <= tmax && qmax[tmax].val < x;tmax--);
		for (;hmin <= tmin && qmin[tmin].val > x;tmin--);
		qmax[++tmax].num = qmin[++tmin].num = i;
		qmax[tmax].val = qmin[tmin].val = x;
		for (;qmax[hmax].num <= i-k;hmax++);
		for (;qmin[hmin].num <= i-k;hmin++);
		if (i >= k) {
			ansmax[i] = qmax[hmax].val;
			ansmin[i] = qmin[hmin].val;
		}
	}
	for (int i = k;i <= n;i++) printf("%d%c",ansmin[i],i ^ n ? ' ' : '\n');
	for (int i = k;i <= n;i++) printf("%d%c",ansmax[i],i ^ n ? ' ' : '\n');
	return 0;
}
