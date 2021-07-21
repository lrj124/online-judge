#include <cstdio>
#include <stack>
using namespace std;
stack<long long> s;
long long n,x,ans;
int main() {
	for (scanf("%lld",&n);n--;) {
		scanf("%lld",&x);
		for (;s.size() && s.top() < x;s.pop());
		ans += s.size(); s.push(x);
	}
	printf("%lld",ans);
	return 0;
}
