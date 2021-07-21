//I am hunting for the golden stag.
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 998244353;

int main() {
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) {
		scanf("%d",&t[i]);
		if (t[i] == 1) scanf("%d%d",&p[i],&v[i]),flag = false;
		if (t[i] == 2) scanf("%d",&v[i]),flag = false;
		if (t[i] == 3) {
			int cnt,x; scanf("%d",&cnt);
			for (;cnt--;edge[i].push_back(x)) scanf("%d",&x);
		}
	}
	
	return 0;
}
