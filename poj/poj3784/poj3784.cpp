#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int T,n,cas,ans;
vector<int> v;
int main() {
	freopen("poj3784.in","r",stdin);
	freopen("poj3784.out","w",stdout);
	for (scanf("%d",&T);T--;v.clear()) {
		scanf("%d%d",&cas,&n);
		printf("%d %d\n",cas,(n+1)/2);
		for (int i = 1,x;i <= n;i++) {
			scanf("%d",&x);
			v.insert(lower_bound(v.begin(),v.end(),x),x);
			if (i & 1) printf("%d%c",v[(i+1)/2-1],(i+1)/2%10 ? ' ' : '\n');
		}
		if ((n+1)/2%10) puts("");
	}
	return 0;
}
