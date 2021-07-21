/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.03.21:14
*Mail          :  1584634848@qq.com
*Problem       :  luogu2698
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,d,head_max,tail_max,head_min,tail_min;
struct water_drop {
	int x,y;
	inline bool operator < (water_drop cmp) const {
		return x < cmp.x;
	}
} w[maxn];
struct que { int val,num; } q_max[maxn],q_min[maxn];
inline bool check(int mid) {
	head_max = head_min = 1;
	tail_max = tail_min = 0;
	for (int i = 1;i <= n;i++) {
		for (;head_max <= tail_max && w[i].y >= q_max[tail_max].val;tail_max--);
		for (;head_min <= tail_min && w[i].y <= q_min[tail_min].val;tail_min--);
		q_max[++tail_max] = { w[i].y,w[i].x };
		q_min[++tail_min] = { w[i].y,w[i].x };
		for (;q_max[head_max].num+mid < w[i].x;head_max++);
		for (;q_min[head_min].num+mid < w[i].x;head_min++);
		if (q_max[head_max].val-q_min[head_min].val >= d) return true;
	}
	return false;
}
int main() {
	freopen("luogu2698.in","r",stdin);
	freopen("luogu2698.out","w",stdout);
	scanf("%d%d",&n,&d);
	for (int i = 1;i <= n;i++) scanf("%d%d",&w[i].x,&w[i].y);
	sort(w+1,w+n+1);
	int l = 1,r = 10000000;
	for (int mid;l < r;mid = l+r>>1,check(mid) ? r = mid : l = mid+1);
	printf("%d",l == 10000000 ? -1 : l);
	return 0;
}
