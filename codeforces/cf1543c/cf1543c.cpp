//2021.07.19 10:02 by lrj124.
#include <algorithm>
#include <cstdio>
using namespace std;
const double eps = 1e-9;
double ans;
inline void dfs(int now,double c,double m,double p,double v,double pro) {
	if (c < eps && m < eps && p < eps) return ans += pro*now,void();
	dfs(now+1,0,0,0,v,pro*p);
	if (c > eps) dfs(now+1,max(c-v,0.),m > eps ? m+min(c,v)/2 : 0,p+min(c,v)/(m > eps ? 2 : 1),v,pro*c);
	if (m > eps) dfs(now+1,c > eps ? c+min(m,v)/2 : 0,max(m-v,0.),p+min(m,v)/(c > eps ? 2 : 1),v,pro*m);
}
int main() {
	for (int t = scanf("%d",&t)*0+t;t--;ans = 0) {
		double c,m,p,v;
		scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
		dfs(0,c,m,p,v,1);
		printf("%.12lf\n",ans);
	}
	return 0;
}
