/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.16.20:00
*Mail          :  1584634848@qq.com
*Problem       :  luogu4563
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 5000 + 10;
int n,h[maxn],f[maxn][maxn],ans;
inline double slope(int x,int y) { return 1.*(h[x]-h[y])/(x-y); }
inline bool check(int x,int y,int z) { return slope(z,x) < slope(z,y); }
int main() {
	freopen("luogu4563.in","r",stdin);
	freopen("luogu4563.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&h[i]);
	for (int r = 1,sum,pos = 0;r <= n;r++,pos = 0) {
		ans ^= (f[r][r] = sum = 1);
		for (int l = r-1;l;l--) {
			if (!pos || check(l,pos,r)) {
				sum += min(f[l+1][pos-1],f[l+1][pos]);
				pos = l;
			}
			ans ^= (f[l][r] = sum+min(f[l][pos-1],f[l][pos]));
		}
	}
	printf("%d",ans);
	return 0;
}
