/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.07.21:12
*Mail          :  1584634848@qq.com
*Problem       :  at2165
************************************************/
#include <cstdio>
const int maxn = 200000 + 10;
int n,l,r(maxn),x[maxn];
inline bool check(int mid) {
	for (int i = 1;i < n;i++) {
		if ((x[n-i] > mid && x[n-i+1] > mid) || (x[n-i] <= mid && x[n-i+1] <= mid)) return x[n-i] <= mid;
		if ((x[n+i] > mid && x[n+i-1] > mid) || (x[n+i] <= mid && x[n+i-1] <= mid)) return x[n+i] <= mid;
	}
	return x[1] <= mid;
}
int main() {
	freopen("at2165.in","r",stdin);
	freopen("at2165.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i < (n<<1);i++) scanf("%d",&x[i]);
	for (int mid;l < r;mid = l+r>>1,check(mid) ? r = mid : l = mid+1);
	printf("%d",l);
	return 0;
}
