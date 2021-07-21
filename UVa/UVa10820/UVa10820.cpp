/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.12.14:28
*Mail          :  1584634848@qq.com
*Problem       :  UVa10820
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 10;
int n,prime[maxn],phi[maxn];
bool is_not_prime[maxn];
inline void init() {
	phi[1] = 1;
	for (int i = 2;i <= maxn-10;i++) {
		if (!is_not_prime[i]) {
			prime[++prime[0]] = i;
			phi[i] = i-1;
		}
		for (int j = 1;j <= prime[0] && i*prime[j] <= maxn-10;j++) {
			is_not_prime[i*prime[j]] = true;
			if (!(i%prime[j])) {
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i]*(prime[j]-1);
		}
	}
	for (int i = 1;i <= maxn-10;i++) phi[i] += phi[i-1];
}
int main() {
	freopen("UVa10820.in","r",stdin);
	freopen("UVa10820.out","w",stdout);
	for (init();scanf("%d",&n),n;) printf("%d\n",(phi[n]<<1)-1);
	return 0;
}
