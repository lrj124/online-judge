#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1000000 + 10;
int n,ans,sum[maxn],h[maxn],v[maxn];
stack<int> s;
int main() {
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d%d",&h[i],&v[i]);
		for (;s.size() && h[s.top()] < h[i];sum[i] += v[s.top()],s.pop());
		if (s.size()) sum[s.top()] += v[i];
		s.push(i);
	}
	for (int i = 1;i <= n;i++) ans = max(ans,sum[i]);
	printf("%d",ans);
	return 0;
}
